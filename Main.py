import sys
import datetime
import os
from pathlib import Path
import traceback
import pandas as pd
import numpy as np
import calendar
from statistics import mean
from scipy.interpolate import interp1d as interp
import sqlite3
#%%######################################################################################################
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use("Qt5Agg")
#%%######################################################################################################
from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5 import QtTest
from PyQt5.QtCore import Qt, QThread, pyqtSignal
# from PyQt5.QtCore.QElapsedTimer import timer
from PyQt5.QtWidgets import QFileDialog, QMessageBox, QAction, QTableWidgetItem
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
from matplotlib.figure import Figure
#%%######################################################################################################
from PyQt5.uic import loadUiType
sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)),'GUIfiles'))
Ui_MainWindow, QMainWindow = loadUiType('GUIfiles\gui.ui')
from loadingsavingtemplate import LoadParamTemplate, SaveParamTemplate

sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)),'Keithley Code'))
from myKeithleyFunctions import connectToKeithley, prepareVoltage, measureVoltage, prepareCurrent, measureCurrent, openShutter, closeShutter, takeIV, shutdownKeithley,setFrontTerminal,setRearTerminal

sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)),'Otherfunctions'))
from database_Tables import CreateAllTables
import database_GeneralReading_pyqt as DBreadPack

#%%######################################################################################################
shutteropen=0
RefDiodeChecked=0
Sunintensity=0
STOPMEAS=0
STOPMEASMPP=0
AllDATA={}
lastmeasDATA={}
AlltrackingDATA={}
lastmeastrackingDATA={}
aftermpp=0

def connectPixel(box1, box2, pixelName):
    print('Pixel '+pixelName+' connected')
