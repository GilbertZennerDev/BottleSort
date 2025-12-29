#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

void printBottles(vector<string> bottles)
{
	int y, x;

	y = -1;
	while (++y < bottles[0].size())
	{
		x = -1;
		while (++x < bottles.size())
			cout << bottles[x][y] << " ";
		cout << "\n";
	}
}

int getFirstNotX(string bottle)
{
	int i;

	i = -1;
	while (++i < bottle.size())
		if (bottle[i] != 'x') return (i);
	return (-1);
}

int getLastX(string bottle)
{
	int i;

	i = -1;
	while (++i < bottle.size())
		if (bottle[i] != 'x') return (i - 1);
	return (bottle.size() - 1);
}

bool checkComplete(string bottle)
{
	unsigned int i;
	char box;

	i = 0;
	box = bottle[0];
	while (++i < bottle.size())
		if (bottle[i] != box && box != 'x')
		{
			cout << "Not Complete\n." << bottle[i] << ". ." << box << ".\n";
			return (false);
		}
	cout << "Complete\n";
	return (true);
}

bool checkBottlesComplete(vector<string> bottles)
{
	int i;

	i = -1;
	while (++i < bottles.size())
		if (!checkComplete(bottles[i])) return (false);
	cout << "All Complete. GAME WON!\n";
	return (true);
}

bool check(unsigned int x, vector<string> bottles)
{
	return (x < 0 || x >= bottles.size());
}

void flush_bottle(vector<string> *bottles, unsigned int indexStart, unsigned int indexEnd)
{
	char box;
	int lastX;
	int firstNotX;
	string startBottle;	

	if (check(indexStart, *bottles) || check(indexEnd, *bottles)) return ;
	//# we flush from indexStart to indexEnd
	//# in indexStart we remove the firstNotX from indexStart, then replace the last X in indexEnd
	startBottle = (*bottles)[indexStart];
	firstNotX = getFirstNotX(startBottle);
	lastX = getLastX((*bottles)[indexEnd]);
	if (lastX == -1){cout << "Error: Bottle full\n"; return ;}
	if (firstNotX == -1){cout << "Error: Bottle is empty\n"; return ;}
	box = startBottle[firstNotX];
	(*bottles)[indexStart][firstNotX] = 'x';
	(*bottles)[indexEnd][lastX] = box;
	printBottles(*bottles);
	return ;
}

bool	check_level_valid(vector<string> bottles)
{
//	#simple: we check all bottles have same length and length > 0
//	#also at least 2 bottles are needed
	int		i;
	unsigned int	size;

	if (bottles.size() < 2) return (false);
	size = bottles[0].size();
	i = -1;
	while (++i < bottles.size())
		if (bottles[i].size() != size) return (false);
	return (true);
}

void load_level(vector<string> *bottles, string levelname, string foldername="levels/")
{
	stringstream	ss;
	string		line;
	string		bottle;

	fstream f(foldername + levelname + ".lvl");
	if (!f.is_open()) {
        cerr << "Error opening the file!";
        return ;
   	}
   	(*bottles).clear();
	while (getline(f, line))
	{
		ss.clear();
		ss << line;
		bottle.clear();
		while(getline(ss, line, ' '))
			bottle.push_back(line[0]);
		(*bottles).push_back(bottle);
	}
	if (!check_level_valid(*bottles))
	{
		(*bottles).clear();
		cout << "Error: Level invalid.\n";
	}
	f.close();
	return ;
}

void	save_level(string levelname, vector<string> bottles)
{
	int	i;
	int	j;
	string	line;

	ofstream f("saves/" + levelname + ".lvl");
	if (!f.is_open()) {
        cerr << "Error opening the file!";
        return ;
   	}
	//ech muss just all string an bottles an f saven.
	i = -1;
	while (++i < bottles.size())
	{
		j = -1;
		line.clear();
		while (++j < bottles[i].size())
		{
			line.push_back(bottles[i][j]);
			line.push_back(' ');
		}
		f << line + "\n";
	}
	f.close();
}

void userInterface()
{
	string u;
	string t;
	string cmds;
	bool show_cmds;
	stringstream ss;
	vector<string> u2;
	vector<string> bottles;

	show_cmds = true;
	load_level(&bottles, "1");
	cmds = string("s - show bottles, f x y - flush from x to y, c - check all bottles complete, l x - load level x, save - saveLevel, ls - load savedLevel, h - toggle commands, x - exit.\n");
	
	cout << "Welcome to Bottle Sort\n";
	while (1)
	{
		u.clear();
		if (show_cmds) cout << cmds;
		getline(cin, u);
		if (u == string("x")) exit(1);
		if (u == string("s") && bottles.size()) printBottles(bottles);
		if (u == string("c")) checkBottlesComplete(bottles);
		if (u == string("h")) show_cmds = !show_cmds;
		ss.clear();
		ss << u;
		u2.clear();
		while(getline(ss, t, ' '))
			u2.push_back(t);
		if (u2[0] == string("f") && u2.size() == 3 && bottles.size() && u2[1] != u2[2])
			flush_bottle(&bottles, atoi(u2[1].c_str()), atoi(u2[2].c_str()));
		if (u2[0] == string("l") && u2.size() == 2)
			load_level(&bottles, u2[1]);
		if (u2[0] == string("ls") && u2.size() == 2)
			load_level(&bottles, u2[1], "saves/");
		if (u2[0] == string("save")) save_level(u2[1], bottles);
	}
}

int	main(int ac, char **av)
{
	userInterface();
	return (0);
}
