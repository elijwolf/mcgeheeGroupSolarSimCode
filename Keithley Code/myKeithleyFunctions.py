import pyvisa
import sys
import numpy as np

#####TO-DO#####
'''
- find out if you can use wait_for_srq or wai
- determine Digital Output configuration required to open and close the shutter. The functions currently work, but the output configuration is a guess.
'''
###############
def connectToKeithley(keithleyAddress='GPIB0::22::INSTR'):
	'''
	This creates a Keithley object with which to interact with.
	Attempt to connect to a Keithley, then send an ID query to confirm connection. If this fails, send an error message to the terminal and terminate the program.
	'''
	if keithleyAddress=='Test':
		print ('Keithley Code running in Test Mode. All of the following data is generated not measured.')
		from scipy.interpolate import interp1d as interp
		global datetime
		import datetime
		global time
		import time
		global sleepTime
		sleepTime = 0.001
		global start
		start = datetime.datetime.now()
		global k
		k = 8.617e-5
		global T0
		T0 = 273.15
		global Iph
		Iph = 0

		def testIV(V,Iph,I0=1e-9,T=25,VF=1.2,VR=1,V0=0.56):
			I = -Iph + I0*(np.exp((V-VF+V0)/(k*(T+T0)))-1) + 0.01*np.random.uniform(-1,1)
			return I

		def testIVinv(I,Iph,I0=1e-9,T=25,VF=1.2,VR=1,V0=0.56):
			V = k*(T+T0)*np.log(1+((I+Iph)/I0)) + 0.001*np.random.uniform(-1,1)
			return V

		global getI
		getI = testIV

		global getV
		getV = testIVinv

		return keithleyAddress

	try:
		rm = pyvisa.ResourceManager()
		# print(rm.list_resources())
		print ('Attempting to connect to keithley.')
		keithleyObject = rm.open_resource(keithleyAddress)
		print (keithleyObject.query('*IDN?'))
		# keithleyObject.timeout = 100000
		keithleyObject.write('*RST')
		keithleyObject.write('SENS:FUNC:CONC OFF')
	except:
		print ('Could not establish connection with Keithley.')
		print ('Check connection with Keithley')
		sys.exit()
	return keithleyObject

def prepareVoltage(keithleyObject, NPLC=1):
	'''
	Prepares the Keithley to measure voltage.
	NPLC Range [0.01,10]
	'''
	if keithleyObject == 'Test':
		return
	keithleyObject.write('SOUR:FUNC CURR')
	keithleyObject.write('SOUR:CURR:MODE FIXED')
	keithleyObject.write('SOUR:CURR:RANG:AUTO ON')
	keithleyObject.write('SENS:FUNC "VOLT"')
	keithleyObject.write('SENS:VOLT:PROT 10')
	keithleyObject.write('SENS:VOLT:RANG:AUTO ON')
	keithleyObject.write('SENS:VOLT:NPLC {:.3f}'.format(NPLC))
	keithleyObject.write('OUTP ON')

def measureVoltage(keithleyObject, current=0, n=1):
	'''
	Sets the current and measures voltage n times.
	'''
	if keithleyObject == 'Test':
		time.sleep(sleepTime)
		timeStamp = (datetime.datetime.now()-start).total_seconds()
		simVolt = getV(current,Iph)
		rawData = np.array([simVolt,current,9.91e+37, timeStamp, 0b00000000])
		rawDataArray = np.array(rawData)
		for i in range(n-1):
			time.sleep(sleepTime)
			timeStamp = (datetime.datetime.now()-start).total_seconds()
			simVolt = getV(current,Iph)
			rawData = np.array([simVolt,current,9.91e+37, timeStamp, 0b00000000])
			rawDataArray = np.vstack((rawDataArray,rawData))
		data = rawDataArray
		return data
	keithleyObject.write('SOUR:CURR:LEV {:.3f}'.format(current))
	rawData = keithleyObject.query_ascii_values('READ?')
	rawDataArray = np.array(rawData)
	for i in range(n-1):
		rawData = keithleyObject.query_ascii_values('READ?')
		rawDataArray = np.vstack((rawDataArray,rawData))
	data = rawDataArray
	return data

