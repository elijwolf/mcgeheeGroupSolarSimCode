import sys
import os
import traceback
import pandas as pd
import numpy as np
from scipy.interpolate import interp1d as interp
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),'GUIfiles'))
######################################################################################################
import matplotlib
matplotlib.use("Qt5Agg")
######################################################################################################
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtWidgets import QFileDialog
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
from matplotlib.figure import Figure
######################################################################################################

from gui import Ui_MainWindow  #need to comment out all lines containing "PlaceholderText"
from loadingsavingtemplate import LoadParamTemplate, SaveParamTemplate

class Main(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        QtWidgets.QMainWindow.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        
        fig1 = Figure()
        self.JVgraph = fig1.add_subplot(111)
        self.JVgraph.set_xlabel('Voltage (mV)')
        self.JVgraph.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.JVgraph.axhline(y=0, color='k')
        self.JVgraph.axvline(x=0, color='k')
        self.addmplJV(fig1)
        
        fig2 = Figure()
        self.MPPTgraph_JV = fig2.add_subplot(221)
        self.MPPTgraph_JV.set_xlabel('Voltage (mV)')
        self.MPPTgraph_JV.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.MPPTgraph_TV = fig2.add_subplot(222)
        self.MPPTgraph_TV.set_xlabel('Time (s)')
        self.MPPTgraph_TV.set_ylabel('Voltage (mV)')
        self.MPPTgraph_TJ = fig2.add_subplot(223)
        self.MPPTgraph_TJ.set_xlabel('Time (s)')
        self.MPPTgraph_TJ.set_ylabel('Current density (mA/cm'+'\xb2'+')')
        self.MPPTgraph_TP = fig2.add_subplot(224)
        self.MPPTgraph_TP.set_xlabel('Time (s)')
        self.MPPTgraph_TP.set_ylabel('Power (W/m'+'\xb2'+')')
        self.addmplMPPT(fig2)
        
        for item0 in [self.JVgraph,self.MPPTgraph_JV,self.MPPTgraph_TV,self.MPPTgraph_TJ,self.MPPTgraph_TP]:
            for item in ([item0.title, item0.xaxis.label, item0.yaxis.label] +
                         item0.get_xticklabels() + item0.get_yticklabels()):
                item.set_fontsize(12)
                
                
        self.ui.actionLoad_settings.triggered.connect(lambda: LoadParamTemplate(self))
        self.ui.actionSave_settings.triggered.connect(lambda: SaveParamTemplate(self))
        
    def addmplJV(self, fig):
        self.canvas = FigureCanvas(fig)
        self.ui.gridLayout_MPLwidgetJV.addWidget(self.canvas)
        self.canvas.draw()
        self.toolbar = NavigationToolbar(self.canvas, 
                self.ui.MPLwidgetJV, coordinates=True)
        self.ui.gridLayout_MPLwidgetJV.addWidget(self.toolbar)
                
    def addmplMPPT(self, fig):
        self.canvas = FigureCanvas(fig)
        self.ui.gridLayout_MPLwidgetMPPT.addWidget(self.canvas)
        self.canvas.draw()
        self.toolbar = NavigationToolbar(self.canvas, 
                self.ui.MPLwidgetMPPT, coordinates=True)
        self.ui.gridLayout_MPLwidgetMPPT.addWidget(self.toolbar)  
        

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    theapp = Main()
    theapp.show()
    sys.exit(app.exec_())