boxCurrent = 'test'
boxVoltage = 'test'
keithleyAddress='Test'
#%%######################################################################################################
"""
need to check all units in all function measuring data from keithley

sequence builder: so user can define himself the sequence of dark, light, mpp... same as done for Jay


weird empty lines in table


NOTES FROM ELI:

- when doing mppt, openshutter is called at every point
"""
#%%######################################################################################################
class Main(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        global AllDATA, shutteropen
        QtWidgets.QMainWindow.__init__(self, parent)
        
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        LoadParamTemplate(self)
        self.keithleyObject=connectToKeithley(keithleyAddress)
        
        self.connecttoDB()
 
        finish = QAction("Quit", self)
        finish.triggered.connect(lambda: self.closeEvent(self.keithleyObject))
        
        #shutter initialization, so that software value corresponds to real value
        self.shutter('OpenShutter',self.keithleyObject)
        self.shutter('CloseShutter',self.keithleyObject)
        
        self.fig1 = Figure()
        self.JVgraph = self.fig1.add_subplot(111)
        self.JVgraph.set_xlabel('Voltage (mV)')
        self.JVgraph.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.JVgraph.axhline(y=0, color='k')
        self.JVgraph.axvline(x=0, color='k')
        self.addmpl(self.fig1,self.ui.gridLayout_MPLwidgetJV, self.ui.MPLwidgetJV)
        
        
        self.fig2 = Figure()
        self.MPPTgraph_JV = self.fig2.add_subplot(221)
        self.MPPTgraph_JV.set_xlabel('Voltage (mV)')
        self.MPPTgraph_JV.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.MPPTgraph_TV = self.fig2.add_subplot(222)
        self.MPPTgraph_TV.set_xlabel('Time (s)')
        self.MPPTgraph_TV.set_ylabel('Voltage (mV)')
        self.MPPTgraph_TJ = self.fig2.add_subplot(223)
        self.MPPTgraph_TJ.set_xlabel('Time (s)')
        self.MPPTgraph_TJ.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.MPPTgraph_TP = self.fig2.add_subplot(224)
        self.MPPTgraph_TP.set_xlabel('Time (s)')
        self.MPPTgraph_TP.set_ylabel('Power (W/m'+'\xb2'+')')
        self.addmpl(self.fig2, self.ui.gridLayout_MPLwidgetMPPT,self.ui.MPLwidgetMPPT)
        
        self.fig3 = Figure()
        self.DIVgraphlin = self.fig3.add_subplot(121)
        self.DIVgraphlin.set_xlabel('Voltage (mV)')
        self.DIVgraphlin.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.DIVgraphlogY = self.fig3.add_subplot(122)
        self.DIVgraphlogY.set_yscale('log')
        self.DIVgraphlogY.set_xlabel('Voltage (mV)')
        self.DIVgraphlogY.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.addmpl(self.fig3,self.ui.gridLayout_MPLwidgetDIV,self.ui.MPLwidgetDIV)

        self.fig4 = Figure()
        self.DBgraph = self.fig4.add_subplot(111)
        self.DBgraph.set_xlabel('Date/Time')
        self.DBgraph.set_ylabel('X (-)')
        # self.DBgraph.axhline(y=0, color='k')
        # self.DBgraph.axvline(x=0, color='k')
        self.addmpl(self.fig4,self.ui.gridLayout_mplDB, self.ui.widget_DB)

        
        for item0 in [self.DIVgraphlin,self.DIVgraphlogY,self.DBgraph,self.JVgraph,self.MPPTgraph_JV,self.MPPTgraph_TV,self.MPPTgraph_TJ,self.MPPTgraph_TP]:
            for item in ([item0.title, item0.xaxis.label, item0.yaxis.label] +
                         item0.get_xticklabels() + item0.get_yticklabels()):
                item.set_fontsize(12)
                
        self.ui.actionLoad_settings.triggered.connect(lambda: LoadParamTemplate(self))
        self.ui.actionSave_settings.triggered.connect(lambda: SaveParamTemplate(self))
        
        self.ui.pushButton_OpenCloseShutter.clicked.connect(lambda: self.opencloseshutter(self.keithleyObject))
    
        self.ui.pushButton_StartMeas.clicked.connect(self.InitMeas)
        
        self.ui.pushButton_cleargraph.clicked.connect(lambda: self.ClearGraph(0))
        
        self.ui.pushButton_StopMeas.clicked.connect(self.stopmeas)
        self.ui.pushButton_StopMppt.clicked.connect(self.stopmeasmpp)
        
        self.ui.pushButton_MeasureIntensityDiode.clicked.connect(lambda: self.MeasureRefDiode(self.keithleyObject))

        self.ui.pushButton_LoadAllDATAinTable.clicked.connect(lambda: self.UpdateTable(AllDATA))
        
        self.ui.pushButton_PlotfromTable.clicked.connect(self.PlotfromTable)
        
        self.ui.pushButton_exportgraphandfile.clicked.connect(self.Exporttxtplot)
        
        self.ui.comboBox_MeasType.currentTextChanged.connect(self.on_combobox_changed)
        
        self.ui.tabWidget.currentChanged.connect(self.onclickDBtab)
        
        self.ui.comboBox_DBTime.currentTextChanged.connect(self.on_combobox_DBTime_changed)
        self.ui.comboBox_DBTimeYaxis.currentTextChanged.connect(self.SearchAndPlot)
        self.ui.comboBox_DBTime_restrictions.currentTextChanged.connect(self.on_combobox_DBTimeRestrictions_changed)
        self.ui.pushButton_DBTime_Add.clicked.connect(self.Addrestriction)
        self.ui.pushButton_DBTime_remove.clicked.connect(self.Removerestriction)
        
        
        
    def closeEvent(self, event):
        """ what happens when close the program"""
        
        close = QMessageBox.question(self,
                                     "QUIT",
                                     "Are you sure?",
                                      QMessageBox.Yes | QMessageBox.No)
        if close == QMessageBox.Yes:
            shutdownKeithley(self.keithleyObject)
            self.theCursor.close()
            self.db_conn.close()
            event.accept()
        else:
            event.ignore()


        
    def on_combobox_changed(self, value):
        
        if value == 'FixedVoltage':
            self.ui.label_20.setText('Fixed voltage (mV):')
            self.ui.groupBox_MPPTParam.setTitle('FV parameters')
        elif value == 'FixedCurrent':
            self.ui.label_20.setText('Fixed current (mA):')
            self.ui.groupBox_MPPTParam.setTitle('FC parameters')
        else:
            self.ui.label_20.setText('Start voltage (mV):')
            self.ui.groupBox_MPPTParam.setTitle('MPPT parameters')
                
#%%######################################################################################################

    def addmpl(self, fig, whereLayout, whereWidget):
        self.canvas = FigureCanvas(fig)
        whereLayout.addWidget(self.canvas)
        self.canvas.draw()
        self.toolbar = NavigationToolbar(self.canvas, 
                whereWidget, coordinates=True)
        whereLayout.addWidget(self.toolbar)
        
    def opencloseshutter(self,keithleyObject):
        global shutteropen
        
        if not shutteropen: #if closed, then we open
            openShutter(keithleyObject)
            shutteropen=1
            self.ui.pushButton_OpenCloseShutter.setText('Close shutter')
        else: #if open, then we close
            closeShutter(keithleyObject)
            shutteropen=0
            self.ui.pushButton_OpenCloseShutter.setText('Open shutter')
            
    def shutter(self,action,keithleyObject):
        global shutteropen
        
        if action == 'OpenShutter':
            openShutter(keithleyObject)
            shutteropen=1
            self.ui.pushButton_OpenCloseShutter.setText('Close shutter')
        else:
            closeShutter(keithleyObject)
            shutteropen=0
            self.ui.pushButton_OpenCloseShutter.setText('Open shutter')  
        
#%%######################################################################################################
    def Popup_CheckDiode(self):
        choice = QMessageBox.question(self, 'Do you want to measure the reference diode?',
                                            "Click Ok to measure it\nClick Ignore to assume 1 sun",
                                            QMessageBox.Ok | QMessageBox.Ignore)
        if choice == QMessageBox.Ok:
            # print("measuring ref diode")#should add here the function that will measure the ref diode and populate the fields
            # self.MeasureRefDiode()
            return 'measuring the ref diode'
        else:
            # print("assume 1 sun")
            self.ui.radioButton_Assume1sun.setChecked(True)
            return 'User ignores request for ref meas'
    
    def MeasureRefDiode(self, keithleyObject):
        global RefDiodeChecked, Sunintensity
        # print('measuring ref diode')
        polar='pin'
        if self.ui.radioButton_nip.isChecked():
            polar='nip'
        print(polar)
        self.shutter('OpenShutter',keithleyObject)
        setFrontTerminal(keithleyObject)
        prepareCurrent(keithleyObject, NPLC = 1, currentlimit=1e-2, polarity=polar)
        dataCurrent = measureCurrent(keithleyObject,voltage=0.0,n=20, polarity = polar)
        self.ui.doubleSpinBox_MeasuredDiodeCurrent.setValue(abs(mean(dataCurrent[:,1])))
        Sunintensity=abs(mean(dataCurrent[:,1]))/self.ui.doubleSpinBox_DiodeNominalCurrent.value()
        self.ui.doubleSpinBox_NumbSun.setValue(Sunintensity)
        self.shutter('CloseShutter',keithleyObject)
        setRearTerminal(keithleyObject)
        RefDiodeChecked=1
    
    def stopmeas(self):
        global STOPMEAS
        STOPMEAS=1
    def stopmeasmpp(self):
        global STOPMEASMPP
        STOPMEASMPP=1
       
    def PlotfromTable(self):
        global AllDATA
        
        rows=list(set(index.row() for index in self.ui.tableWidget.selectedIndexes()))
        sampleselected=[self.ui.tableWidget.item(row,0).text() for row in rows]
        # print(rows)
        self.ClearGraph('LIV')
        for sample in sampleselected:
            direction=AllDATA[sample]['ScanDirection']
            if direction == 'fwd':#forward scan
                self.JVgraph.plot(AllDATA[sample]['Voltage'],AllDATA[sample]['CurrentDensity'], linestyle="dashed",label=AllDATA[sample]['SampleNamePix']+'_'+direction)
            elif direction == 'rev':#reverse scan
                self.JVgraph.plot(AllDATA[sample]['Voltage'],AllDATA[sample]['CurrentDensity'], linestyle="solid",label=AllDATA[sample]['SampleNamePix']+'_'+direction)
        self.JVgraph.legend()
        self.fig1.canvas.draw_idle()
        self.fig1.canvas.flush_events()
       
    def Exporttxtplot(self):
        global AllDATA
        
        rows=list(set(index.row() for index in self.ui.tableWidget.selectedIndexes()))
        sampleselected=[self.ui.tableWidget.item(row,0).text() for row in rows]
        
        for sample in sampleselected:
            self.Savedata(sample,AllDATA)
    
    def InitMeas(self):
        
        if self.ui.checkBox_threaded.isChecked():
            print('threaded')
            self.StartMeasThreaded(self.keithleyObject)
        else:
            print('not threaded')
            self.StartMeas(self.keithleyObject)
            
    def StartMeasThreaded(self, keithleyObject):
        global aftermpp,boxCurrent, boxVoltage, RefDiodeChecked, STOPMEAS, shutteropen,lastmeastrackingDATA, lastmeasDATA, Sunintensity
        # print('startmeas')
        self.ui.pushButton_StartMeas.setEnabled(False)
        STOPMEAS=0
        aftermpp=0
        lastmeasDATA={}
        lastmeastrackingDATA={}
        self.ClearGraph(1)
        self.ClearTable()
        
        ########
        Assume1suncheck=0
        if not self.ui.radioButton_Assume1sun.isChecked() and not RefDiodeChecked:
            Assume1suncheck=self.Popup_CheckDiode()
        go=0
        
        if Assume1suncheck =='User ignores request for ref meas' or self.ui.radioButton_Assume1sun.isChecked():
            Sunintensity=1
            go=1
        if go or RefDiodeChecked:
            if RefDiodeChecked and not self.ui.radioButton_Assume1sun.isChecked():
                Sunintensity=self.ui.doubleSpinBox_NumbSun.value()
        
            ########
            
            for i in range(self.ui.spinBox_RepNumb.value()):
                # print('Sequence #'+str(i+1))
                
                self.sequence = str(self.ui.comboBox_MeasType.currentText())
                
                pixels=[]
                pixcolorslist=[]
                Allpixels=['A','B','C','D','E','F']
                allpixcolors=['black','red','blue','green','cyan','magenta']
                if self.ui.radioButton_pixAll.isChecked():
                    pixels=Allpixels
                    pixcolorslist=allpixcolors
                else:
                    checkboxlist=[self.ui.checkBox_pixA.isChecked(),self.ui.checkBox_pixB.isChecked(),
                                  self.ui.checkBox_pixC.isChecked(),self.ui.checkBox_pixD.isChecked(),
                                  self.ui.checkBox_pixE.isChecked(),self.ui.checkBox_pixF.isChecked()]
                    for item in range(6):
                        if checkboxlist[item]:
                            pixels.append(Allpixels[item])
                            pixcolorslist.append(allpixcolors[item])
                            
                if self.ui.comboBox_JVscandirection.currentText()=="Reverse + Forward":
                    scandirections=[0,1]
                elif self.ui.comboBox_JVscandirection.currentText()=="Forward + Reverse":
                    scandirections=[1,0]
                elif self.ui.comboBox_JVscandirection.currentText()=="Reverse":
                    scandirections=[0]
                elif self.ui.comboBox_JVscandirection.currentText()=="Forward":
                    scandirections=[1]
                    
                self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                if self.ui.spinBox_RepNumb.value()>1:
                    QtTest.QTest.qWait(self.ui.spinBox_RepDelay.value())
                    
    def launchSequence(self, keithleyObject, pixels, pixcolorslist, scandirections, Rep):
        global aftermpp,boxCurrent, boxVoltage, RefDiodeChecked, STOPMEAS, shutteropen,lastmeastrackingDATA, lastmeasDATA, Sunintensity
        
        if self.sequence=='':
            QMessageBox.information(self,'Finished', 'The sequence is finished.')         
            self.ui.pushButton_StartMeas.setEnabled(True)
        elif self.sequence.split('-')[0]=='LIV':
            print('liv')
            self.sequence=self.sequence[4:]
            self.shutter('OpenShutter',keithleyObject)
            QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
            self.PlotIVThreaded(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
            
        elif self.sequence.split('-')[0]=='DIV':
            print('div')
            self.sequence=self.sequence[4:]
            self.shutter('CloseShutter',keithleyObject)
            self.PlotIVThreaded(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
            
        elif self.sequence.split('-')[0]=='MPPT':
            print('MPPT')
            self.sequence=self.sequence[5:]
            if self.ui.checkBox_MPPTlighton.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
                
            self.Tracking(keithleyObject,'MPPT', pixels, pixcolorslist, scandirections, Rep)
            
            if self.ui.checkBox_MPPTlightonafter.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            aftermpp=1
            self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
        elif self.sequence.split('-')[0]=='FixedVoltage':
            print('FixedVoltage')
            self.sequence=self.sequence[13:]
            if self.ui.checkBox_MPPTlighton.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            
            self.Tracking(keithleyObject,'FixedVoltage', pixels, pixcolorslist, scandirections, Rep)
            
            if self.ui.checkBox_MPPTlightonafter.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
        elif self.sequence.split('-')[0]=='FixedCurrent':
            print('FixedCurrent')
            self.sequence=self.sequence[13:]
            if self.ui.checkBox_MPPTlighton.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
                
            self.Tracking(keithleyObject,'FixedCurrent', pixels, pixcolorslist, scandirections, Rep)
            
            if self.ui.checkBox_MPPTlightonafter.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
        elif self.sequence.split('-')[0]=='bestpixMPPT':
            print('bestpixMPPT')
            self.sequence=self.sequence[12:]
            if self.ui.checkBox_MPPTlighton.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            self.Tracking(keithleyObject,'MPPTbest', pixels, pixcolorslist, scandirections, Rep)
            
            if self.ui.checkBox_MPPTlightonafter.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
            self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
        
    def StartMeas(self, keithleyObject):#if not threaded
        global aftermpp,boxCurrent, boxVoltage, RefDiodeChecked, STOPMEAS, shutteropen,lastmeastrackingDATA, lastmeasDATA, Sunintensity
        # print('startmeas')
        self.ui.pushButton_StartMeas.setEnabled(False)
        STOPMEAS=0
        lastmeasDATA={}
        lastmeastrackingDATA={}
        self.ClearGraph(1)
        self.ClearTable()
        
        ########
        Assume1suncheck=0
        if not self.ui.radioButton_Assume1sun.isChecked() and not RefDiodeChecked:
            Assume1suncheck=self.Popup_CheckDiode()
        go=0
        
        if Assume1suncheck =='User ignores request for ref meas' or self.ui.radioButton_Assume1sun.isChecked():
            Sunintensity=1
            go=1
        if go or RefDiodeChecked:
            if RefDiodeChecked and not self.ui.radioButton_Assume1sun.isChecked():
                Sunintensity=self.ui.doubleSpinBox_NumbSun.value()
        
            ########
            
            for i in range(self.ui.spinBox_RepNumb.value()):
                # print('Sequence #'+str(i+1))
                
                sequence = str(self.ui.comboBox_MeasType.currentText())
                
                pixels=[]
                pixcolorslist=[]
                Allpixels=['A','B','C','D','E','F']
                allpixcolors=['black','red','blue','green','cyan','magenta']
                if self.ui.radioButton_pixAll.isChecked():
                    pixels=Allpixels
                    pixcolorslist=allpixcolors
                else:
                    checkboxlist=[self.ui.checkBox_pixA.isChecked(),self.ui.checkBox_pixB.isChecked(),
                                  self.ui.checkBox_pixC.isChecked(),self.ui.checkBox_pixD.isChecked(),
                                  self.ui.checkBox_pixE.isChecked(),self.ui.checkBox_pixF.isChecked()]
                    for item in range(6):
                        if checkboxlist[item]:
                            pixels.append(Allpixels[item])
                            pixcolorslist.append(allpixcolors[item])
                            
                if self.ui.comboBox_JVscandirection.currentText()=="Reverse + Forward":
                    scandirections=[0,1]
                elif self.ui.comboBox_JVscandirection.currentText()=="Forward + Reverse":
                    scandirections=[1,0]
                elif self.ui.comboBox_JVscandirection.currentText()=="Reverse":
                    scandirections=[0]
                elif self.ui.comboBox_JVscandirection.currentText()=="Forward":
                    scandirections=[1]
                
                #########################
                if sequence == 'LIV':
                    # print('LIV')
                    self.shutter('OpenShutter',keithleyObject)
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    self.shutter('CloseShutter',keithleyObject)
                    
                if sequence == 'DIV':
                    # print('DIV')
                    self.shutter('CloseShutter',keithleyObject)
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                if sequence == 'DIV-LIV':
                    # print('DIV-LIV')
                    # print('DIV')
                    self.shutter('CloseShutter',keithleyObject)
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    # print('LIV')
                    self.shutter('OpenShutter',keithleyObject)
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    self.shutter('CloseShutter',keithleyObject)
                    
                if sequence == 'MPPT':
                    # print('MPPT')
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                        
                    self.Tracking(keithleyObject,'MPPT', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                
                if sequence == 'FixedVoltage':
                    # print('FixedVoltage')
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    
                    self.Tracking(keithleyObject,'FixedVoltage', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    
                if sequence == 'FixedCurrent':
                    # print('FixedCurrent')
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                        
                    self.Tracking(keithleyObject,'FixedCurrent', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    
                if sequence == 'LIV-MPPT-LIV':
                    # print('LIV-MPPT-LIV')
                    self.shutter('OpenShutter',keithleyObject)
                    STOPMEAS=0
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0    
                    self.Tracking(keithleyObject,'MPPT', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    
                    STOPMEAS=0
                    aftermpp=1
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    self.shutter('CloseShutter',keithleyObject)
                    aftermpp=0
                    
                if sequence == 'LIV-bestpixMPPT-LIV':
                    # print('LIV-bestpixMPPT-LIV')
                    self.shutter('OpenShutter',keithleyObject)
                    STOPMEAS=0
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0    
                    self.Tracking(keithleyObject,'MPPTbest', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    
                    STOPMEAS=0
                    aftermpp=1
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    self.shutter('CloseShutter',keithleyObject)
                    aftermpp=0
                    
                if sequence == 'DIV-LIV-MPPT-LIV':
                    # print('DIV-LIV-MPPT-LIV')
                    # print('DIV')
                    self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    # print('LIV')
                    STOPMEAS=0
                    self.shutter('OpenShutter',keithleyObject)
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    # print('MPPT')
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0    
                    self.Tracking(keithleyObject,'MPPT', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                        
                    # print('LIV')
                    STOPMEAS=0
                    aftermpp=1
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    self.shutter('CloseShutter',keithleyObject)
                    aftermpp=0
                    
                if sequence == 'DIV-LIV-bestpixMPPT-LIV':
                    # print('DIV-LIV-bestpixMPPT-LIV')
                    # print('DIV')
                    self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    # print('LIV')
                    STOPMEAS=0
                    self.shutter('OpenShutter',keithleyObject)
                    QtTest.QTest.qWait(self.ui.doubleSpinBox_JVdelayshutter.value())
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    
                    # print('MPPT')
                    if self.ui.checkBox_MPPTlighton.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                    STOPMEAS=0    
                    self.Tracking(keithleyObject,'MPPTbest', pixels, pixcolorslist, scandirections, i)
                    
                    if self.ui.checkBox_MPPTlightonafter.isChecked():
                        self.shutter('OpenShutter',keithleyObject)
                    else:
                        self.shutter('CloseShutter',keithleyObject)
                        
                    # print('LIV')
                    STOPMEAS=0
                    aftermpp=1
                    self.PlotIV(keithleyObject, pixels, pixcolorslist, scandirections, i)
                    self.shutter('CloseShutter',keithleyObject)
                    aftermpp=0
                    
                if self.ui.spinBox_RepNumb.value()>1:
                    QtTest.QTest.qWait(self.ui.spinBox_RepDelay.value())
                    
            # print('measurement finished')
        
        #disconnect from DB

        QMessageBox.information(self,'Finished', 'The sequence is finished.')         
        self.ui.pushButton_StartMeas.setEnabled(True)
    
     
    def Tracking(self, keithleyObject,trackingtype, pixelslist, pixcolorslist, scandirections, Rep):
        global STOPMEAS,STOPMEASMPP, AlltrackingDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global boxCurrent, boxVoltage, keithleyAddress, lastmeasDATA
        allpixtobemeasured=''
        
        if trackingtype=='MPPTbest':
            pixels=[sorted(lastmeasDATA.items(), key=lambda x: x[1]['Eff'],reverse=True)[0][1]['Pixel']]
        else:
            pixels=pixelslist
        
        for item in range(len(pixels)):
            allpixtobemeasured+=pixels[item]
            allpixtobemeasured+=', '
        allpixtobemeasured=allpixtobemeasured[:-2]
        
        year=str(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[0])
        month=calendar.month_name[int(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[1])]
        directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'SolarSimAllUsersDATA',str(self.ui.lineEdit_UserName.text()),year,month)
        if not os.path.exists(directory):
            os.makedirs(directory)
            os.chdir(directory)
        else :
            os.chdir(directory)
        polar='pin'
        if self.ui.radioButton_nip.isChecked():
            polar='nip'
        if trackingtype=='FixedCurrent':
            prepareVoltage(keithleyObject, NPLC = 1,voltlimit = 10, polarity=polar)#prepare to apply a current and measure a voltage
        else:
            prepareCurrent(keithleyObject, NPLC = 1, currentlimit=1e-2, polarity=polar)#prepare to apply a voltage and measure a current

        for item in range(len(pixels)):
            STOPMEASMPP=0
            nMeas = 2
            timelist=[]
            currentlist=[]
            currentdensitylist=[]
            voltagelist=[]
            powerlist=[]
            steplist=[]
            delaylist=[]
            
            initialvoltage=self.ui.doubleSpinBox_MPPTstartvoltage.value()
            initialdelay=self.ui.doubleSpinBox_MPPTdelaypoints.value()
            initialstep=self.ui.spinBox_MPPTstepsize.value()
            connectPixel(boxCurrent, boxVoltage, pixels[item])
            pixcolor=pixcolorslist[item]
            pixarea=eval('self.ui.doubleSpinBox_pix'+pixels[item]+'area.value()')
            
            elapsed_timer = QtCore.QElapsedTimer()
            elapsed_timer.start()
            if self.ui.checkBox_MPPTlighton.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)
                
            while True:
                voltagefixed=self.ui.doubleSpinBox_MPPTstartvoltage.value()
                delay=self.ui.doubleSpinBox_MPPTdelaypoints.value()
                step=self.ui.spinBox_MPPTstepsize.value()
                if trackingtype=='FixedVoltage':
                    dataCurrent=measureCurrent(keithleyObject,voltagefixed/1000,nMeas,polarity = polar)
                    currentden=1000*abs(mean(dataCurrent[:,1]))/pixarea #mA/cm2
                    current=abs(mean(dataCurrent[:,1])) #A
                    currentlist.append(float(current))
                    currentdensitylist.append(float(currentden))
                    voltagelist.append(float(voltagefixed))#/1000))  #mV
                    powerlist.append(float(currentden*voltagefixed/1000)/Sunintensity)
                    timelist.append(float(elapsed_timer.elapsed()/1000))
                    steplist.append(step)
                    delaylist.append(delay)  
                    
                elif trackingtype=='FixedCurrent':
                    dataVoltage=measureVoltage(keithleyObject,voltagefixed/1000,nMeas,polarity = polar)
                    voltage=abs(mean(dataVoltage[:,1]))
                    currentlist.append(voltagefixed)
                    currentdensitylist.append(voltagefixed/pixarea)
                    voltagelist.append(voltage)
                    powerlist.append(voltage*voltagefixed/pixarea/Sunintensity)
                    timelist.append(float(elapsed_timer.elapsed()/1000))
                    steplist.append(step)
                    delaylist.append(delay)  
                
                elif trackingtype=='MPPT' or trackingtype=='MPPTbest':
                    if trackingtype=='MPPTbest':
                        voltagefixed=sorted(lastmeasDATA.items(), key=lambda x: x[1]['Eff'],reverse=True)[0][1]['Vmpp']
                        # print(voltagefixed)
                        
                    dataCurrent=measureCurrent(keithleyObject,voltagefixed/1000,nMeas,polarity = polar)
                    currentden=abs(mean(dataCurrent[:,1]))/pixarea
                    current=abs(mean(dataCurrent[:,1]))
                    
                    currentlist.append(current)
                    currentdensitylist.append(currentden)
                    voltagelist.append(voltagefixed/1000)
                    powerlist.append(currentden*voltagefixed/1000/Sunintensity)
                    timelist.append(float(elapsed_timer.elapsed()/1000))
                    steplist.append(step)
                    delaylist.append(delay)
                    
                    voltagefixed+=step
                    
                    while True:
                        step=self.ui.spinBox_MPPTstepsize.value()
                        delay=self.ui.doubleSpinBox_MPPTdelaypoints.value()
                        # if self.ui.checkBox_MPPTlighton.isChecked():
                        #     self.shutter('OpenShutter',keithleyObject)
                        # else:
                        #     self.shutter('CloseShutter',keithleyObject)
                        
                        dataCurrent=measureCurrent(keithleyObject,voltagefixed/1000,nMeas)
                        currentden=1000*abs(mean(dataCurrent[:,1]))/pixarea
                        current=abs(mean(dataCurrent[:,1]))
                        
                        currentlist.append(current)
                        currentdensitylist.append(currentden)
                        voltagelist.append(voltagefixed/1000)
                        powerlist.append(currentden*voltagefixed/1000/Sunintensity)
                        
                        timelist.append(float(elapsed_timer.elapsed()/1000))
                        steplist.append(step)
                        delaylist.append(delay)  
                        
                        self.MPPTgraph_JV.plot(voltagelist,currentdensitylist, linestyle="solid",color=pixcolor)
                        self.MPPTgraph_TV.plot(timelist,voltagelist, linestyle="solid",color=pixcolor)
                        self.MPPTgraph_TJ.plot(timelist,currentdensitylist, linestyle="solid",color=pixcolor)
                        self.MPPTgraph_TP.plot(timelist,powerlist, linestyle="solid",color=pixcolor)
                        
                        self.fig2.canvas.draw_idle()
                        self.fig2.canvas.flush_events()
                        
                        if abs(voltagefixed)>=abs(self.ui.doubleSpinBox_MPPTvoltagelimit.value()):
                            if voltagefixed>0:
                                voltagefixed-=step
                            else:
                                voltagefixed+=step
                        else:
                            if powerlist[-1]>powerlist[-2]:
                                if voltagelist[-1]>voltagelist[-2]:
                                    voltagefixed+=step
                                else:
                                    voltagefixed-=step
                            else:
                                if voltagelist[-1]>voltagelist[-2]:
                                    voltagefixed-=step
                                else:
                                    voltagefixed+=step
                        
                        QtTest.QTest.qWait(delay)
                        if STOPMEASMPP==1:#stops ongoing meas of pixel to pass to the next pixel
                            break
                        if STOPMEAS==1:#will stop all measurement and pass to the next step of sequence
                            break
                    
                                 
                    
                self.MPPTgraph_JV.plot(voltagelist,currentdensitylist, linestyle="solid",color=pixcolor)
                self.MPPTgraph_TV.plot(timelist,voltagelist, linestyle="solid",color=pixcolor)
                self.MPPTgraph_TJ.plot(timelist,currentdensitylist, linestyle="solid",color=pixcolor)
                self.MPPTgraph_TP.plot(timelist,powerlist, linestyle="solid",color=pixcolor)
                
                self.fig2.canvas.draw_idle()
                self.fig2.canvas.flush_events()
                
                QtTest.QTest.qWait(delay)
                
                # if keithleyAddress=='Test':
                #     QtTest.QTest.qWait(1000)#to be removed

                
                if STOPMEASMPP==1:#stops ongoing meas of pixel to pass to the next pixel
                    break
                if STOPMEAS==1:#will stop all measurement and pass to the next step of sequence
                    break
            
            if shutteropen:
                illum='lt'
            else:
                illum='dk'
            if self.ui.radioButton_Assume1sun.isChecked():
                radioButton_Assume1sun='True'
            else:
                radioButton_Assume1sun='False'
            timestr = QtCore.QDateTime.currentDateTime().toString(QtCore.Qt.ISODate)
            timestr=timestr.replace(':','').replace('-','')          

            sample=str(self.ui.lineEdit_SampleName.text()) +'_'+  'pX'+pixels[item] +'_'+ trackingtype +'_'+ illum +'_'+ 'lp'+str(Rep) +'_'+ timestr  
            samplename=str(self.ui.lineEdit_SampleName.text()).replace('-','_')
            if '_' in str(self.ui.lineEdit_SampleName.text()):
                Batch=str(self.ui.lineEdit_SampleName.text()).split('_')[0]
                Substrate=str(self.ui.lineEdit_SampleName.text()).split('_')[1]
            else:
                Batch='None'
                Substrate='None' 
            AlltrackingDATA[sample]={'sampleID': sample,'SampleNamePix': str(self.ui.lineEdit_SampleName.text()) +'_'+ pixels[item], 
                                     'linktorawdata':str(os.path.join(str(directory),sample+'.txt')),'SampleName': samplename,'Batch#':Batch,'Substrate#':Substrate,'Pixel':pixels[item],'Allpixs':allpixtobemeasured,
                                     'illum': illum, 'Sunintensity': Sunintensity, 'IsRefDiodeMeasured': RefDiodeChecked, 
                                     'RefDiodeNomCurr':self.ui.doubleSpinBox_DiodeNominalCurrent.value(),
                                     'RefDiodeMeasCurr':self.ui.doubleSpinBox_MeasuredDiodeCurrent.value(),
                                      'datetime': QtCore.QDateTime.currentDateTime(), 'Comment': str(self.ui.lineEdit_Comment.text()),'temperature':self.ui.doubleSpinBox_Temperature.value(),
                                      'UserName': str(self.ui.lineEdit_UserName.text()), 'MeasType': str(self.ui.comboBox_MeasType.currentText()),'MeasNowType': trackingtype,
                                      'RepNumb': Rep,'DelayRep':self.ui.spinBox_RepDelay.value(), 'pixelArea': pixarea,'assume1sun':radioButton_Assume1sun,'ShutterOpen':shutteropen,
                                      'InitialVoltage': initialvoltage, 'initialdelay':initialdelay,'initialstep':initialstep,'trackingtime': max(timelist),
                                      'step':steplist,'delay':delaylist,'Voltage':voltagelist,'Current':currentlist, 'CurrentDensity': currentdensitylist, 'time':timelist,'power':powerlist
                                      }
            lastmeastrackingDATA[sample]=AlltrackingDATA[sample]

            self.Savedata(sample,AlltrackingDATA)
            # self.loadtoDB(sample,AlltrackingDATA)
            
            if STOPMEAS==1:
                break
        self.loadtoDB('MPP',lastmeasDATA,lastmeastrackingDATA) 
        
    def PlotIVThreaded(self, keithleyObject, pixels, pixcolorslist, scandirections, Rep):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        self.pixels=pixels
        self.pixcolorslist=pixcolorslist
        self.scandirections=scandirections
        self.Rep=Rep
        
        allpixtobemeasured=''
        for item in range(len(pixels)):
            allpixtobemeasured+=pixels[item]
            allpixtobemeasured+=', '
        self.allpixtobemeasured=allpixtobemeasured[:-2]
        
        year=str(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[0])
        month=calendar.month_name[int(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[1])]
        self.directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'SolarSimAllUsersDATA',str(self.ui.lineEdit_UserName.text()),year,month)
        if not os.path.exists(self.directory):
            os.makedirs(self.directory)
            os.chdir(self.directory)
        else :
            os.chdir(self.directory)
        self.keithleyObject=keithleyObject
        self.thread = ThreadtakeIV(pixels,scandirections, keithleyObject)
        self.thread.result.connect(self.PlotIVThreadedUpdategraph)
        self.thread.finished.connect(self.PlotIVThreadedFinished)
        self.thread.start()
    
    def PlotIVThreadedFinished(self):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        pixels=self.pixels
        pixcolorslist=self.pixcolorslist
        scandirections=self.scandirections
        Rep=self.Rep
        directory=self.directory
        allpixtobemeasured=self.allpixtobemeasured
        keithleyObject=self.keithleyObject
        print('finished')
        
        if shutteropen:
            self.ClearGraph('LIV')
        else:
            self.ClearGraph('DIV')
        for sampleitem in lastmeasDATA.keys():
            pixcoloritem=lastmeasDATA[sampleitem]['pixcolor']
            if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
            elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
            if lastmeasDATA[sampleitem]['illum'] == 'dk':
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
                ydataabs=list(map(lambda x: abs(x),lastmeasDATA[sampleitem]['CurrentDensity']))
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="solid",color=pixcoloritem)
         
        if  self.sequence=='':
            if self.ui.checkBox_MPPTlightonafter.isChecked():
                self.shutter('OpenShutter',keithleyObject)
            else:
                self.shutter('CloseShutter',keithleyObject)           
        self.loadtoDB('IV',lastmeasDATA,lastmeastrackingDATA) 
        self.launchSequence(keithleyObject, pixels, pixcolorslist, scandirections, Rep)
        
        
    def PlotIVThreadedUpdategraph(self,data):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        pixels=self.pixels
        pixcolorslist=self.pixcolorslist
        scandirections=self.scandirections
        Rep=self.Rep
        directory=self.directory
        allpixtobemeasured=self.allpixtobemeasured
        keithleyObject=self.keithleyObject
        
        direction=data[0]
        item=data[1]
        data=data[2]
        
        pixcolor=pixcolorslist[item]
        
        # print(data)
        pixarea=eval('window.w.ui.doubleSpinBox_pix'+pixels[item]+'area.value()')
        currentlist=data[:,1]
        voltagelist=data[:,0]
        currentdenlist=[x*1000/pixarea for x in data[:,1]] #assume 1sun, and assume keithley gives Amperes back 
         
        if direction == 1:#forward scan 
            directionstr='fwd' 
            self.JVgraph.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
        elif direction == 0:#reverse scan 
            directionstr='rev' 
            self.JVgraph.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
        self.fig1.canvas.draw_idle() 
        self.fig1.canvas.flush_events()
         
        if shutteropen: 
            illum='lt' 
        else: 
            illum='dk' 
        if illum == 'dk': 
            if direction == 1:#forward scan 
                self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
            elif direction == 0:#reverse scan 
                self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
            ydataabs=list(map(lambda x: abs(x),currentdenlist)) 
            if direction == 1:#forward scan 
                self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="dashed",color=pixcolor) 
            elif direction == 0:#reverse scan 
                self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="solid",color=pixcolor) 
            self.fig3.canvas.draw_idle() 
            self.fig3.canvas.flush_events() 
        
        if self.ui.radioButton_Assume1sun.isChecked():
            radioButton_Assume1sun='True'
        else:
            radioButton_Assume1sun='False'
        timestr = QtCore.QDateTime.currentDateTime().toString(QtCore.Qt.ISODate)
        timestr=timestr.replace(':','').replace('-','')

        sample=str(self.ui.lineEdit_SampleName.text()) +'_'+  'pX'+pixels[item] +'_'+ directionstr +'_'+ illum +'_'+ 'lp'+str(Rep) +'_'+ timestr  
        samplename=str(self.ui.lineEdit_SampleName.text()).replace('-','_')
        if '_' in str(self.ui.lineEdit_SampleName.text()):
            Batch=str(self.ui.lineEdit_SampleName.text()).split('_')[0]
            Substrate=str(self.ui.lineEdit_SampleName.text()).split('_')[1]
        else:
            Batch='None'
            Substrate='None'
        
        commenttext=str(self.ui.lineEdit_Comment.text())
        if aftermpp:
            if 'aftermpp' not in commenttext:
                commenttext+='_aftermpp'
        polarity='pin'
        if self.ui.radioButton_nip.isChecked():
            polarity='nip'
        AllDATA[sample]={'sampleID': sample,'SampleNamePix': str(self.ui.lineEdit_SampleName.text()) +'_'+ pixels[item], 
                          'linktorawdata':str(os.path.join(str(directory),sample+'.txt')),'SampleName': samplename,'Batch#':Batch,'Substrate#':Substrate, 'Pixel':pixels[item], 'Allpixs':allpixtobemeasured,
                          'ScanDirection': directionstr, 'illum': illum, 'Sunintensity': Sunintensity, 'IsRefDiodeMeasured': RefDiodeChecked, 
                          'RefDiodeNomCurr':self.ui.doubleSpinBox_DiodeNominalCurrent.value(),'RefDiodeMeasCurr':self.ui.doubleSpinBox_MeasuredDiodeCurrent.value(),
                          'datetime': QtCore.QDateTime.currentDateTime(), 'Comment': commenttext,'temperature':self.ui.doubleSpinBox_Temperature.value(),
                          'UserName': str(self.ui.lineEdit_UserName.text()), 'MeasType': str(self.ui.comboBox_MeasType.currentText()),'MeasNowType': 'IV',
                          'pixcolor':pixcolor,'RepNumb': Rep,'DelayRep':self.ui.spinBox_RepDelay.value(), 'pixelArea': pixarea,'assume1sun':radioButton_Assume1sun,'ShutterOpen':shutteropen,
                          'MinVoltage': self.ui.doubleSpinBox_JVminvoltage.value(), 'MaxVoltage': self.ui.doubleSpinBox_JVmaxvoltage.value(),
                          'Aftermpp':aftermpp,'StepSize': self.ui.doubleSpinBox_JVstepsize.value(), 'CurrentLimit': self.ui.doubleSpinBox_JVcurrentlimit.value(), 
                          'IntegTime': self.ui.doubleSpinBox_JVintegrationtime.value(), 'Delaypts': self.ui.doubleSpinBox_JVdelaypoints.value(), 
                          'DelayShutter': self.ui.doubleSpinBox_JVdelayshutter.value(),'polarity':polarity,
                          'Voc': -1., 'Jsc': -1., 'Isc': -1., 'FF': -1., 'Eff': -1, 'Pmpp': -1., 'Roc':-1., 'Rsc':-1., 'Jmpp':-1, 'Vmpp':-1,
                          'Voltage':voltagelist,'Current':currentlist, 'CurrentDensity': currentdenlist
                          }
        lastmeasDATA[sample]=AllDATA[sample]

        self.AnalysisJV(sample)
        self.Savedata(sample,AllDATA)
        self.UpdateTable(lastmeasDATA)
        
    def PlotIV(self, keithleyObject, pixels, pixcolorslist, scandirections, Rep):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        # print('')
        # print(scandirections)
        allpixtobemeasured=''
        for item in range(len(pixels)):
            allpixtobemeasured+=pixels[item]
            allpixtobemeasured+=', '
        allpixtobemeasured=allpixtobemeasured[:-2]
        self.allpixtobemeasured=allpixtobemeasured
        
        year=str(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[0])
        month=calendar.month_name[int(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[1])]
        directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'SolarSimAllUsersDATA',str(self.ui.lineEdit_UserName.text()),year,month)
        if not os.path.exists(directory):
            os.makedirs(directory)
            os.chdir(directory)
        else :
            os.chdir(directory)
        integtime=self.ui.doubleSpinBox_JVintegrationtime.value()
        # NPLC of 1 with 60Hz power, new value every 16.67ms
        # integtime=50ms => NPLC = .050*60 = 3
        NPLC=integtime*60/1000
        if NPLC>10:
            NPLC=10
        if NPLC<0.01:
            NPLC=0.01
        polarity='pin'
        if self.ui.radioButton_nip.isChecked():
            polarity='nip'
        currentlimit=self.ui.doubleSpinBox_JVcurrentlimit.value()
        prepareCurrent(keithleyObject, NPLC,currentlimit,polarity)#prepare to apply a voltage and measure a current

        for item in range(len(pixels)):
            connectPixel(boxCurrent, boxVoltage, pixels[item])
            pixarea=eval('self.ui.doubleSpinBox_pix'+pixels[item]+'area.value()')
            pixcolor=pixcolorslist[item]
            
            for direction in scandirections:
                self.direction=direction
                if keithleyAddress=='Test':
                    QtTest.QTest.qWait(200)
                minV=self.ui.doubleSpinBox_JVminvoltage.value()/1000
                maxV=self.ui.doubleSpinBox_JVmaxvoltage.value()/1000
                stepV=self.ui.doubleSpinBox_JVstepsize.value()/1000
                delay=self.ui.doubleSpinBox_JVdelaypoints.value()
                data=takeIV(keithleyObject, minV,maxV,stepV,delay,direction,polarity,NPLC, currentlimit) 
                currentlist=data[:,1]
                voltagelist=data[:,0]
                currentdenlist=[x*1000/pixarea for x in data[:,1]] #assume 1sun, and assume keithley gives Amperes back 
                 
                if direction == 1:#forward scan 
                    directionstr='fwd' 
                    self.JVgraph.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
                elif direction == 0:#reverse scan 
                    directionstr='rev' 
                    self.JVgraph.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
                self.fig1.canvas.draw_idle() 
                 
                if shutteropen: 
                    illum='lt' 
                else: 
                    illum='dk' 
                if illum == 'dk': 
                    if direction == 1:#forward scan 
                        self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
                    elif direction == 0:#reverse scan 
                        self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
                    ydataabs=list(map(lambda x: abs(x),currentdenlist)) 
                    if direction == 1:#forward scan 
                        self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="dashed",color=pixcolor) 
                    elif direction == 0:#reverse scan 
                        self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="solid",color=pixcolor) 
                    self.fig3.canvas.draw_idle() 
                    self.fig3.canvas.flush_events() 
 
                self.fig1.canvas.flush_events() 
                
                if shutteropen:
                    illum='lt'
                    # self.ClearGraph('LIV')
                else:
                    illum='dk'
                    # self.ClearGraph('DIV')
                
                if self.ui.radioButton_Assume1sun.isChecked():
                    radioButton_Assume1sun='True'
                else:
                    radioButton_Assume1sun='False'
                timestr = QtCore.QDateTime.currentDateTime().toString(QtCore.Qt.ISODate)
                timestr=timestr.replace(':','').replace('-','')

                sample=str(self.ui.lineEdit_SampleName.text()) +'_'+  'pX'+pixels[item] +'_'+ directionstr +'_'+ illum +'_'+ 'lp'+str(Rep) +'_'+ timestr  
                samplename=str(self.ui.lineEdit_SampleName.text()).replace('-','_')
                if '_' in str(self.ui.lineEdit_SampleName.text()):
                    Batch=str(self.ui.lineEdit_SampleName.text()).split('_')[0]
                    Substrate=str(self.ui.lineEdit_SampleName.text()).split('_')[1]
                else:
                    Batch='None'
                    Substrate='None'
                
                commenttext=str(self.ui.lineEdit_Comment.text())
                if aftermpp:
                    if 'aftermpp' not in commenttext:
                        commenttext+='_aftermpp'
                
                AllDATA[sample]={'sampleID': sample,'SampleNamePix': str(self.ui.lineEdit_SampleName.text()) +'_'+ pixels[item], 
                                  'linktorawdata':str(os.path.join(str(directory),sample+'.txt')),'SampleName': samplename,'Batch#':Batch,'Substrate#':Substrate, 'Pixel':pixels[item], 'Allpixs':allpixtobemeasured,
                                  'ScanDirection': directionstr, 'illum': illum, 'Sunintensity': Sunintensity, 'IsRefDiodeMeasured': RefDiodeChecked, 
                                  'RefDiodeNomCurr':self.ui.doubleSpinBox_DiodeNominalCurrent.value(),'RefDiodeMeasCurr':self.ui.doubleSpinBox_MeasuredDiodeCurrent.value(),
                                  'datetime': QtCore.QDateTime.currentDateTime(), 'Comment': commenttext,'temperature':self.ui.doubleSpinBox_Temperature.value(),
                                  'UserName': str(self.ui.lineEdit_UserName.text()), 'MeasType': str(self.ui.comboBox_MeasType.currentText()),'MeasNowType': 'IV',
                                  'pixcolor':pixcolor,'RepNumb': Rep,'DelayRep':self.ui.spinBox_RepDelay.value(), 'pixelArea': pixarea,'assume1sun':radioButton_Assume1sun,'ShutterOpen':shutteropen,
                                  'MinVoltage': self.ui.doubleSpinBox_JVminvoltage.value(), 'MaxVoltage': self.ui.doubleSpinBox_JVmaxvoltage.value(),
                                  'Aftermpp':aftermpp,'StepSize': self.ui.doubleSpinBox_JVstepsize.value(), 'CurrentLimit': self.ui.doubleSpinBox_JVcurrentlimit.value(), 
                                  'IntegTime': self.ui.doubleSpinBox_JVintegrationtime.value(), 'Delaypts': self.ui.doubleSpinBox_JVdelaypoints.value(), 
                                  'DelayShutter': self.ui.doubleSpinBox_JVdelayshutter.value(),'polarity':polarity,
                                  'Voc': -1., 'Jsc': -1., 'Isc': -1., 'FF': -1., 'Eff': -1, 'Pmpp': -1., 'Roc':-1., 'Rsc':-1., 'Jmpp':-1, 'Vmpp':-1,
                                  'Voltage':voltagelist,'Current':currentlist, 'CurrentDensity': currentdenlist
                                  }
                lastmeasDATA[sample]=AllDATA[sample]

                self.AnalysisJV(sample)
                self.Savedata(sample,AllDATA)
                self.UpdateTable(lastmeasDATA)
                if STOPMEAS==1:
                    break
            if STOPMEAS==1:
                break
            
        if shutteropen:
            self.ClearGraph('LIV')
        else:
            self.ClearGraph('DIV')
        for sampleitem in lastmeasDATA.keys():
            pixcoloritem=lastmeasDATA[sampleitem]['pixcolor']
            if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
            elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
            if lastmeasDATA[sampleitem]['illum'] == 'dk':
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
                ydataabs=list(map(lambda x: abs(x),lastmeasDATA[sampleitem]['CurrentDensity']))
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="solid",color=pixcoloritem)
        
        self.loadtoDB('IV',lastmeasDATA,lastmeastrackingDATA) 
        
    def PlotIVlive(self, keithleyObject, pixels, pixcolorslist, scandirections, Rep): #live plot point by point, this seems to be slow when using the keithley
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        # print('')
        # print(scandirections)
        allpixtobemeasured=''
        for item in range(len(pixels)):
            allpixtobemeasured+=pixels[item]
            allpixtobemeasured+=', '
        allpixtobemeasured=allpixtobemeasured[:-2]
        
        year=str(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[0])
        month=calendar.month_name[int(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[1])]
        directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'SolarSimAllUsersDATA',str(self.ui.lineEdit_UserName.text()),year,month)
        if not os.path.exists(directory):
            os.makedirs(directory)
            os.chdir(directory)
        else :
            os.chdir(directory)
        integtime=self.ui.doubleSpinBox_JVintegrationtime.value()
        # NPLC of 1 with 60Hz power, new value every 16.67ms
        # integtime=50ms => NPLC = .050*60 = 3
        NPLC=integtime*60/1000
        if NPLC>10:
            NPLC=10
        if NPLC<0.01:
            NPLC=0.01
        currentlimit=self.ui.doubleSpinBox_JVcurrentlimit.value()
        nMeas=2
        polar='pin'
        if window.w.ui.radioButton_nip.isChecked():
            polar='nip'
        prepareCurrent(keithleyObject, NPLC,currentlimit,polar)#prepare to apply a voltage and measure a current

        for item in range(len(pixels)):
            connectPixel(boxCurrent, boxVoltage, pixels[item])
            pixarea=eval('self.ui.doubleSpinBox_pix'+pixels[item]+'area.value()')
            pixcolor=pixcolorslist[item]
            
            # print(scandirections)
            for direction in scandirections:
                # print(direction)
                # startIVtime=datetime.datetime.now()
                if keithleyAddress=='Test':
                    QtTest.QTest.qWait(500)

                minV=self.ui.doubleSpinBox_JVminvoltage.value()/1000
                maxV=self.ui.doubleSpinBox_JVmaxvoltage.value()/1000
                stepV=self.ui.doubleSpinBox_JVstepsize.value()/1000
                delay=self.ui.doubleSpinBox_JVdelaypoints.value()
                
                if shutteropen:
                    illum='lt'
                    self.ClearGraph('LIV')
                else:
                    illum='dk'
                    self.ClearGraph('DIV')
                # self.fig1.canvas.draw()
                # self.fig3.canvas.draw()
                # plt.show(block=False)
                
                # print(lastmeasDATA.keys())
                for sampleitem in lastmeasDATA.keys():
                    pixcoloritem=lastmeasDATA[sampleitem]['pixcolor']
                    if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                        self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
                    else:#reverse scan
                        self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
                    if lastmeasDATA[sampleitem]['illum'] == 'dk':
                        if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                            self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
                        else:#reverse scan
                            self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
                        ydataabs=list(map(lambda x: abs(x),lastmeasDATA[sampleitem]['CurrentDensity']))
                        if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                            self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="dashed",color=pixcoloritem)
                        else:#reverse scan
                            self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="solid",color=pixcoloritem)
                self.fig1.canvas.draw()
                self.fig3.canvas.draw()
                
                if direction == 1:#forward scan
                    directionstr='fwd'
                    startV, stopV = minV, maxV
                elif direction == 0:#reverse scan
                    directionstr='rev'
                    startV, stopV = maxV, minV
                    stepV *= -1
                forw=direction#0=rev, 1=fwd  
                
                volts = np.arange(startV, stopV+stepV, stepV)
                currentdenlist=[]
                currentlist=[]
                voltagelist=[]
                # lines = []
                # # print(volts)
                
                # line, = self.JVgraph.plot([],'o')
                # lines.append(line)
                
                # for step in volts:
                #     starttime=datetime.datetime.now()
                #     dataCurrent=measureCurrent(keithleyObject,step,nMeas)
                #     currentdenlist.append(1000*mean(dataCurrent[:,1])/pixarea)
                #     currentlist.append(mean(dataCurrent[:,1]))
                #     voltagelist.append(step)
                    
                #     lines[0].set_data(voltagelist,currentdenlist)
                #     self.fig1.canvas.draw()
                #     self.fig1.canvas.flush_events()
                    
                #     # self.JVgraph.plot(voltagelist,currentdenlist, 'o',color=pixcolor)
                    
                #     # if illum == 'dk':
                #     #     self.DIVgraphlin.plot(voltagelist,currentdenlist, 'o',color=pixcolor)
                #     #     ydataabs=list(map(lambda x: abs(x),currentdenlist))
                #     #     self.DIVgraphlogY.semilogy(voltagelist,ydataabs, 'o',color=pixcolor)
                #     #     # self.fig3.canvas.draw_idle()
                #     #     self.fig3.canvas.draw()
                #     #     self.fig3.canvas.flush_events()
                    
                #     # # self.fig1.canvas.draw_idle() 
                #     # self.fig1.canvas.draw()
                #     # self.fig1.canvas.flush_events()  
                    
                #     # QtTest.QTest.qWait(delay)
                #     # print((datetime.datetime.now()-starttime).microseconds/1000)
                #     while (datetime.datetime.now()-starttime).microseconds/1000< (delay+integtime):
                #         pass
                
                # print((datetime.datetime.now()-startIVtime).microseconds/1000)
                # startIVtime=datetime.datetime.now()
                for step in volts:
                    starttime=datetime.datetime.now()
                    dataCurrent=measureCurrent(keithleyObject,step,nMeas,polarity = polar)
                    currentdenlist.append(1000*mean(dataCurrent[:,1])/pixarea)
                    currentlist.append(mean(dataCurrent[:,1]))
                    voltagelist.append(step)
                    
                    self.JVgraph.plot(voltagelist,currentdenlist, 'o',color=pixcolor)
                    
                    # if illum == 'dk':
                    #     self.DIVgraphlin.plot(voltagelist,currentdenlist, 'o',color=pixcolor)
                    #     ydataabs=list(map(lambda x: abs(x),currentdenlist))
                    #     self.DIVgraphlogY.semilogy(voltagelist,ydataabs, 'o',color=pixcolor)
                    #     # self.fig3.canvas.draw_idle()
                    #     self.fig3.canvas.draw()
                    #     self.fig3.canvas.flush_events()
                    
                    # self.fig1.canvas.draw_idle() 
                    self.fig1.canvas.draw()
                    self.fig1.canvas.flush_events()  
                    
                    # QtTest.QTest.qWait(delay)
                    # print((datetime.datetime.now()-starttime).microseconds/1000)
                    while (datetime.datetime.now()-starttime).microseconds/1000< (delay+integtime):
                        pass
                # print((datetime.datetime.now()-startIVtime).microseconds/1000)
                # startIVtime=datetime.datetime.now()
                if self.ui.radioButton_Assume1sun.isChecked():
                    radioButton_Assume1sun='True'
                else:
                    radioButton_Assume1sun='False'
                timestr = QtCore.QDateTime.currentDateTime().toString(QtCore.Qt.ISODate)
                timestr=timestr.replace(':','').replace('-','')

                sample=str(self.ui.lineEdit_SampleName.text()) +'_'+  'pX'+pixels[item] +'_'+ directionstr +'_'+ illum +'_'+ 'lp'+str(Rep) +'_'+ timestr  
                samplename=str(self.ui.lineEdit_SampleName.text()).replace('-','_')
                if '_' in str(self.ui.lineEdit_SampleName.text()):
                    Batch=str(self.ui.lineEdit_SampleName.text()).split('_')[0]
                    Substrate=str(self.ui.lineEdit_SampleName.text()).split('_')[1]
                else:
                    Batch='None'
                    Substrate='None'
                
                commenttext=str(self.ui.lineEdit_Comment.text())
                if aftermpp:
                    if 'aftermpp' not in commenttext:
                        commenttext+='_aftermpp'
                
                AllDATA[sample]={'sampleID': sample,'SampleNamePix': str(self.ui.lineEdit_SampleName.text()) +'_'+ pixels[item], 
                                 'linktorawdata':str(os.path.join(str(directory),sample+'.txt')),'SampleName': samplename,'Batch#':Batch,'Substrate#':Substrate, 'Pixel':pixels[item], 'Allpixs':allpixtobemeasured,
                                 'ScanDirection': directionstr, 'illum': illum, 'Sunintensity': Sunintensity, 'IsRefDiodeMeasured': RefDiodeChecked, 
                                 'RefDiodeNomCurr':self.ui.doubleSpinBox_DiodeNominalCurrent.value(),'RefDiodeMeasCurr':self.ui.doubleSpinBox_MeasuredDiodeCurrent.value(),
                                 'datetime': QtCore.QDateTime.currentDateTime(), 'Comment': commenttext,'temperature':self.ui.doubleSpinBox_Temperature.value(),
                                 'UserName': str(self.ui.lineEdit_UserName.text()), 'MeasType': str(self.ui.comboBox_MeasType.currentText()),'MeasNowType': 'IV',
                                 'pixcolor':pixcolor,'RepNumb': Rep,'DelayRep':self.ui.spinBox_RepDelay.value(), 'pixelArea': pixarea,'assume1sun':radioButton_Assume1sun,'ShutterOpen':shutteropen,
                                 'MinVoltage': self.ui.doubleSpinBox_JVminvoltage.value(), 'MaxVoltage': self.ui.doubleSpinBox_JVmaxvoltage.value(),
                                 'Aftermpp':aftermpp,'StepSize': self.ui.doubleSpinBox_JVstepsize.value(), 'CurrentLimit': self.ui.doubleSpinBox_JVcurrentlimit.value(), 
                                 'IntegTime': self.ui.doubleSpinBox_JVintegrationtime.value(), 'Delaypts': self.ui.doubleSpinBox_JVdelaypoints.value(), 
                                 'DelayShutter': self.ui.doubleSpinBox_JVdelayshutter.value(),'polarity':polarity,
                                 'Voc': -1., 'Jsc': -1., 'Isc': -1., 'FF': -1., 'Eff': -1, 'Pmpp': -1., 'Roc':-1., 'Rsc':-1., 'Jmpp':-1, 'Vmpp':-1,
                                 'Voltage':voltagelist,'Current':currentlist, 'CurrentDensity': currentdenlist
                                 }
                lastmeasDATA[sample]=AllDATA[sample]

                self.AnalysisJV(sample)
                self.Savedata(sample,AllDATA)
                self.UpdateTable(lastmeasDATA)
                # print((datetime.datetime.now()-startIVtime).microseconds/1000)
                if STOPMEAS==1:
                    break
            if STOPMEAS==1:
                break
            
        if shutteropen:
            self.ClearGraph('LIV')
        else:
            self.ClearGraph('DIV')
        for sampleitem in lastmeasDATA.keys():
            pixcoloritem=lastmeasDATA[sampleitem]['pixcolor']
            if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
            elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                self.JVgraph.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
            if lastmeasDATA[sampleitem]['illum'] == 'dk':
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlin.plot(lastmeasDATA[sampleitem]['Voltage'],lastmeasDATA[sampleitem]['CurrentDensity'], linestyle="solid",color=pixcoloritem)
                ydataabs=list(map(lambda x: abs(x),lastmeasDATA[sampleitem]['CurrentDensity']))
                if lastmeasDATA[sampleitem]['ScanDirection'] == 'fwd':#forward scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="dashed",color=pixcoloritem)
                elif lastmeasDATA[sampleitem]['ScanDirection'] == 'rev':#reverse scan
                    self.DIVgraphlogY.semilogy(lastmeasDATA[sampleitem]['Voltage'],ydataabs, linestyle="solid",color=pixcoloritem)
        
        self.loadtoDB('IV',lastmeasDATA,lastmeastrackingDATA)  
    
    def AnalysisJV(self, sample):
        global AllDATA, lastmeasDATA, Sunintensity        
        
        resample_step_size = 0.00001 # Voltage step size to use while resampling JV curve to find Pmax
    
        from scipy.interpolate import interp1d
    
        # Create a dict to store the parameters. Default values are -1 indicating failure to extract parameter
        # print('')
        try:
            # Extract Jsc by interpolating wrt V
            jv_interp_V = interp1d(AllDATA[sample]['Voltage'], AllDATA[sample]['CurrentDensity'], bounds_error=False, fill_value=0.)
            Jsc = jv_interp_V(0.)
            AllDATA[sample]['Jsc'] = abs(np.around(Jsc, decimals=8))
            lastmeasDATA[sample]['Jsc']= AllDATA[sample]['Jsc'] 
            AllDATA[sample]['Isc'] = AllDATA[sample]['Jsc']*AllDATA[sample]['pixelArea']
            lastmeasDATA[sample]['Isc'] = AllDATA[sample]['Isc']
            # print(AllDATA[sample]['Jsc'])
        
            # Extract Voc by interpolating wrt J
            jv_interp_J = interp1d(AllDATA[sample]['CurrentDensity'], AllDATA[sample]['Voltage'], bounds_error=False, fill_value=0.)
            Voc = jv_interp_J(0.)
            AllDATA[sample]['Voc'] = 1000*np.around(Voc, decimals=4) #in mV
            lastmeasDATA[sample]['Voc'] = AllDATA[sample]['Voc'] 
            # print(AllDATA[sample]['Voc'])
            
            # Resample JV curve over standard interval and find Pmax
            Vrange_new = np.arange(0., Voc, resample_step_size)
    #            print(Vrange_new)
            jv_resampled = np.zeros((len(Vrange_new), 3))
            jv_resampled[:,0] = np.copy(Vrange_new)
            jv_resampled[:,1] = jv_interp_V(jv_resampled[:,0])
            jv_resampled[:,2] = np.abs(np.multiply(jv_resampled[:,0], jv_resampled[:,1]))
    #            print(jv_resampled)
            pmax=np.max(np.abs(np.multiply(jv_resampled[:,0], jv_resampled[:,1])))
            AllDATA[sample]['Pmpp'] = np.around(np.max(np.abs(np.multiply(jv_resampled[:,0], jv_resampled[:,1]))), decimals=4)
            AllDATA[sample]['Eff']=AllDATA[sample]['Pmpp']/Sunintensity #to correct for the actual light intensity measured with the ref diode
            lastmeasDATA[sample]['Pmpp'] = AllDATA[sample]['Pmpp']
            lastmeasDATA[sample]['Eff']=AllDATA[sample]['Eff']
            # print(AllDATA[sample]['Eff'])
            indPmax=list(jv_resampled[:,2]).index(pmax)
            AllDATA[sample]['Jmpp']=abs(list(jv_resampled[:,1])[indPmax]) 
            lastmeasDATA[sample]['Jmpp']=AllDATA[sample]['Jmpp']
    #            print(list(jv_resampled[:,1])[indPmax])
    #            print(indPmax)
    #            print(jv_interp_J(list(jv_resampled[:,1])[indPmax]))
            AllDATA[sample]['Vmpp']=1000*abs(list(jv_resampled[:,0])[indPmax])
            lastmeasDATA[sample]['Vmpp']=AllDATA[sample]['Vmpp']
    #            print(params['Vmpp'])
        
            # Calculate fill factor
            AllDATA[sample]['FF'] = abs(100*np.around(pmax/(Jsc*Voc), decimals=4))
            lastmeasDATA[sample]['FF'] =AllDATA[sample]['FF']
            # print(AllDATA[sample]['FF'])
            # print('')
            # Calculate Rsc&Roc 
            x= [x0 for x0,y0 in sorted(zip(AllDATA[sample]['Voltage'],AllDATA[sample]['CurrentDensity']))]
            y= [0.001*y0 for x0,y0 in sorted(zip(AllDATA[sample]['Voltage'],AllDATA[sample]['CurrentDensity']))]
            
            xSC=[]
            ySC=[]
            for i in range(len(x)):
                if x[i]>=0:
                    xSC.append(x[i-3])
                    xSC.append(x[i-2])
                    xSC.append(x[i-1])
                    xSC.append(x[i])
                    xSC.append(x[i+1])
                    xSC.append(x[i+2])
                    ySC.append(y[i-3])
                    ySC.append(y[i-2])
                    ySC.append(y[i-2])
                    ySC.append(y[i])
                    ySC.append(y[i+1])
                    ySC.append(y[i+2])
                    break

            xSC=np.array(xSC)
            ySC=np.array(ySC)    
                
            xy=[xi*yi for xi, yi in zip(xSC,ySC)]
            xSC2=[xi**2 for xi in xSC]
            AllDATA[sample]['Rsc'] =abs( 1/(((sum(xSC)*sum(ySC)) - len(xSC)*sum(xy)) / ((sum(xSC)*sum(xSC)) - len(xSC)*sum(xSC2)))) 
            lastmeasDATA[sample]['Rsc'] =AllDATA[sample]['Rsc']
            # print(AllDATA[sample]['Rsc'])
            
            if AllDATA[sample]['Jsc']>1:
                xSC=[]
                ySC=[]
                for i in range(len(x)):
                    if x[i]>=AllDATA[sample]['Voc']*0.001:
                        xSC.append(x[i-2])
                        xSC.append(x[i-1])
                        xSC.append(x[i])
                        xSC.append(x[i+1])
                        
                        ySC.append(y[i-2])
                        ySC.append(y[i-1])
                        ySC.append(y[i])
                        ySC.append(y[i+1])
                        break
                xSC=np.array(xSC)
                ySC=np.array(ySC)
                
                xy=[xi*yi for xi, yi in zip(xSC,ySC)]
                xSC2=[xi**2 for xi in xSC]
                AllDATA[sample]['Roc'] =abs( 1/(((sum(xSC)*sum(ySC)) - len(xSC)*sum(xy)) / ((sum(xSC)*sum(xSC)) - len(xSC)*sum(xSC2))))
                lastmeasDATA[sample]['Roc'] =AllDATA[sample]['Roc']
            else:
                xSC=x[-3:]
                ySC=y[-3:]
                xSC=np.array(xSC)
                ySC=np.array(ySC)      
                xy=[xi*yi for xi, yi in zip(xSC,ySC)]
                xSC2=[xi**2 for xi in xSC]
                AllDATA[sample]['Roc'] = abs( 1/(((sum(xSC)*sum(ySC)) - len(xSC)*sum(xy)) / ((sum(xSC)*sum(xSC)) - len(xSC)*sum(xSC2))))
                lastmeasDATA[sample]['Roc'] =AllDATA[sample]['Roc']
            # print(AllDATA[sample]['Roc'])
        except:
            print("error with fits, probably a dark curve...")
            
