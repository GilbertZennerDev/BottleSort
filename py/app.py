"""
dIdee ass fir den Magic Sort no ze programmeiren
et gett folgendes ze maan:

mir hun 3+ Flaeschen mat verschiddene Faarwen
dZill ass pro Flesch eng Faarb oder ganz eidel

if the top is x, then just replace x
the top must be x to allow flushing

cases:

g x -> x x -> x b
b x    b g    x g

Ech hun dLogik agebaut kritt!! JUCHUU!!
"""

import sys

def printBottles(bottles):
	print(bottles[0][0], bottles[1][0], bottles[2][0])
	print(bottles[0][1], bottles[1][1], bottles[2][1])
	
def getFirstNotX(bottle):
	for i, c in enumerate(bottle):
		if c != 'x': return i
	return -1 #only x, is empty
	
def getLastX(bottle):
	for i, c in enumerate(bottle):
		if c != 'x': return (i - 1)
	return (len(bottle) - 1)#no x, is full, return the last index
	
def checkComplete(bottles, index):
	bottle = bottles[index]
	box = bottle[0]
	for i, b in enumerate(bottle):
		if b != box and box != 'x': print("Not Complete"); return False
	print("Complete"); return True
	
def checkBottlesComplete(bottles):
	for i in range(len(bottles)):
		if not checkComplete(bottles, i): return False
	print("All Complete. GAME WON!"); return True

def flushBottle(bottles, indexStart, indexEnd):
	# we flush from indexStart to indexEnd
	# in indexStart we remove the firstNotX from indexStart, then replace the last X in indexEnd
	startBottle = bottles[indexStart]
	firstNotX = getFirstNotX(startBottle)
	lastX = getLastX(bottles[indexEnd])
	if lastX == -1: print("Error: Bottle full"); return
	if firstNotX == -1: print("Error: Bottle is empty"); return
	
	box = startBottle[firstNotX]
	bottles[indexStart][firstNotX] = 'x'
	bottles[indexEnd][lastX] = box
	print(bottles)
	return bottles
	
def userInterface(bottles):
	while 1:
		u = input("s - show bottles, f x y - flush from x to y, c - check all bottles complete, x - exit.\n")
		if u == 'x': exit()
		if u == 's': print(bottles)
		if u == 'c': checkBottlesComplete(bottles)
		u = u.split(' ')
		if u[0] == 'f':
			bottles = flushBottle(bottles, int(u[1]), int(u[2]))		

def	main():
	av = sys.argv
	ac = len(av)
	print("Welcome to Bottle Sort")
	bottles = [
	['g', 'g', 'b'],
	['b', 'b', 'g'],
	['x', 'x', 'x'],
	]
	userInterface(bottles)

if __name__ == '__main__': main()
