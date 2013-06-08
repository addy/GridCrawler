#include "functions.h"
#include <iostream>

Functions::Functions() {
	playerPos = setPlayer();
	player = new Entity(playerPos);

	trapPos = setTrap(playerPos);
	trap = new Entity(trapPos);

	monsterPos = setMonster(playerPos, trapPos);
	monster = new Entity(monsterPos);
	
	int i, j;

	dungeon = new char*[10];
	for(i = 0; i < 10; i++)
		dungeon[i] = new char[10];
}

void Functions::print() {
	int i, j;

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			if(playerPos->row == i && playerPos->col == j)
				dungeon[i][j] = 'P';
			else if(monsterPos->row == i && monsterPos->col == j)
				dungeon[i][j] = 'M';
			else if(trapPos->row == i && trapPos->col == j)
				dungeon[i][j] = 'T';
			else
				dungeon[i][j] = '.';
		}
	}

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			std::cout << dungeon[i][j];
			if (j == 9)
				std::cout << std::endl;
		}
	}
}

Position* Functions::setTrap(Position* player) {
	int row, col;
	while(true) {
		row = rand() % 10;
		col = rand() % 10;
		if (row != player->row && col != player->col)
			break;
	}

	return new Position(row, col);
}

Position* Functions::setPlayer() {
	int row = rand() % 10;
	int col = rand() % 10;

	return new Position(row, col);
}

Position* Functions::setMonster(Position* player, Position* trap) {
	int row, col;
	while(true) {
		row = rand() % 10;
		col = rand() % 10;
		if (row != player->row && row != trap->row && col != player->col && col != trap->col)
			break;
	}

	return new Position(row, col);
}

void Functions::moveMonster() {
	int move = rand() % 4 + 1;

	switch(move) {
		case 1:
			monster->moveUp();
			break;
		case 2:
			monster->moveDown();
			break;
		case 3:
			monster->moveLeft();
			break;
		case 4:
			monster->moveRight();
			break;
	}

	
}