#%%######################################################################################################            
    def Savedata(self, sample, DATA):
        year=str(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[0])
        month=calendar.month_name[int(QtCore.QDate.currentDate().toString(QtCore.Qt.ISODate).split('-')[1])]
        directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'SolarSimAllUsersDATA',str(self.ui.lineEdit_UserName.text()),year,month)
        if not os.path.exists(directory):
            os.makedirs(directory)
            os.chdir(directory)
        else :
            os.chdir(directory)
        
        if DATA[sample]['MeasNowType']=='IV':
            text='#Boulder Solar Simulator, Python\n'+\
                '\n'+\
                'DateTime:\t'+	DATA[sample]['datetime'].toString()+'\n'+\
                'UserName:\t'+str(DATA[sample]['UserName']) +'\n'+\
                'SampleName:\t'+str(DATA[sample]['SampleName']) +'\n'+\
                'Comment:\t'+str(DATA[sample]['Comment'])+'\n'+\
                'Meas. type:\t'+str(DATA[sample]['MeasType'])+'\n'+\
                'WhichPixels:\t'+str(DATA[sample]['Allpixs'])+'\n'+\
                'PixelNow:\t'+str(DATA[sample]['Pixel'])+'\n'+\
                'PixArea:\t'+str(DATA[sample]['pixelArea'])+'\n'+\
                '#rep:\t'+str(DATA[sample]['RepNumb'])+'\n'+\
                'DelayRep:\t'+str(DATA[sample]['DelayRep'])+'\n'+\
                'Aftermpp:\t'+str(DATA[sample]['Aftermpp'])+'\n'+\
                '\n'+\
                'WasRefMeasured?:\t'+str(DATA[sample]['IsRefDiodeMeasured'])+'\n'+\
                'Diode nominal current:\t'+str(DATA[sample]['RefDiodeNomCurr'])+'\n'+\
                'Diode measured current:\t'+str(DATA[sample]['RefDiodeMeasCurr'])+'\n'+\
                '#sun:\t'+str(DATA[sample]['Sunintensity'])+'\n'+\
                'temperature:\t'+str(DATA[sample]['temperature'])+'\n'+\
                'assume1sun:\t'+str(DATA[sample]['assume1sun'])+'\n'+\
                '\n'+\
                'Illumination:\t'+str(DATA[sample]['illum'])+'\n'+\
                'ShutterOpen:\t'+str(DATA[sample]['ShutterOpen'])+'\n'+\
                '\n'+\
                '#IV scan Parameters\n'+\
                'minvoltage:\t'+str(DATA[sample]['MinVoltage'])+'\n'+\
                'maxvoltage:\t'+str(DATA[sample]['MaxVoltage'])+'\n'+\
                'JVstepsize:\t'+str(DATA[sample]['StepSize'])+'\n'+\
                'currentlimit:\t'+str(DATA[sample]['CurrentLimit'])+'\n'+\
                'integtime:\t'+str(DATA[sample]['IntegTime'])+'\n'+\
                'delaypoints:\t'+str(DATA[sample]['Delaypts'])+'\n'+\
                'delayshutter:\t'+str(DATA[sample]['DelayShutter'])+'\n'+\
                'scandirection:\t'+str(DATA[sample]['ScanDirection'])+'\n'+\
                'polarity:\t'+str(DATA[sample]['polarity'])+'\n'+\
                '\n'+\
                '#IV results\n'+\
                'Eff\t'+str(DATA[sample]['Eff'])+'\n'+\
                'Voc\t'+str(DATA[sample]['Voc'])+'\n'+\
                'FF\t'+str(DATA[sample]['FF'])+'\n'+\
                'Jsc\t'+str(DATA[sample]['Jsc'])+'\n'+\
                'Isc\t'+str(DATA[sample]['Isc'])+'\n'+\
                'Pmpp\t'+str(DATA[sample]['Pmpp'])+'\n'+\
                'Vmpp\t'+str(DATA[sample]['Vmpp'])+'\n'+\
                'Jmpp\t'+str(DATA[sample]['Jmpp'])+'\n'+\
                'Roc\t'+str(DATA[sample]['Roc'])+'\n'+\
                'Rsc\t'+str(DATA[sample]['Rsc'])+'\n'+\
                '\n'+\
                '#IV data\n'+\
                'Voltage\tCurrentDensity\tCurrent\n'
            for i in range(len(DATA[sample]['Voltage'])):
                text+=str(DATA[sample]['Voltage'][i])+'\t'+str(DATA[sample]['CurrentDensity'][i])+'\t'+str(DATA[sample]['Current'][i])+'\n'
            with open(DATA[sample]['sampleID']+'.txt','w') as file:
                file.write(text)
            
        else:
            text='#Boulder Solar Simulator, Python\n'+\
                '\n'+\
                'DateTime:\t'+	DATA[sample]['datetime'].toString()+'\n'+\
                'UserName:\t'+str(DATA[sample]['UserName']) +'\n'+\
                'SampleName:\t'+str(DATA[sample]['SampleName']) +'\n'+\
                'Comment:\t'+str(DATA[sample]['Comment'])+'\n'+\
                'Meas. type:\t'+str(DATA[sample]['MeasType'])+'\n'+\
                'WhichPixels:\t'+str(DATA[sample]['Allpixs'])+'\n'+\
                'PixelNow:\t'+str(DATA[sample]['Pixel'])+'\n'+\
                'PixArea:\t'+str(DATA[sample]['pixelArea'])+'\n'+\
                '#rep:\t'+str(DATA[sample]['RepNumb'])+'\n'+\
                'DelayRep:\t'+str(DATA[sample]['DelayRep'])+'\n'+\
                '\n'+\
                'WasRefMeasured?:\t'+str(DATA[sample]['IsRefDiodeMeasured'])+'\n'+\
                'Diode nominal current:\t'+str(DATA[sample]['RefDiodeNomCurr'])+'\n'+\
                'Diode measured current:\t'+str(DATA[sample]['RefDiodeMeasCurr'])+'\n'+\
                '#sun:\t'+str(DATA[sample]['Sunintensity'])+'\n'+\
                'temperature:\t'+str(DATA[sample]['temperature'])+'\n'+\
                'assume1sun:\t'+str(DATA[sample]['assume1sun'])+'\n'+\
                '\n'+\
                'Illumination:\t'+str(DATA[sample]['illum'])+'\n'+\
                'ShutterOpen:\t'+str(DATA[sample]['ShutterOpen'])+'\n'+\
                '\n'+\
                '#MPPT scan Parameters\n'+\
                'InitialVoltage:\t'+str(DATA[sample]['InitialVoltage'])+'\n'+\
                'initialdelay:\t'+str(DATA[sample]['initialdelay'])+'\n'+\
                'initialstep:\t'+str(DATA[sample]['initialstep'])+'\n'+\
                '\n'+\
                '#MPPT data\n'+\
                'Time\tPower\tVoltage\tCurrentDensity\tCurrent\tStep\tDelay\n'
            for i in range(len(DATA[sample]['Voltage'])):
                text+=str(DATA[sample]['time'][i])+'\t'+str(DATA[sample]['power'][i])+'\t'+str(DATA[sample]['Voltage'][i])+'\t'+str(DATA[sample]['CurrentDensity'][i])+'\t'+str(DATA[sample]['Current'][i])+'\t'+str(DATA[sample]['step'][i])+'\t'+str(DATA[sample]['delay'][i])+'\n'
            with open(DATA[sample]['sampleID']+'.txt','w') as file:
                file.write(text)

