#include "pathFinding.h"

using namespace std;

int main(int argc, char * argv[]) {
	PFSystem * system;
	if (argc < 3) {
		system = new PFSystem(15, 10);
	}
	else {
		system = new PFSystem(atoi(argv[1]), atoi(argv[2]));
	}
	system->menu();
	return 0;	
}

/* PFSystem functions */
PFSystem::PFSystem(int inWidth, int inHeight) {
	width = inWidth;
	height = inHeight;
	player = new Player(1, 1);
	followers = NULL;
	map = NULL;
	map = generateMap();
}

void PFSystem::menu() {
	cout << "Welcome to the menu!" << endl;
}

char ** PFSystem::generateMap() {
	if (map != NULL) {
		free(map);
	}
	map = (char **) calloc(width * sizeof(char), height);
	return map;
}

void PFSystem::printMap() {

}


/* Player functions */
Player::Player(int x, int y) {
	xPos = x;
	yPos = y;
}


/* Follower functions */
Follower::Follower(int x, int y) {
	xPos = x;
	yPos = y;
}