def prepareCurrent(keithleyObject, NPLC=1):
	'''
	Prepares the Keithley to measure current.
	NPLC Range [0.01,10]
	'''
	if keithleyObject == 'Test':
		return
	keithleyObject.write('SOUR:FUNC VOLT')
	keithleyObject.write('SOUR:VOLT:MODE FIXED')
	keithleyObject.write('SOUR:VOLT:RANG:AUTO ON')
	keithleyObject.write('SENS:FUNC "CURR"')
	keithleyObject.write('SENS:CURR:PROT 10E-2')
	keithleyObject.write('SENS:CURR:RANG:AUTO ON')
	keithleyObject.write('SENS:CURR:NPLC {:.3f}'.format(NPLC))
	keithleyObject.write('OUTP ON')

def measureCurrent(keithleyObject, voltage=0, n=1):
	'''
	Sets the voltage and measures current n times.
	'''
	if keithleyObject == 'Test':
		time.sleep(sleepTime)
		timeStamp = (datetime.datetime.now()-start).total_seconds()
		simCurrent = getI(voltage,Iph)
		rawData = np.array([voltage,simCurrent,9.91e+37, timeStamp, 0b00000000])
		rawDataArray = np.array(rawData)
		for i in range(n-1):
			time.sleep(sleepTime)
			timeStamp = (datetime.datetime.now()-start).total_seconds()
			simCurrent = getI(voltage,Iph)
			rawData = np.array([voltage,simCurrent,9.91e+37, timeStamp, 0b00000000])
			rawDataArray = np.vstack((rawDataArray,rawData))
		data = rawDataArray
		return data
	keithleyObject.write('SOUR:VOLT:LEV {:.3f}'.format(voltage))
	rawData = keithleyObject.query_ascii_values('READ?')
	rawDataArray = np.array(rawData)
	for i in range(n-1):
		rawData = keithleyObject.query_ascii_values('READ?')
		rawDataArray = np.vstack((rawDataArray,rawData))
	data = rawDataArray
	return data

def openShutter(keithleyObject):
	'''
	Opens the Solar Sim shutter to allow light through and illuminate a device.
	'''
	if keithleyObject == 'Test':
		global Iph
		Iph = 20
		return
	keithleyObject.write('SOUR2:TTL {:d}'.format(0b1111))

def closeShutter(keithleyObject):
	'''
	Closes the Solar Sim shutter to block light and prevent illumination of a device.
	'''
	if keithleyObject == 'Test':
		global Iph
		Iph = 0
		return
	keithleyObject.write('SOUR2:TTL {:d}'.format(0b0000))

def takeIV(keithleyObject, startV=-0.2, stopV=1.2, stepV=0.1, delay=0.01, rev=0, NPLC = 1):
	'''
	This takes an IV sweep. startV must be less than stopV.
	Returns an (n,5) numpy array.
	Columns are...
	[Voltage,Current,Resistance,Time,Status]
	Resistance is noramlly disabled and will result in all values in the third column be equal to 9.91e+37.
	See Keithley manual for the explanatoin of the value of status.
	NPLC Range [0.01,10]
	'''
	if rev != 0:
		startV, stopV = stopV, startV
		stepV *= -1

	if keithleyObject == 'Test':
		volts = np.arange(startV, stopV+stepV, stepV)
		global start
		start = datetime.datetime.now()
		timeStamp = (datetime.datetime.now()-start).total_seconds()
		simCurrent = getI(volts[0],Iph)
		rawData = np.array([volts[0],simCurrent,9.91e+37, timeStamp, 0b00000000])
		rawDataArray = np.array(rawData)
		for volt in volts[1:]:
			time.sleep(sleepTime)
			timeStamp = (datetime.datetime.now()-start).total_seconds()
			simCurrent = getI(volt,Iph)
			rawData = np.array([volt,simCurrent,9.91e+37, timeStamp, 0b00000000])
			rawDataArray = np.vstack((rawDataArray,rawData))
		data = rawDataArray
		return data

	n = round(1 + (stopV - startV) / stepV)
	keithleyObject.timeout = 100000
	keithleyObject.write('SOUR:FUNC VOLT')
	keithleyObject.write('SOUR:VOLT:STAR {:.3f}'.format(startV))
	keithleyObject.write('SOUR:VOLT:STOP {:.3f}'.format(stopV))
	keithleyObject.write('SOUR:VOLT:STEP {:.3f}'.format(stepV))
	keithleyObject.write('SOUR:VOLT:MODE SWE')
	keithleyObject.write('SOUR:SWE:RANG AUTO')
	keithleyObject.write('SOUR:SWE:SPAC LIN')
	keithleyObject.write('SOUR:SWE:POIN {:d}'.format(n))
	keithleyObject.write('SOUR:DEL {:.3f}'.format(delay))
	keithleyObject.write('SENS:FUNC "CURR"')
	keithleyObject.write('SENS:CURR:PROT 100E-3')
	keithleyObject.write('SENS:CURR:NPLC {:.3f}'.format(NPLC))
	keithleyObject.write('TRIG:COUN {:d}'.format(n))
	keithleyObject.write('SYST:TIME:RES')
	keithleyObject.write('OUTP ON')
	rawData = keithleyObject.query_ascii_values('READ?')
	data = np.reshape(rawData, (-1,5))
	return data