#%%######################################################################################################    
    def loadtoDB(self, MeasType, ivDATA, mppdata):       
        
        if MeasType=='IV':
            DATA=ivDATA
        else:
            DATA=mppdata
        
        for sample in DATA.keys():
            #username in Table users        
            self.theCursor.execute("SELECT id FROM users WHERE user=?",(DATA[sample]['UserName'],))
            users_id_exists = self.theCursor.fetchone()
            if users_id_exists==None:
                self.theCursor.execute("INSERT INTO users (user) VALUES (?)",
                                (DATA[sample]['UserName'],))
                users_id_exists=self.theCursor.lastrowid
            else:
                users_id_exists=users_id_exists[0]
                    
            # #batchname in Table batch, with users_id
            self.theCursor.execute("SELECT id FROM batch WHERE batchname =? AND users_id =?",(DATA[sample]['Batch#'],users_id_exists,))
            batch_id_exists = self.theCursor.fetchone()
            if batch_id_exists==None:
                self.theCursor.execute("INSERT INTO batch (batchname,users_id) VALUES (?,?)",
                                (DATA[sample]['Batch#'],users_id_exists,))
                batch_id_exists=self.theCursor.lastrowid
            else:
                batch_id_exists=batch_id_exists[0]
                    
            #samplename in table samples, with batch_id
            self.theCursor.execute("SELECT id FROM samples WHERE samplename =? AND batch_id =?",(DATA[sample]['SampleName'],batch_id_exists,))
            samples_id_exists = self.theCursor.fetchone()
            # print(samples_id_exists)
            if samples_id_exists==None:
                self.theCursor.execute("INSERT INTO samples (samplename,batch_id) VALUES (?,?)",
                                (DATA[sample]['SampleName'],batch_id_exists,))
                samples_id_exists=self.theCursor.lastrowid
            else:
                samples_id_exists=samples_id_exists[0]
            # print(samples_id_exists)
            
            #sample pixel area
            self.theCursor.execute("SELECT id FROM pixelarea WHERE pixel_area =?",(DATA[sample]['pixelArea'],))
            pixelarea_id_exists = self.theCursor.fetchone()
            if pixelarea_id_exists==None:
                self.theCursor.execute("INSERT INTO pixelarea (pixel_area) VALUES (?)",
                                (DATA[sample]['pixelArea'],))
                pixelarea_id_exists=self.theCursor.lastrowid
            else:
                pixelarea_id_exists=pixelarea_id_exists[0]
            
            #table cells
            self.theCursor.execute("SELECT id FROM cells WHERE cellname =? AND samples_id =? AND batch_id =?",(DATA[sample]['Pixel'],samples_id_exists,batch_id_exists,))
            cells_id_exists = self.theCursor.fetchone()
            if cells_id_exists==None:
                self.theCursor.execute("INSERT INTO cells (cellname,AllpixSeq, pixelarea_id,samples_id,batch_id) VALUES (?,?,?,?,?)",
                                (DATA[sample]['Pixel'],DATA[sample]['Allpixs'],pixelarea_id_exists,samples_id_exists,batch_id_exists,))
                cells_id_exists=self.theCursor.lastrowid
            else:
                cells_id_exists=cells_id_exists[0]
        
            self.theCursor.execute("INSERT INTO Refdiode (IsRefDiodeMeasured,RefDiodeNomCurr,RefDiodeMeasCurr,temperature) VALUES (?,?,?,?)",
                                (DATA[sample]['IsRefDiodeMeasured'],DATA[sample]['RefDiodeNomCurr'],DATA[sample]['RefDiodeMeasCurr'],DATA[sample]['temperature'],))
            refdiode_id_exists=self.theCursor.lastrowid
            
            
            if DATA[sample]['MeasNowType']=='IV':
                #tables JVmeas
                self.theCursor.execute("SELECT id FROM JVmeas WHERE MeasurementLongName =? AND cells_id =? AND samples_id =? AND batch_id =?",(DATA[sample]['sampleID'],cells_id_exists,samples_id_exists,batch_id_exists,))
                JVmeas_id_exists = self.theCursor.fetchone()
                if JVmeas_id_exists==None:
                    self.theCursor.execute("INSERT INTO JVmeas (DateTimeJV, Eff, Voc,Jsc,Isc, FF, Vmpp, Jmpp,Pmpp,Roc,Rsc,ScanDirect,Delay, DelayShutter,IntegTime,Vmin,Vmax,MeasType,MeasNowType,StepSize,CurrentLimit,LightDark,IlluminationIntensity,commentJV,MeasurementLongName,SampleNamePix,linktorawdata,aftermpp,samples_id,batch_id,cells_id,Refdiode_id) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
                                    (DATA[sample]['datetime'].toString(QtCore.Qt.ISODate).replace('T','-').replace(':','-') ,DATA[sample]['Eff'],DATA[sample]['Voc'],DATA[sample]['Jsc'],
                                     DATA[sample]['Isc'],DATA[sample]['FF'],DATA[sample]['Vmpp'],DATA[sample]['Jmpp'],
                                     DATA[sample]['Pmpp'],DATA[sample]['Roc'],DATA[sample]['Rsc'],DATA[sample]['ScanDirection'],
                                     DATA[sample]['Delaypts'],DATA[sample]['DelayShutter'],DATA[sample]['IntegTime'],DATA[sample]['MinVoltage'],
                                     DATA[sample]['MaxVoltage'],DATA[sample]['MeasType'],DATA[sample]['MeasNowType'],DATA[sample]['StepSize'],
                                     DATA[sample]['CurrentLimit'],DATA[sample]['illum'],DATA[sample]['Sunintensity'],DATA[sample]['Comment'],
                                     DATA[sample]['sampleID'],DATA[sample]['SampleNamePix'],DATA[sample]['linktorawdata'],DATA[sample]['Aftermpp'],
                                     samples_id_exists,batch_id_exists,cells_id_exists,refdiode_id_exists,))
                    JVmeas_id_exists=self.theCursor.lastrowid
                else:
                    JVmeas_id_exists=JVmeas_id_exists[0]
            else:
                #tables Mppmeas
                self.theCursor.execute("SELECT id FROM MPPmeas WHERE MeasurementLongName =? AND cells_id =? AND samples_id =? AND batch_id =?",(DATA[sample]['sampleID'],cells_id_exists,samples_id_exists,batch_id_exists,))
                MPPmeas_id_exists = self.theCursor.fetchone()
                if MPPmeas_id_exists==None:
                    self.theCursor.execute("INSERT INTO MPPmeas (DateTimeMPP,TrackingAlgo,MeasType,MeasNowType,TrackingDuration,Vstart,Vstep,Delay,PowerEnd,commentmpp,LightDark,IlluminationIntensity,MeasurementLongName,SampleNamePix,linktorawdata,samples_id,batch_id, cells_id,Refdiode_id,PowerEnd) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
                                    (DATA[sample]['datetime'].toString(QtCore.Qt.ISODate).replace('T','-').replace(':','-'),'perturbe&observe',DATA[sample]['MeasType'],DATA[sample]['MeasNowType'],
                                     DATA[sample]['trackingtime'],DATA[sample]['InitialVoltage'],DATA[sample]['initialstep'],DATA[sample]['initialdelay'],
                                     DATA[sample]['power'][-1],DATA[sample]['Comment'],DATA[sample]['illum'],
                                     DATA[sample]['Sunintensity'],DATA[sample]['sampleID'],DATA[sample]['SampleNamePix'],DATA[sample]['linktorawdata'],
                                     samples_id_exists,batch_id_exists,cells_id_exists,refdiode_id_exists,DATA[sample]['power'][-1],))
                    MPPmeas_id_exists=self.theCursor.lastrowid
                else:
                    MPPmeas_id_exists=MPPmeas_id_exists[0]
                    
            self.db_conn.commit()
        
    
    def connecttoDB(self):
        directory=os.path.join(str(Path(os.path.abspath(__file__)).parent.parent),'Database')
        if not os.path.exists(directory):
            os.makedirs(directory)
            os.chdir(directory)
        else :
            os.chdir(directory)
        path=os.path.join(directory,'CUMcGeheeGeneralDB.db')
        
        self.db_conn=sqlite3.connect(path)
        self.theCursor=self.db_conn.cursor()
        # print("connected to database")
        CreateAllTables(self.db_conn)
    
    def onclickDBtab(self,indexoftab):
        # print(indexoftab)   
        if indexoftab:
            self.ui.comboBox_DBTime.clear()
            timecriterialist=DBreadPack.timecriteria
            for i in range(len(timecriterialist)):
                self.ui.comboBox_DBTime.addItem(timecriterialist[i])
                
            
    def on_combobox_DBTime_changed(self):

        self.ui.comboBox_DBTimeYaxis.clear()
        
        yaxisoptionlist=DBreadPack.fromtocriteria
        for i in range(len(yaxisoptionlist)):
            if 'JV' in self.ui.comboBox_DBTime.currentText():
                if 'MPP' not in yaxisoptionlist[i]:
                    self.ui.comboBox_DBTimeYaxis.addItem(yaxisoptionlist[i])
            elif 'MPP' in self.ui.comboBox_DBTime.currentText():
                if 'JV' not in yaxisoptionlist[i]:
                    self.ui.comboBox_DBTimeYaxis.addItem(yaxisoptionlist[i])
        
        self.ui.comboBox_DBTime_restrictions.clear()
        
        restrictionslist=DBreadPack.fromtocriteria + DBreadPack.dropdowncriteria
            
        for i in range(len(restrictionslist)):
            if 'JV' in self.ui.comboBox_DBTime.currentText():
                if 'MPP' not in restrictionslist[i]:
                    self.ui.comboBox_DBTime_restrictions.addItem(restrictionslist[i])
            elif 'MPP' in self.ui.comboBox_DBTime.currentText():
                if 'JV' not in restrictionslist[i]:
                    self.ui.comboBox_DBTime_restrictions.addItem(restrictionslist[i])

    def on_combobox_DBTimeRestrictions_changed(self):
        criteria=self.ui.comboBox_DBTime_restrictions.currentText()
        if criteria in DBreadPack.fromtocriteria:
            # print(criteria)
            self.theCursor.execute("SELECT "+criteria.split('.')[1]+" FROM "+criteria.split('.')[0])
            listoptions=list(set([x[0] for x in self.theCursor.fetchall()]))
            minimum=min(listoptions)
            maximum=max(listoptions)
            self.ui.lineEdit_DBTime_From.setText(str(minimum))
            self.ui.lineEdit_DBTime_To.setText(str(maximum))
        elif criteria in DBreadPack.dropdowncriteria:
            # print('here')
            self.ui.listWidget_DBTime_Restrictions.clear()
            self.theCursor.execute("SELECT "+criteria.split('.')[1]+" FROM "+criteria.split('.')[0])
            listoptions=list(set([x[0] for x in self.theCursor.fetchall()]))
            for item in listoptions:
                self.ui.listWidget_DBTime_Restrictions.addItem(str(item))
    
    def Addrestriction(self):
        
        currentrestrictionparam = self.ui.comboBox_DBTime_restrictions.currentText()
        if currentrestrictionparam in DBreadPack.fromtocriteria:
            self.ui.listWidget_DBTime_chosenRestrictions.addItem(currentrestrictionparam+'__'+self.ui.lineEdit_DBTime_From.text()+'__'+self.ui.lineEdit_DBTime_To.text())
        elif currentrestrictionparam in DBreadPack.dropdowncriteria:
            selectedrestparam=self.ui.listWidget_DBTime_Restrictions.selectedItems()
            for i in selectedrestparam:
                self.ui.listWidget_DBTime_chosenRestrictions.addItem(currentrestrictionparam+'__'+i.text())
        self.SearchAndPlot()
                
    def Removerestriction(self):
        self.ui.listWidget_DBTime_chosenRestrictions.takeItem(self.ui.listWidget_DBTime_chosenRestrictions.currentRow())
        self.SearchAndPlot()
        
    def SearchAndPlot(self):
        
        criteria=self.ui.comboBox_DBTimeYaxis.currentText()
        timecrit=self.ui.comboBox_DBTime.currentText()
        # if criteria.split('.')[0]==timecrit.split('.')[0]:#MPP-MPP or JV-JV
        #     self.theCursor.execute("SELECT "+timecrit.split('.')[1]+', ' + criteria.split('.')[1]+" FROM "+criteria.split('.')[0])
        #     results=self.theCursor.fetchall()
        #     date=[datetime.datetime.strptime(x[0],'%Y-%m-%d-%H-%M-%S') for x in results]
        #     ydata=[x[1] for x in results]
        # elif criteria.split('.')[0]=='Refdiode': #JV-Refdiode or MPP-Refdiode
        #     self.theCursor.execute("SELECT "+timecrit +', ' + criteria +" FROM "+criteria.split('.')[0]+', ' + timecrit.split('.')[0] + ' WHERE Refdiode.id = '+ timecrit.split('.')[0]+'.Refdiode_id')
        #     results=self.theCursor.fetchall()
        #     date=[datetime.datetime.strptime(x[0],'%Y-%m-%d-%H-%M-%S') for x in results]
        #     ydata=[x[1] for x in results]
            
        # self.DBgraph.clear()
        # self.DBgraph.plot(date,ydata,'o')
        # self.DBgraph.set_xlabel('Date/Time')
        # self.DBgraph.set_ylabel(criteria.split('.')[1])
        # for tick in self.DBgraph.get_xticklabels():
        #     tick.set_rotation(15)
        # self.fig4.canvas.draw()
        # self.fig4.canvas.flush_events()
        
        
        items = []
        for index in range(self.ui.listWidget_DBTime_chosenRestrictions.count()):
             items.append(self.ui.listWidget_DBTime_chosenRestrictions.item(index).text()) 
             
        criteriaListdetailled=[]
        criteriaListdetailled2=[]
        for item in items:
            if len(item.split('__'))==2:
                criteriaListdetailled.append([item.split('__')[0],[item.split('__')[1]]])
            elif len(item.split('__'))==3:
                criteriaListdetailled2.append([item.split('__')[0],item.split('__')[1],item.split('__')[2]])
        
             
        #get the from
             
        #get where: list of id matches
        #get where: from listbox, blabla = blabli or ...
        #get where: from fromto, (blabla between ll and ll) and ...
        parameterList=[timecrit,criteria]
        parametertables=list(set([x.split('.')[0] for x in parameterList]))
        parametertables=sorted(parametertables, key=lambda s: s.casefold())
        criteriaList=[x.split('__')[0] for x in items]
        tablenames=list(set(["batch","samples"]+[timecrit.split('.')[0],criteria.split('.')[0]]+[x.split('.')[0] for x in criteriaList]))
        # print(items)
        # print(criteriaList)
        # print(tablenames)
        
        if criteria.split('.')[0]==timecrit.split('.')[0]:
            SelectInstructions="SELECT "+timecrit +', ' + criteria +" FROM "#+criteria.split('.')[0] + ',samples, batch, cells WHERE '
            for item in tablenames:
                SelectInstructions+=item+', '
            SelectInstructions=SelectInstructions[:-2]+" WHERE "
            wherelist=[criteria.split('.')[0]]
        else:
            SelectInstructions="SELECT "+timecrit +', ' + criteria +" FROM "#+criteria.split('.')[0]+', ' + timecrit.split('.')[0] + ', samples, batch, cells WHERE '
            for item in tablenames:
                SelectInstructions+=item+', '
            SelectInstructions=SelectInstructions[:-2]+" WHERE "
            wherelist=[criteria.split('.')[0]]
             
        items+=[criteria.split('.')[0],timecrit.split('.')[0]]
        # print(items)
        # criteriaList=[self.listWidget2.item(i).text() for i in range(self.listWidget2.count())]
        
        # tablenames=list(set(["batch","samples","cells"]+[x.split('.')[0] for x in items]))
        # tablenames=list(set([x.split('.')[0] for x in items]))
        # print(tablenames)
        wherelist=["samples.batch_id = batch.id AND "]
        # wherelist=[]
        for item in tablenames:
            self.theCursor.execute("SELECT * FROM "+item)
            headcol=[x[0] for x in self.theCursor.description]  
            headcol=[x[:-3] for x in headcol if '_id' in x] 
            # print(headcol)
            for item2 in headcol:
                if item2 in tablenames:
                    wherelist.append(item+'.'+item2+'_id = '+item2+'.id AND ')
        wherelist=list(set(wherelist))
        # print(wherelist)
        for item in wherelist:
            SelectInstructions+=item
        for item in criteriaListdetailled:
            SelectInstructions+='('
            for item2 in item[1]:
                SelectInstructions+= item[0]+' = '+"'"+str(item2)+"' OR "
            SelectInstructions=SelectInstructions[:-4]+') AND '
        for item in criteriaListdetailled2:
            SelectInstructions+= '('+item[0] + ' BETWEEN ' + item[1] + ' AND ' + item[2] +') AND '
        
        # print(SelectInstructions[:-4])
        self.theCursor.execute(SelectInstructions[:-4])
        data=self.theCursor.fetchall()
        
        date=[datetime.datetime.strptime(x[0],'%Y-%m-%d-%H-%M-%S') for x in data]
        ydata=[x[1] for x in data]
             
        self.DBgraph.clear()
        self.DBgraph.plot(date,ydata,'o')
        self.DBgraph.set_xlabel('Date/Time')
        self.DBgraph.set_ylabel(criteria.split('.')[1])
        for tick in self.DBgraph.get_xticklabels():
            tick.set_rotation(15)
        self.fig4.canvas.draw()
        self.fig4.canvas.flush_events()
        
        # print(data)
        # print('')

