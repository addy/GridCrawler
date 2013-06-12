#ifndef FUNC_H
#define FUNC_H

#define heading_t	int
#define NORTH		0
#define EAST		1
#define SOUTH		2
#define WEST		3


#include <vector>
#include "position.h"
#include "entity.h"


class Map {
private:
	bool** dungeonWalls;
	Entity* player;
	std::vector<Entity*> monsters;
	std::vector<Entity*> traps;


public:
	int height;
	int width;

	Map(int, int, Entity*);
	void print(void);
	void setTrap(Position*);
	void handleMonsterMovement(void);

	bool isWall(Position*);
	bool isWall(heading_t, Position*);
};

#endif