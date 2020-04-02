from PyQt5.QtWidgets import QFileDialog
from PyQt5 import QtCore


def LoadParamTemplate(self):
    '''
    ask user to select a template file to fill everything with presaved parameters
    '''      
    
    fname = QFileDialog.getOpenFileName(self, 'Open file', 'c:\\',"Text files (*.txt)")
    with open(fname[0],'r') as file:
        for line in file:
            if 'UserName' in line:
                self.ui.lineEdit_UserName.setText(line.split('\t')[1])
            elif 'SampleName' in line:
                self.ui.lineEdit_SampleName.setText(line.split('\t')[1])
            elif 'Comment' in line:
                self.ui.lineEdit_Comment.setText(line.split('\t')[1])
            elif 'Meas. type' in line:
                index = self.ui.comboBox_MeasType.findText(line.split('\t')[1][:-1], QtCore.Qt.MatchFixedString)
                if index >= 0:
                     self.ui.comboBox_MeasType.setCurrentIndex(index)
            elif 'WhichPixel' in line:
                index = self.ui.comboBox_WhichPixel.findText(line.split('\t')[1][:-1], QtCore.Qt.MatchFixedString)
                if index >= 0:
                     self.ui.comboBox_WhichPixel.setCurrentIndex(index)
            elif '#rep' in line:
                self.ui.spinBox_RepNumb.setValue(float(line.split('\t')[1]))
            elif 'DelayRep' in line:
                self.ui.spinBox_RepDelay.setValue(float(line.split('\t')[1]))
            elif 'Diode1sun' in line:
                self.ui.doubleSpinBox_Diode1sunVoltage.setValue(float(line.split('\t')[1]))
            elif 'mismatchfactor' in line:
                self.ui.doubleSpinBox_MismatchFactor.setValue(float(line.split('\t')[1]))
            elif 'temperature' in line:
                self.ui.doubleSpinBox_Temperature.setValue(float(line.split('\t')[1]))
            elif 'minvoltage' in line:
                self.ui.doubleSpinBox_JVminvoltage.setValue(float(line.split('\t')[1]))
            elif 'maxvoltage' in line:
                self.ui.doubleSpinBox_JVmaxvoltage.setValue(float(line.split('\t')[1]))
            elif 'JVstepsize' in line:
                self.ui.doubleSpinBox_JVstepsize.setValue(float(line.split('\t')[1]))
            elif 'currentlimit' in line:
                self.ui.doubleSpinBox_JVcurrentlimit.setValue(float(line.split('\t')[1]))
            elif 'integtime' in line:
                self.ui.doubleSpinBox_JVintegrationtime.setValue(float(line.split('\t')[1]))
            elif 'delaypoints' in line:
                self.ui.doubleSpinBox_JVdelaypoints.setValue(float(line.split('\t')[1]))
            elif 'delayshutter' in line:
                self.ui.doubleSpinBox_JVdelayshutter.setValue(float(line.split('\t')[1]))
            elif 'scandirection' in line:
                index = self.ui.comboBox_JVscandirection.findText(line.split('\t')[1][:-1], QtCore.Qt.MatchFixedString)
                if index >= 0:
                     self.ui.comboBox_JVscandirection.setCurrentIndex(index)
            elif 'startvoltage' in line:
                self.ui.doubleSpinBox_MPPTstartvoltage.setValue(float(line.split('\t')[1]))
            elif 'MPPTstepsize' in line:
                self.ui.spinBox_MPPTstepsize.setValue(float(line.split('\t')[1]))
            elif 'voltagelimit' in line:
                self.ui.doubleSpinBox_MPPTvoltagelimit.setValue(float(line.split('\t')[1]))
            elif 'delaypointsmpp' in line:
                self.ui.doubleSpinBox_MPPTdelaypoints.setValue(float(line.split('\t')[1]))
            elif 'lighton' in line:
                self.ui.checkBox_MPPTlighton.setChecked(eval(line.split('\t')[1]))
            elif 'keeplightafter' in line:
                self.ui.checkBox_MPPTlightonafter.setChecked(eval(line.split('\t')[1]))
            elif 'PixelA' in line:
                self.ui.checkBox_pixA.setChecked(eval(line.split('\t')[1]))
            elif 'PixelB' in line:
                self.ui.checkBox_pixB.setChecked(eval(line.split('\t')[1]))
            elif 'PixelC' in line:
                self.ui.checkBox_pixC.setChecked(eval(line.split('\t')[1]))
            elif 'PixelD' in line:
                self.ui.checkBox_pixD.setChecked(eval(line.split('\t')[1]))
            elif 'PixelE' in line:
                self.ui.checkBox_pixE.setChecked(eval(line.split('\t')[1]))
            elif 'PixelF' in line:
                self.ui.checkBox_pixF.setChecked(eval(line.split('\t')[1]))
            elif 'A-area' in line:
                self.ui.doubleSpinBox_pixAarea.setValue(float(line.split('\t')[1]))
            elif 'B-area' in line:
                self.ui.doubleSpinBox_pixBarea.setValue(float(line.split('\t')[1]))
            elif 'C-area' in line:
                self.ui.doubleSpinBox_pixCarea.setValue(float(line.split('\t')[1]))
            elif 'D-area' in line:
                self.ui.doubleSpinBox_pixDarea.setValue(float(line.split('\t')[1]))
            elif 'E-area' in line:
                self.ui.doubleSpinBox_pixEarea.setValue(float(line.split('\t')[1]))
            elif 'F-area' in line:
                self.ui.doubleSpinBox_pixFarea.setValue(float(line.split('\t')[1]))
            elif 'Allpix' in line:
                self.ui.radioButton_pixAll.setChecked(eval(line.split('\t')[1]))
    

