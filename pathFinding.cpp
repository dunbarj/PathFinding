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
	printMap();
}

void PFSystem::menu() {
	cout << "Welcome to the menu!" << endl;
}

char ** PFSystem::generateMap() {
	if (map != NULL) {
		free(map);
	}
	for (int i = 0; i < height; i++) {
		map[i] = (char *) calloc(width, sizeof(char));
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == (height - 1)) {
				map[i][j] = '@';
			}
			else if (j == 0 || j == (width - 1)) {
				map[i][j] = '@';
			}
			else {
				map[i][j] = ' ';
			}
		}
	}
	return map;
}

void PFSystem::printMap() {
	for (int i = 0; i < height; i++) {
		cout << &map[i][0] << endl;
	}
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

