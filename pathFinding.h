#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Player;
class Follower;

class PFSystem {
	public:
		PFSystem(int width, int height);
		void menu();
		char ** generateMap();
		void printMap();
		
		char **  map;
		int width;
		int height;
		Player * player;
		Follower ** followers;
};

class Player {
	public:
		Player(int x, int y);
		
		int xPos;
		int yPos;
};

class Follower {
	public:
		Follower(int x, int y);
		int xPos;
		int yPos;
};
