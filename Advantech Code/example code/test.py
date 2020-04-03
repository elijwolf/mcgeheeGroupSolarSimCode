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
		self.cDeviceInfo.DeviceMode = bdaqctrl.ModeWriteWithReset
		self.cDeviceInfo.ModuleIndex = 0

		self.cret = bdaqctrl.InstantDoCtrl_setSelectedDevice(self.cDeviceStruct,self.cDeviceInfo)
		print ()
		print ('Attempting device connect.')
		print (devDesc)
		errorCheck(self.cret)

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
	bdaqctrl.InstantDoCtrl_Dispose(deviceObject)

if __name__ == "__main__":
	demoDevice1 = DeviceObject('DemoDevice,BID#0')
	demoDevice2 = DeviceObject('DemoDevice,BID#1')
	readDeviceState(demoDevice1)
	readDeviceState(demoDevice2)
	writeDeviceState(demoDevice1,0b11110000)
	writeDeviceState(demoDevice2,0b00001111)
	readDeviceState(demoDevice1)
	readDeviceState(demoDevice2)