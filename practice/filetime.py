import os.path, time
import sys

# Validate command line arguments, print usage if not correct:
numArgs = len(sys.argv)
if (numArgs < 4 ):
   print ("Usage: str(sys.argv[0]) <path to file 1> <path to file 2> <path to file3>")
   sys.exit(2)

#Store file names in a list:
fileList = [sys.argv[1], sys.argv[2], sys.argv[3]]

# Call the get access time function from the os.path module for each file:
ractime1 = os.path.getatime(sys.argv[1])
ractime2 = os.path.getatime(sys.argv[2])
ractime3 = os.path.getatime(sys.argv[3])

#Store access times in a list:
timeList = [ractime1, ractime2, ractime3]

#Store the filename list and corresponding access times list in a key-value pair, using 'dict':
kvPair = dict(zip(timeList, fileList))

#Find the max of the access time list, the most recently accessed file is the one with max time value:
high = max(timeList)

#Use the max time value to index into the key-vale pair and return the corresponding file name:
print kvPair[high]