def shutdownKeithley(keithleyObject):
	if keithleyObject == 'Test':
		return
	keithleyObject.write('OUTP OFF')

if __name__ == "__main__":

	import matplotlib.pyplot as plt

	# rm = pyvisa.ResourceManager()
	# print(rm.list_resources())

	# keithley = connectToKeithley('GPIB0::22::INSTR')
	keithley = connectToKeithley('Test')
	
	openShutter(keithley)
	closeShutter(keithley)

	prepareCurrent(keithley, NPLC = 2)
	dataCurrent = measureCurrent(keithley,voltage=0.001,n=10)
	# print (type(dataCurrent))
	# print (dataCurrent.shape)
	# print (type(dataCurrent[0]))
	# print (dataCurrent[0].shape)
	# print (type(dataCurrent[0][0]))
	# print (type(dataCurrent[0][1]))
	# print (type(dataCurrent[0][2]))
	# print (type(dataCurrent[0][3]))
	# print (type(dataCurrent[0][4]))

	prepareVoltage(keithley)
	dataVoltage = measureVoltage(keithley,current=0.001,n=9)
	# print (type(dataVoltage))
	# print (dataVoltage.shape)
	# print (type(dataVoltage[0]))
	# print (dataVoltage[0].shape)
	# print (type(dataVoltage[0][0]))
	# print (type(dataVoltage[0][1]))
	# print (type(dataVoltage[0][2]))
	# print (type(dataVoltage[0][3]))
	# print (type(dataVoltage[0][4]))

	plt.figure('Voltage')
	# print (dataVoltage.shape)
	# print (dataVoltage.shape[0])
	xs = np.arange(dataVoltage.shape[0])
	plt.plot(xs,dataVoltage[:,0])

	plt.figure('Current')
	xs = np.arange(dataCurrent.shape[0])
	plt.plot(xs,dataCurrent[:,1])


	#This section of code tests the takeIV function and plots it.
	openShutter(keithley)
	data = takeIV(keithley, NPLC = 0.01)
	# print (type(data))
	# print (data.shape)
	# print (type(data[0]))
	# print (data[0].shape)
	# print (type(data[0][0]))
	# print (type(data[0][1]))
	# print (type(data[0][2]))
	# print (type(data[0][3]))
	# print (type(data[0][4]))
	volt = data[:,0]
	current = data[:,1]
	# c = data[:,2]
	# d = data[:,3]
	# e = data[:,4]
	data1 = takeIV(keithley, rev=1)
	volt1 = data1[:,0]
	current1 = data1[:,1]
	# # c1 = data[:,2]
	# # d1 = data[:,3]
	# # e1 = data[:,4]
	closeShutter(keithley)
	dataDark = takeIV(keithley, rev=1)
	voltDark = dataDark[:,0]
	currentDark = dataDark[:,1]
	# # c1 = data[:,2]
	# # d1 = data[:,3]
	# # e1 = data[:,4]
	plt.figure('Sweep')
	# plt.plot(volt,volt, label = 'Volts')
	plt.plot(volt,current, label = 'Jsc->Voc')
	plt.plot(volt1,current1, label = 'Voc->Jsc')
	# plt.plot(volt,c, label = 'Resistance') #This is noramlly disabled and will result in all values equal to 9.91e+37
	# plt.plot(volt,d, label = 'Time')
	# plt.plot(volt,e, label = 'Status')

	plt.plot(voltDark,currentDark, label = 'Dark')
	
	shutdownKeithley(keithley)
	plt.legend()
	plt.show()