import re
import cmath
import sys

if len(sys.argv) != 3:
  print "You must specify the file name and column arguments."
  exit()

fileNameIn = sys.argv[1]
fileNameOut = sys.argv[2]

fileIn = open(fileNameIn, "r")
lines = fileIn.readlines()

previousTime = 0
durations = []
for lineIndex in range(0, len(lines)):
  line = lines[lineIndex]
  line = line.replace("\n", "")
  line = re.compile(" +").split(line)

  if lineIndex == 0:
    previousTime = line[0]
  else:
    durations = durations + [float(line[0]) - float(previousTime)]
    previousTime = line[0]

fileOut = open(fileNameOut,"w+")

fileOut.write("Durations\n")
for durationIndex in range(0, len(durations)):
  fileOut.write(str(durations[durationIndex]) + "\n")

fileOut.close()
