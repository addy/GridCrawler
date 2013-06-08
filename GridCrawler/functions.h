#ifndef FUNC_H
#define FUNC_H
#include "position.h"
#include "entity.h"

class Functions {
private:
	char** dungeon;
	Position* playerPos;
	Position* trapPos;
	Position* monsterPos;
	
	
public:
	Entity* player;
	Entity* trap;
	Entity* monster;
	Functions(void);
	void print(void);
	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);
	void moveMonster(void);
	Position* setTrap(Position*);
	Position* setPlayer(void);
	Position* setMonster(Position*, Position*);
};

#endif