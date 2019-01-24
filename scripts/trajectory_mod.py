import re
import math
import sys

if len(sys.argv) != 3:
  print "You must specify the file name and the rotation degrees."
  exit()

fileName = sys.argv[1]
degrees = float(sys.argv[2])
radians = math.radians(degrees)

file = open(fileName, "r")
lines = file.readlines()

timeCol = 0
xCol = 1
yCol = 3

# String processed
for lineIndex in range(0, len(lines)):
  line = lines[lineIndex]
  line = line.replace("\n", "")
  line = re.compile(" +").split(line)
  lines[lineIndex] = line

timeRel = float(lines[0][timeCol])
lines[0][timeCol] = 0
xMove = float(lines[0][xCol])
lines[0][xCol] = 0
yMove = float(lines[0][yCol])
lines[0][yCol] = 0

for lineIndex in range(1, len(lines)):
  x = float(lines[lineIndex][xCol])
  y = float(lines[lineIndex][yCol])
  time = float(lines[lineIndex][timeCol])
  lines[lineIndex][xCol] = x - xMove
  lines[lineIndex][yCol] = y - yMove
  lines[lineIndex][timeCol] = time - timeRel

for lineIndex in range(1, len(lines)):
  x = float(lines[lineIndex][xCol])
  y = float(lines[lineIndex][yCol])
  xp = x * math.cos(radians) - y * math.sin(radians)
  yp = x * math.sin(radians) + y * math.cos(radians)
  lines[lineIndex][xCol] = xp
  lines[lineIndex][yCol] = yp

file = open("trayectoriaResult.txt", "w")
for lineIndex in range(0, len(lines)):
  line = ""
  for i in range(0, len(lines[lineIndex])):
    line += str(lines[lineIndex][i])
    if i < (len(lines[lineIndex]) - 1):
      line += " "
  line += "\n"
  file.write(line)
file.close()