def SaveParamTemplate(self):
    '''
    ask user to select a template file to save all parameters
    '''
    if self.ui.checkBox_MPPTlighton.isChecked():
        checkBox_MPPTlighton='True'
    else:
        checkBox_MPPTlighton='False'
    if self.ui.checkBox_MPPTlightonafter.isChecked():
        checkBox_MPPTlightonafter='True'
    else:
        checkBox_MPPTlightonafter='False'
    if self.ui.checkBox_pixA.isChecked():
        checkBox_pixA='True'
    else:
        checkBox_pixA='False'
    if self.ui.checkBox_pixB.isChecked():
        checkBox_pixB='True'
    else:
        checkBox_pixB='False'
    if self.ui.checkBox_pixC.isChecked():
        checkBox_pixC='True'
    else:
        checkBox_pixC='False'
    if self.ui.checkBox_pixD.isChecked():
        checkBox_pixD='True'
    else:
        checkBox_pixD='False'
    if self.ui.checkBox_pixE.isChecked():
        checkBox_pixE='True'
    else:
        checkBox_pixE='False'
    if self.ui.checkBox_pixF.isChecked():
        checkBox_pixF='True'
    else:
        checkBox_pixF='False'
    if self.ui.radioButton_pixAll.isChecked():
        radioButton_pixAll='True'
    else:
        radioButton_pixAll='False'
    
    fname = QFileDialog.getSaveFileName(self, 'Save file', 'c:\\',"Text files (*.txt)")
    with open(fname[0],'w') as file:
        text='UserName\t'+ str(self.ui.lineEdit_UserName.text())+\
            'SampleName\t'+ str(self.ui.lineEdit_SampleName.text())+\
            'Comment\t'+str(self.ui.lineEdit_Comment.text())+\
            'Meas. type\t'+ str(self.ui.comboBox_MeasType.currentText())+'\n'+\
            'WhichPixel\t'+ str(self.ui.comboBox_WhichPixel.currentText())+'\n'+\
            '#rep\t'+ str(self.ui.spinBox_RepNumb.value())+'\n'+\
            'DelayRep\t'+ str(self.ui.spinBox_RepDelay.value())+'\n'+\
            '\n'+\
            'Diode1sun\t'+ str(self.ui.doubleSpinBox_Diode1sunVoltage.value())+'\n'+\
            'mismatchfactor\t'+ str(self.ui.doubleSpinBox_MismatchFactor.value())+'\n'+\
            'temperature\t'+ str(self.ui.doubleSpinBox_Temperature.value())+'\n'+\
            '\n'+\
            'minvoltage\t'+ str(self.ui.doubleSpinBox_JVminvoltage.value())+'\n'+\
            'maxvoltage\t'+ str(self.ui.doubleSpinBox_JVmaxvoltage.value())+'\n'+\
            'JVstepsize\t'+ str(self.ui.doubleSpinBox_JVstepsize.value())+'\n'+\
            'currentlimit\t'+ str(self.ui.doubleSpinBox_JVcurrentlimit.value())+'\n'+\
            'integtime\t'+ str(self.ui.doubleSpinBox_JVintegrationtime.value())+'\n'+\
            'delaypoints\t'+ str(self.ui.doubleSpinBox_JVdelaypoints.value())+'\n'+\
            'delayshutter\t'+ str(self.ui.doubleSpinBox_JVdelayshutter.value())+'\n'+\
            'scandirection\t'+ str(self.ui.comboBox_JVscandirection.currentText())+'\n'+\
            '\n'+\
            'startvoltage\t'+ str(self.ui.doubleSpinBox_MPPTstartvoltage.value())+'\n'+\
            'MPPTstepsize\t'+ str(self.ui.spinBox_MPPTstepsize.value())+'\n'+\
            'voltagelimit\t'+ str(self.ui.doubleSpinBox_MPPTvoltagelimit.value())+'\n'+\
            'delaypointsmpp\t'+ str(self.ui.doubleSpinBox_MPPTdelaypoints.value())+'\n'+\
            'lighton\t'+checkBox_MPPTlighton +'\n'+\
            'keeplightafter\t'+checkBox_MPPTlightonafter +'\n'+\
            '\n'+\
            'PixelA\t'+checkBox_pixA +'\n'+\
            'PixelB\t'+checkBox_pixB +'\n'+\
            'PixelC\t'+checkBox_pixC +'\n'+\
            'PixelD\t'+checkBox_pixD +'\n'+\
            'PixelE\t'+checkBox_pixE +'\n'+\
            'PixelF\t'+checkBox_pixF +'\n'+\
            'A-area\t'+ str(self.ui.doubleSpinBox_pixAarea.value())+'\n'+\
            'B-area\t'+ str(self.ui.doubleSpinBox_pixBarea.value())+'\n'+\
            'C-area\t'+ str(self.ui.doubleSpinBox_pixCarea.value())+'\n'+\
            'D-area\t'+ str(self.ui.doubleSpinBox_pixDarea.value())+'\n'+\
            'E-area\t'+ str(self.ui.doubleSpinBox_pixEarea.value())+'\n'+\
            'F-area\t'+ str(self.ui.doubleSpinBox_pixFarea.value())+'\n'+\
            'Allpix\t'+ radioButton_pixAll
        
        file.write(text)
