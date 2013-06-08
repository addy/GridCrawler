#include "gameplay.h"
#include "functions.h"
#include <iostream>

Functions* GamePlay::turn(Functions* p) {
	char move;
	p->print();
	std::cout << "Enter (u)p, (d)own, (l)eft, or (r)ight ";
	std::cin >> move;
	switch(move) {
		case 'u':
			p->player->moveUp();
			break;
		case 'd':
			p->player->moveDown();
			break;
		case 'l':
			p->player->moveLeft();
			break;
		case 'r':
			p->player->moveRight();
			break;
		default: 
			break;
	}

	p->moveMonster();

	return p;
}