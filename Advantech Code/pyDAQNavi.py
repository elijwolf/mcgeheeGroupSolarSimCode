# Python Imports

from cffi import FFI
import sys

# C Magic
ffibuilder = FFI()

with open("_bdaqctrl.h") as fin:
	ffibuilder.cdef(fin.read())

bdaqctrl = ffibuilder.dlopen("biodaq.dll")

# Python Functions and Classes for Interaction
class DeviceObject:
	def __init__(self, devDesc):
		self.cDeviceStruct = bdaqctrl.AdxInstantDoCtrlCreate()
		self.cDeviceInfo = ffibuilder.new("DeviceInformation *")
		self.deviceDescription = devDesc

		self.cDeviceInfo.Description = devDesc
		self.cDeviceInfo.DeviceNumber = -1
		# self.cDeviceInfo.DeviceMode = bdaqctrl.ModeWrite #This leaves the relay in its original state when being initialized
		self.cDeviceInfo.DeviceMode = bdaqctrl.ModeWriteWithReset #This sets the device to 0b00000000 when initialized
		self.cDeviceInfo.ModuleIndex = 0

		self.cret = bdaqctrl.InstantDoCtrl_setSelectedDevice(self.cDeviceStruct,self.cDeviceInfo)
		print ()
		print ('Attempting device connect.')
		print (devDesc)
		errorCheck(self.cret)

	def __del__(self):
		writeDeviceState(self,0b00000000) #When about to shut down the device is set to 0b00000000.
		disconnectDevice(self)

def readDeviceState(deviceObject):
	cstate = ffibuilder.new("uint8 *")
	cret = bdaqctrl.InstantDoCtrl_ReadAny(deviceObject.cDeviceStruct,0,1,cstate)
	print ()
	print ('Attempting device read.')
	print (deviceObject.deviceDescription)
	errorCheck(cret)
	state = cstate[0]
	print ('Relay state is {0:08b}'.format(state))
	return state

def writeDeviceState(deviceObject,state):
	cstate = ffibuilder.new("uint8 *", state)
	cret = bdaqctrl.InstantDoCtrl_WriteAny(deviceObject.cDeviceStruct,0,1,cstate)
	print ()
	print ('Attempting device write.')
	print (deviceObject.deviceDescription)
	print ('{:08b}'.format(state))
	errorCheck(cret)
	readDeviceState(deviceObject)
	return

def errorCheck(cret):
	try:
		assert bdaqctrl.Success == cret
		print ('Success!')
	except:
		print ('Device Error')
		print ('{:02X}'.format(cret))
		sys.exit()
	return

def disconnectDevice(deviceObject):
	print ('')
	print ('Attempting device disconnect.')
	bdaqctrl.InstantDoCtrl_Dispose(deviceObject.cDeviceStruct)
	print ('Success')

if __name__ == "__main__":
	# demoDevice1 = DeviceObject('USB-4761,BID#0')
	# demoDevice1 = DeviceObject('USB-4761,BID#1')

	demoDevice1 = DeviceObject('DemoDevice,BID#0')
	demoDevice2 = DeviceObject('DemoDevice,BID#1')
	readDeviceState(demoDevice1)
	readDeviceState(demoDevice2)
	writeDeviceState(demoDevice1,0b11110000)
	writeDeviceState(demoDevice2,0b00001111)
	readDeviceState(demoDevice1)
	readDeviceState(demoDevice2)