#%%######################################################################################################    
    def UpdateTable(self, listdata):
        
        self.ui.tableWidget.setRowCount(len(listdata.keys()))
        self.ui.tableWidget.setHorizontalHeaderLabels(
            ['Name','Eff. (%)','FF (%)', 'Voc (mV)', 'Jsc (mA/cm2)','Isc (A)', 
             'Roc (ohm/cm2)', 'Rsc (ohm/cm2)', 'Pmpp (W/m2)', 'Vmpp (mV)', 'Jmpp (mA/cm2)'])
        i=0
        for key in listdata.keys():
            self.ui.tableWidget.setItem(i,0,QTableWidgetItem(listdata[key]['sampleID']))
            self.ui.tableWidget.setItem(i,1,QTableWidgetItem('%.2f' % listdata[key]['Eff']))
            self.ui.tableWidget.setItem(i,2,QTableWidgetItem('%.2f' % listdata[key]['FF']))
            self.ui.tableWidget.setItem(i,3,QTableWidgetItem('%.2f' % listdata[key]['Voc']))
            self.ui.tableWidget.setItem(i,4,QTableWidgetItem('%.2f' % listdata[key]['Jsc']))
            self.ui.tableWidget.setItem(i,5,QTableWidgetItem('%.2f' % listdata[key]['Isc']))
            self.ui.tableWidget.setItem(i,6,QTableWidgetItem('%.2f' % listdata[key]['Roc']))
            self.ui.tableWidget.setItem(i,7,QTableWidgetItem('%.2f' % listdata[key]['Rsc']))
            self.ui.tableWidget.setItem(i,8,QTableWidgetItem('%.2f' % listdata[key]['Pmpp']))
            self.ui.tableWidget.setItem(i,9,QTableWidgetItem('%.2f' % listdata[key]['Vmpp']))
            self.ui.tableWidget.setItem(i,10,QTableWidgetItem('%.2f' % listdata[key]['Jmpp']))   
            self.ui.tableWidget.setItem(i,11,QTableWidgetItem(listdata[key]['datetime'].toString(QtCore.Qt.ISODate)))
            i+=1
            
    def ClearTable(self):
        self.ui.tableWidget.setRowCount(0)
        
        
    def ClearGraph(self,All):
        # print('clear')
        if self.ui.comboBox_cleargraph.currentText()=='LIV' or All:
            self.JVgraph.clear()
            self.JVgraph.set_xlabel('Voltage (mV)')
            self.JVgraph.set_ylabel('Current density (mA/cm'+'\xb2'+')')
            self.JVgraph.axhline(y=0, color='k')
            self.JVgraph.axvline(x=0, color='k')
            self.fig1.canvas.draw_idle()
        if self.ui.comboBox_cleargraph.currentText()=='DIV' or All:
            self.DIVgraphlin.clear()
            self.DIVgraphlogY.clear()
            self.DIVgraphlin.set_xlabel('Voltage (mV)')
            self.DIVgraphlin.set_ylabel('Current density (mA/cm'+'\xb2'+')')
            self.DIVgraphlogY.set_yscale('log')
            self.DIVgraphlogY.set_xlabel('Voltage (mV)')
            self.DIVgraphlogY.set_ylabel('Current density (mA/cm'+'\xb2'+')')
            self.fig3.canvas.draw_idle()
        if self.ui.comboBox_cleargraph.currentText()=='MPPT' or All:
            self.MPPTgraph_JV.clear()
            self.MPPTgraph_JV.set_xlabel('Voltage (mV)')
            self.MPPTgraph_JV.set_ylabel('Current density (mA/cm'+'\xb2'+')')
            self.MPPTgraph_TV.clear()
            self.MPPTgraph_TV.set_xlabel('Time (s)')
            self.MPPTgraph_TV.set_ylabel('Voltage (mV)')
            self.MPPTgraph_TJ.clear()
            self.MPPTgraph_TJ.set_xlabel('Time (s)')
            self.MPPTgraph_TJ.set_ylabel('Current density (mA/cm'+'\xb2'+')')
            self.MPPTgraph_TP.clear()
            self.MPPTgraph_TP.set_xlabel('Time (s)')
            self.MPPTgraph_TP.set_ylabel('Power (W/m'+'\xb2'+')')
            self.fig2.canvas.draw_idle()

    def updateJVaftermeas(self,data):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        print('scan finished')
        pixcolor=self.pixcolor
        direction=self.direction
        pixels=self.pixels
        Rep=self.Rep
        directory=self.directory
        allpixtobemeasured=self.allpixtobemeasured
        currentlist=data[:,1]
        voltagelist=data[:,0]
        currentdenlist=[x*1000/self.pixarea for x in data[:,1]] #assume 1sun, and assume keithley gives Amperes back 
         
        if direction == 1:#forward scan 
            directionstr='fwd' 
            self.JVgraph.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
        elif direction == 0:#reverse scan 
            directionstr='rev' 
            self.JVgraph.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
        self.fig1.canvas.draw_idle() 
        polarity='pin'
        if self.ui.radioButton_nip.isChecked():
            polarity='nip'
        if shutteropen: 
            illum='lt' 
        else: 
            illum='dk' 
        if illum == 'dk': 
            if direction == 1:#forward scan 
                self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="dashed",color=pixcolor) 
            elif direction == 0:#reverse scan 
                self.DIVgraphlin.plot(data[:,0],currentdenlist, linestyle="solid",color=pixcolor) 
            ydataabs=list(map(lambda x: abs(x),currentdenlist)) 
            if direction == 1:#forward scan 
                self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="dashed",color=pixcolor) 
            elif direction == 0:#reverse scan 
                self.DIVgraphlogY.semilogy(data[:,0],ydataabs, linestyle="solid",color=pixcolor) 
            self.fig3.canvas.draw_idle() 
            self.fig3.canvas.flush_events() 
 
        self.fig1.canvas.flush_events() 
        
        if shutteropen:
            illum='lt'
            self.ClearGraph('LIV')
        else:
            illum='dk'
            self.ClearGraph('DIV')
        
        if self.ui.radioButton_Assume1sun.isChecked():
            radioButton_Assume1sun='True'
        else:
            radioButton_Assume1sun='False'
        timestr = QtCore.QDateTime.currentDateTime().toString(QtCore.Qt.ISODate)
        timestr=timestr.replace(':','').replace('-','')

        sample=str(self.ui.lineEdit_SampleName.text()) +'_'+  'pX'+self.currentpixelmeasured +'_'+ directionstr +'_'+ illum +'_'+ 'lp'+str(Rep) +'_'+ timestr  
        samplename=str(self.ui.lineEdit_SampleName.text()).replace('-','_')
        if '_' in str(self.ui.lineEdit_SampleName.text()):
            Batch=str(self.ui.lineEdit_SampleName.text()).split('_')[0]
            Substrate=str(self.ui.lineEdit_SampleName.text()).split('_')[1]
        else:
            Batch='None'
            Substrate='None'
        
        commenttext=str(self.ui.lineEdit_Comment.text())
        if aftermpp:
            if 'aftermpp' not in commenttext:
                commenttext+='_aftermpp'
        
        AllDATA[sample]={'sampleID': sample,'SampleNamePix': str(self.ui.lineEdit_SampleName.text()) +'_'+ self.currentpixelmeasured, 
                         'linktorawdata':str(os.path.join(str(directory),sample+'.txt')),'SampleName': samplename,'Batch#':Batch,'Substrate#':Substrate, 'Pixel':self.currentpixelmeasured, 'Allpixs':allpixtobemeasured,
                         'ScanDirection': directionstr, 'illum': illum, 'Sunintensity': Sunintensity, 'IsRefDiodeMeasured': RefDiodeChecked, 
                         'RefDiodeNomCurr':self.ui.doubleSpinBox_DiodeNominalCurrent.value(),'RefDiodeMeasCurr':self.ui.doubleSpinBox_MeasuredDiodeCurrent.value(),
                         'datetime': QtCore.QDateTime.currentDateTime(), 'Comment': commenttext,'temperature':self.ui.doubleSpinBox_Temperature.value(),
                         'UserName': str(self.ui.lineEdit_UserName.text()), 'MeasType': str(self.ui.comboBox_MeasType.currentText()),'MeasNowType': 'IV',
                         'pixcolor':pixcolor,'RepNumb': Rep,'DelayRep':self.ui.spinBox_RepDelay.value(), 'pixelArea': self.pixarea,'assume1sun':radioButton_Assume1sun,'ShutterOpen':shutteropen,
                         'MinVoltage': self.ui.doubleSpinBox_JVminvoltage.value(), 'MaxVoltage': self.ui.doubleSpinBox_JVmaxvoltage.value(),
                         'Aftermpp':aftermpp,'StepSize': self.ui.doubleSpinBox_JVstepsize.value(), 'CurrentLimit': self.ui.doubleSpinBox_JVcurrentlimit.value(), 
                         'IntegTime': self.ui.doubleSpinBox_JVintegrationtime.value(), 'Delaypts': self.ui.doubleSpinBox_JVdelaypoints.value(), 
                         'DelayShutter': self.ui.doubleSpinBox_JVdelayshutter.value(),'polarity':polarity,
                         'Voc': -1., 'Jsc': -1., 'Isc': -1., 'FF': -1., 'Eff': -1, 'Pmpp': -1., 'Roc':-1., 'Rsc':-1., 'Jmpp':-1, 'Vmpp':-1,
                         'Voltage':voltagelist,'Current':currentlist, 'CurrentDensity': currentdenlist
                         }
        lastmeasDATA[sample]=AllDATA[sample]

        self.AnalysisJV(sample)
        self.Savedata(sample,AllDATA)
        self.UpdateTable(lastmeasDATA)

