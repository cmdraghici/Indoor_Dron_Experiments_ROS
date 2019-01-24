import re
import math
import sys
import statistics as st

if len(sys.argv) != 2:
  print "You must specify the file name."
  exit()

fileName = sys.argv[1]

file = open(fileName, "r")
lines = file.readlines()

xCol = 1
yCol = 3

# String processed
for lineIndex in range(0, len(lines)):
  line = lines[lineIndex]
  line = line.replace("\n", "")
  line = re.compile(" +").split(line)
  lines[lineIndex] = line

col = []

for lineIndex in range(0, len(lines)):
  col.append(float(lines[lineIndex][yCol]))

file = open("resultados.txt", "a")
file.write("\n" + fileName + " Standar dev: " + str(st.stdev(col)))
file.write(" Error: " + str(abs(float(lines[len(lines)-1][xCol])) - 1.91))
file.close()
