#ifndef ENT_H
#define ENT_H
#include "position.h"

class Entity {
public:
	Position* currentPos;
	Entity(Position*);
	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);
};

#endif