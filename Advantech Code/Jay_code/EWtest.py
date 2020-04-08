import os
import sys

def findLabCodePath(myPath):
	'''
	This function is used so that python can find important modules regardless of where the main script is run from.
	The main script must be run from anywhere inside the labCode folder.
	'''
	myPath = os.path.abspath(myPath)
	# print (path)
	# print (os.path.basename(path))
	# print ()
	if os.path.basename(myPath) == 'labCode':
		# print ('Done')
		return myPath
	else:
		myPath = findLabCodePath(os.path.normpath(os.path.join(myPath,'..')))
		return myPath

labCodePath = findLabCodePath(__file__)

sys.path.insert(0, os.path.join(labCodePath,'Advantech Code'))
import pyDAQNavi as pDN

sys.path.insert(0, os.path.join(labCodePath,'Advantech Code','Jay_code'))
import pixelControl as pC

sys.path.insert(0, os.path.join(labCodePath,'Keithley Code'))
import myKeithleyFunctions as mKF

