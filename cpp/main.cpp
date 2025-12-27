#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
def userInterface(bottles):
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
*/

/*
def	main():
	av = sys.argv
	ac = len(av)
	print("Welcome to Bottle Sort")
	bottles = load_level("1")
	userInterface(bottles)
*/

void userInterface()
{
	vector<vector<char>> bottles;
	string cmds, txt, u;
	bool show_commands;

	cmds = "s - show bottles, f x y - flush from x to y, c - check all bottles complete, l x - load level x, save - saveLevel, ls - load savedLevel, h - toggle commands, x - exit.\n";
	show_commands = true;
	while (1)
	{
		txt.clear();
		if (show_commands) txt = cmds;
		cout << txt;
		cin >> u;
		cout << "debug u:" << u << "\n";
	}
}

int	main(int ac, char **av)
{
	cout << "Welcome to Bottle Sort\n";
	userInterface();
	return (0);
}
