# -*- coding: utf-8 -*-
"""
Created on Sun Apr  5 15:25:03 2020

@author: jpatel
"""

import DAQNavi

pixelName='all'
                             
def connectPixel(pixelName):
    '''
    function description
    convert pixel letter into relay config for both boxes
    write config to boxCurrent write boxVoltage
    '''
    switcher = {
        'off':0b00000000,
        'a': 0b00000001, 
        'b': 0b00000010, 
        'c': 0b00000100,
        'd': 0b00001000, 
        'e': 0b00010000, 
        'f': 0b00100000,
        'all':0b11111111,
                        } 
    
    
    return switcher.get(pixelName)
    
   # print connectPixel (pixelName) 
    
if __name__ == "__main__":
    boxCurrent = DAQNavi.DeviceObject('USB-4761,BID#0')
    boxVoltage = DAQNavi.DeviceObject('USB-4761,BID#1')
    #DAQNavi.writeDeviceState(boxCurrent, 0b00000001)
    DAQNavi.writeDeviceState(boxCurrent, connectPixel(pixelName))
    DAQNavi.writeDeviceState(boxVoltage, connectPixel(pixelName))
