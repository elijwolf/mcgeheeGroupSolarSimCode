'''
Copy the following code so that you can import DAQNavi.py properly.
You do not need to copy any code that is commented out, including this block.
'''

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

import pyDAQNavi

# demoDevice1 = pyDAQNavi.DeviceObject('DemoDevice,BID#0')