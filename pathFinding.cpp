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
	fflush(0);
	while (1) {
		system->generateMap();
		system->printMap();
		system->player->getPlayerMovement();
	}
	return 0;	
}

/* PFSystem functions */
PFSystem::PFSystem(int inWidth, int inHeight) {
	width = inWidth;
	height = inHeight;
	player = new Player(1, 1, width, height);
	followers = NULL;
	map = NULL;
}

void PFSystem::menu() {
	cout << "Welcome to the menu!" << endl;
}

char ** PFSystem::generateMap() {
	if (map != NULL) {
		free(map);
	}
	map = (char **) malloc(sizeof(char *) * height);
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
				if (i == player->posY && j == player->posX) {
					map[i][j] = 'X';
				}
				else {
					map[i][j] = ' ';
				}
			}
		}
	}
	return map;
}

void PFSystem::printMap() {
	system("clear");
	for (int i = 0; i < height; i++) {
		printf("%s\n", &map[i][0]);
	}
}

int * PFSystem::getFollowerMovement(Follower * flwr, int targetX, int targetY) {
	int openNum = 0;
	int closedNum = 0;
	Node ** openList = (Node **) malloc(100 * sizeof(Node *));
	Node ** closedList = (Node **) malloc(100 * sizeof(Node *));
	Node * start = (Node *) malloc(sizeof(Node));
	start->parent = NULL;
	start->x = flwr->xPos;
	start->y = flwr->yPos;
	start->f = 0;
	start->g = 0;
	start->h = Mathf.abs(targetX - flwr->posX) + Mathf.abs(targetY - flwr->posY);
	openList[openNum++] = start;
	while (openNum > 0) {
		// Set node with lowest F score as qnode
		Node * qnode = openList[0];

		// Remove qnode from open list
		for (int i = 0; i < openNum - 1; i++) {
			openList[i] = openList[i+1];
		}
		openList[i] = NULL;
		openNum--;
		
		// Generate successors
		int num = 4;
		Node ** successors = (Node **) malloc(num * sizeof(Node *));
		for (int i = 0; i < num; i++) {
			successors[i] = (Node *) malloc(sizeof(Node));
			successors[i]->parent = qnode;
		}
		// 0 is up, then clockwise
	}
}


/* Player functions */
Player::Player(int x, int y, int maxX, int maxY) {
	posX = x;
	posY = y;
	maxBoundsX = maxX;
	maxBoundsY = maxY;
}

void Player::getPlayerMovement() {
	char input;
	bool valid = false;
	while (!valid) {
		cout << "Enter direction (w,a,s,d): ";
		cin >> input;
		switch (input) {
			case 'w':
				posY = posY - 1;
				if (posY <= 0) {
					posY = 1;
				}
				valid = true;
				break;
			case 'a':
				posX = posX - 1;
				if (posX <= 0) {
					posX = 1;
				}
				valid = true;
				break;
			case 's':
				posY = posY + 1;
				if (posY >= (maxBoundsY - 1)) {
					posY = maxBoundsY - 2;
				}
				valid = true;
				break;
			case 'd':
				posX = posX + 1;
				if (posX >= (maxBoundsX - 1)) {
					posX = maxBoundsX - 2;
				}
				valid = true;
				break;
			case 'c':
				exit(0);
			default:
				cout << "Invalid input!" << endl;
		}
	}
}


/* Follower functions */
Follower::Follower(int x, int y) {
	xPos = x;
	yPos = y;
}

