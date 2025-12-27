import sys

def printBottles(bottles):
	for y in range(len(bottles[0])):
		for x in range(len(bottles)):
			print(bottles[x][y], end=' ')
		print()
	
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

def flush_bottle(bottles, indexStart, indexEnd):
	old_bottles = bottles
	check = lambda x, bottles: x < 0 or x >= len(bottles)
	if check(indexStart, old_bottles) or check(indexEnd, old_bottles): return old_bottles
	# we flush from indexStart to indexEnd
	# in indexStart we remove the firstNotX from indexStart, then replace the last X in indexEnd
	startBottle = bottles[indexStart]
	firstNotX = getFirstNotX(startBottle)
	lastX = getLastX(bottles[indexEnd])
	if lastX == -1: print("Error: Bottle full"); return old_bottles
	if firstNotX == -1: print("Error: Bottle is empty"); return old_bottles
	
	box = startBottle[firstNotX]
	bottles[indexStart][firstNotX] = 'x'
	bottles[indexEnd][lastX] = box
	printBottles(bottles)
	return bottles
	
def load_level(levelname, folder="levels/"):
	try:
		content = open(folder + levelname + ".lvl", 'r').read().splitlines()
		size = len(content[0].split())
		bottles = [line.split() for line in content]
		printBottles(bottles)
		return bottles
	except Exception as e:
		print(e); return []

#each line is one bottle, so loop across the bottles
def save_level(levelname, bottles):
	try:
		content = "\n".join([" ".join(bottle) for bottle in bottles])
		open("saves/" + levelname + ".lvl", 'w').write(content)
		print("Level Saved")
	except Exception as e:
		print(e);

def userInterface():
	bottles = load_level("1")
	cmds = "s - show bottles, f x y - flush from x to y, c - check all bottles complete, l x - load level x, save - saveLevel, ls - load savedLevel, h - toggle commands, x - exit.\n"
	show_commands = True
	while 1:
		txt = ""
		if show_commands: txt = cmds
		u = input(txt)
		if u == 'x': exit()
		if u == 's' and len(bottles): printBottles(bottles)
		if u == 'c': checkBottlesComplete(bottles)
		if u == 'h': show_commands = not show_commands
		u = u.split(' ')
		if u[0] == 'f' and len(u) == 3 and len(bottles) and u[1] != u[2]:
			bottles = flush_bottle(bottles, int(u[1]), int(u[2]))
		if u[0] == 'l' and len(u) == 2:
			bottles = load_level(u[1])
		if u[0] == 'ls' and len(u) == 2:
			bottles = load_level(u[1], "saves/")
		if u[0] == 'save': save_level(u[1], bottles)

def	main():
	av = sys.argv
	ac = len(av)
	print("Welcome to Bottle Sort")
	userInterface()

if __name__ == '__main__': main()
