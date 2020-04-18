import numpy as np
import sys
import matplotlib.pyplot as plt
import datetime

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_title('Title Goes Here.')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.axis([-1,1,-1,1])
startV1 = -1
endV1 = 1
stepV1 = 0.05
volts1 = np.arange(startV1,endV1+stepV1,stepV1)
startV2 = 1
endV2 = 3
stepV2 = 1
volts2 = np.arange(startV2,endV2+stepV2,stepV2)
ax.axhline(color='k')
ax.axvline(color='k')
lines = []
colorList = ['k','b','r']
fig.canvas.draw() # note that the first draw comes before setting data
legend = plt.legend()
plt.show(block=False)
rawDataArrayList = []
rawDataArray = np.array(([None,None,None,None,None]))

start = datetime.datetime.now()
for idx, volt2 in enumerate(volts2):
	line, = plt.plot([],'x', label = volt2)
	lines.append(line)
	legend.remove()
	legend = plt.legend()
	rawDataArray = np.array(([None,None,None,None,None]))
	for volt1 in volts1:
		rawData = [volt1, volt1**volt2, 2*volt1**volt2, 3*volt1**volt2, 4*volt1**volt2] #This matches the output format of the measureCurrent function. [voltage, current, resistance, time, status]
		rawDataArray = np.vstack((rawDataArray,rawData))
		x = rawDataArray[:,0]
		y = rawDataArray[:,1]
		# plt.plot(x,y, 'x', color = colorList[idx]) # This is about 50% slower than set_data
		lines[idx].set_data(x,y)
		fig.canvas.draw()
		fig.canvas.flush_events()
	rawDataArrayList.append(rawDataArray)
end = datetime.datetime.now()
diff = end-start
print (diff.total_seconds())