class ThreadtakeIV(QThread):
    
    result = pyqtSignal(object)
    finished = pyqtSignal()
    
    def __init__(self, pixels, scandirections, keithleyObject, parent=None):
        QThread.__init__(self, parent)
        self.pixels = pixels
        self.scandirections=scandirections
        self.keithleyObject=keithleyObject
        
    def run(self):
        global STOPMEAS, AllDATA, lastmeasDATA,lastmeastrackingDATA, RefDiodeChecked, Sunintensity, shutteropen
        global aftermpp,boxCurrent, boxVoltage, keithleyAddress
        # print('scan')
        integtime=window.w.ui.doubleSpinBox_JVintegrationtime.value()
        # NPLC of 1 with 60Hz power, new value every 16.67ms
        # integtime=50ms => NPLC = .050*60 = 3
        NPLC=integtime*60/1000
        if NPLC>10:
            NPLC=10
        if NPLC<0.01:
            NPLC=0.01
        polarity='pin'
        if window.w.ui.radioButton_nip.isChecked():
            polarity='nip'
        currentlimit=window.w.ui.doubleSpinBox_JVcurrentlimit.value()
        prepareCurrent(self.keithleyObject, NPLC,currentlimit,polarity)#prepare to apply a voltage and measure a current

        for item in range(len(self.pixels)):
            connectPixel(boxCurrent, boxVoltage, self.pixels[item])
            
            for direction in self.scandirections:
                minV=window.w.ui.doubleSpinBox_JVminvoltage.value()/1000
                maxV=window.w.ui.doubleSpinBox_JVmaxvoltage.value()/1000
                stepV=window.w.ui.doubleSpinBox_JVstepsize.value()/1000
                delay=window.w.ui.doubleSpinBox_JVdelaypoints.value()

                data=takeIV(self.keithleyObject, minV,maxV,stepV,delay,direction,polarity,NPLC, currentlimit)

                if keithleyAddress=='Test':
                    QtTest.QTest.qWait(1000)
                
                data=[direction,item,data]
                self.result.emit(data)
                                
                if STOPMEAS==1:
                    break
            if STOPMEAS==1:
                break
            

        QtTest.QTest.qWait(10) # if this is not here, then the finished signal function finishes before the result signal function finishes, causing plotting problems
        self.finished.emit()
        
        
