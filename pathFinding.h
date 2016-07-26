#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
		Player(int x, int y, int maxX, int maxY);
		void getPlayerMovement();
		int posX, posY, maxBoundsX, maxBoundsY;
};

class Follower {
	public:
		Follower(int x, int y);
		int xPos;
		int yPos;
};
