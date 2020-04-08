# -*- coding: utf-8 -*-
"""
Created on Sun Apr  5 15:25:03 2020

@author: jpatel
"""

import os
import sys

def findDAQNaviPath(myPath):
	'''
	This function is used so that python can find DAQNavi.py regardless of where the main script is run from.
	The main script must be run from inside the labCode folder.
	'''
	myPath = os.path.abspath(myPath)
	# print (path)
	# print (os.path.basename(path))
	# print ()
	if os.path.basename(myPath) == 'labCode':
		# print ('Done')
		return os.path.join(myPath,'Advantech Code')
	else:
		myPath = findDAQNaviPath(os.path.normpath(os.path.join(myPath,'..')))
		return myPath

sys.path.insert(0, findDAQNaviPath(__file__))

import pyDAQNavi as pDN

pixelName='all'
                             
def connectPixel(box1, box2, pixelName):
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
        # 'all':0b11111111,
                        } 
    
    
    pixelConfig = switcher[pixelName]
    # print (pixelConfig)
    pDN.writeDeviceState(box1, pixelConfig)
    pDN.writeDeviceState(box2, pixelConfig)
    
   # print connectPixel (pixelName) 
    
if __name__ == "__main__":
    # boxCurrent = pDN.DeviceObject('USB-4761,BID#0')
    # boxVoltage = pDN.DeviceObject('USB-4761,BID#1')
    boxCurrent = pDN.DeviceObject('DemoDevice,BID#0')
    boxVoltage = pDN.DeviceObject('DemoDevice,BID#1')
    #pDN.writeDeviceState(boxCurrent, 0b00000001)
    connectPixel(boxCurrent, boxVoltage, 'a')