#%%######################################################################################################
class Window(QtWidgets.QDialog):
    def __init__(self):
        super().__init__()
        
        self.resize(607, 151)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.sizePolicy().hasHeightForWidth())
        self.setSizePolicy(sizePolicy)
        self.setMinimumSize(QtCore.QSize(430, 92))
        self.gridLayout = QtWidgets.QGridLayout(self)
        self.setWindowTitle("Will you choose the Red or the Blue pill?")
        self.pushButton_Simulation = QtWidgets.QPushButton("Do you want to work without connection to the keithley?", self)
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(120, 120, 120))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.ButtonText, brush)
        self.pushButton_Simulation.setPalette(palette)
        self.pushButton_Simulation.setObjectName("pushButton_Simulation")
        self.gridLayout.addWidget(self.pushButton_Simulation, 3, 0, 1, 2)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 4, 0, 1, 1)
        self.pushButton_Reality = QtWidgets.QPushButton("Do you want to see the reality and actually measure devices with a keithley?", self)
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(255, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(120, 120, 120))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.ButtonText, brush)
        self.pushButton_Reality.setPalette(palette)
        self.pushButton_Reality.setObjectName("pushButton_Reality")
        self.gridLayout.addWidget(self.pushButton_Reality, 2, 0, 1, 2)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem1, 1, 0, 1, 1)

        
        self.pushButton_Reality.clicked.connect(self.MainReal)   
        self.pushButton_Simulation.clicked.connect(self.MainSimul)

        self.show()

    def MainReal(self): 
        global boxCurrent, boxVoltage, keithleyAddress, connectPixel
        sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)),'Advantech Code'))
        from pixelControl import connectPixel 
        sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)),'Advantech Code'))
        import pyDAQNavi as pDN
        boxCurrent = pDN.DeviceObject('USB-4761,BID#0')
        boxVoltage = pDN.DeviceObject('USB-4761,BID#1')
        # Depending on which Keithley is connected to the Solar Sim, the address may change.
        # keithleyAddress='GPIB0::22::INSTR'
        keithleyAddress='GPIB0::23::INSTR'

        self.w = Main()
        self.w.show()
        self.hide()
        
    def MainSimul(self):

        self.w = Main()
        self.w.show()
        self.hide()
    
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = Window()
    sys.exit(app.exec())