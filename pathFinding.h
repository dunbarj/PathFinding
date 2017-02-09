#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class Player;
class Follower;

struct Node {
	Node * parent;
	int x, y;
	int f, g, h;	
};

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
		int * getFollowerMovement(Follower * flwr, int targetX, int targetY);
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
		bool isTurn;
		int xPos;
		int yPos;
};
