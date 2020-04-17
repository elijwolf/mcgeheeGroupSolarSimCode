import numpy as np
import sys
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_title('Title Goes Here.')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
startV = -1
endV = 1
stepV = 0.1
volts = np.arange(startV,endV,stepV)
voltss = volts**2
ax.axis([startV,endV,min(voltss),max(voltss)])
ax.axhline(color='k')
ax.axvline(color='k')
line, = plt.plot([])
fig.canvas.draw() # note that the first draw comes before setting data
axbackground = fig.canvas.copy_from_bbox(ax.bbox) # cache the background
plt.show(block=False)

rawDataArray = np.array(([0,0,0,0,0]))

def updatePlot(x,y):
	line.set_data(x,y)
	fig.canvas.restore_region(axbackground) # restore background
	ax.draw_artist(line) # redraw just the points
	fig.canvas.blit(ax.bbox) # fill in the axes rectangle
	fig.canvas.flush_events()

for volt in volts:
	rawData = [volt, volt**2, volt**3, volt**4, volt**5]
	rawDataArray = np.vstack((rawDataArray,rawData))
	x = rawDataArray[:,0]
	y = rawDataArray[:,1]
	updatePlot(x,y)