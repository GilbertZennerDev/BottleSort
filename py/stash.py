"""
def load_level(levelname):
	try:
		content = open("levels/" + levelname + ".lvl", 'r').read().splitlines()
		size = len(content[0].split())
		bottles = [[line.split()[i] for line in content] for i in range(size)]
		printBottles(bottles)
		return bottles
	except Exception as e:
		print(e); return []
"""
#now each bottle is one line, so much simpler


