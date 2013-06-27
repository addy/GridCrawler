#ifndef MAP_H
#define MAP_H

#define heading_t	int
#define NORTH		0
#define EAST		1
#define SOUTH		2
#define WEST		3

typedef int map_locale_t;
#define CAVE_MAP	0
#define JUNGLE_MAP	1
#define	DUNGEON_MAP 2


#include <vector>
#include "entity.h"


const unsigned int CELL_HEIGHT_PX = 32;
const unsigned int CELL_WIDTH_PX = 32;
const unsigned int WINDOW_HEIGHT_CELLS = 10;
const unsigned int WINDOW_WIDTH_CELLS = 10;

char* const DUNGEON_TEXTURES_LIST[] = {"Brain Jelly.png", "Young Alien.png"};
const int DUNGEON_TEXTURES_LIST_SIZE = sizeof(DUNGEON_TEXTURES_LIST)/sizeof(char*);

class Map {
private:
	bool** dungeonWalls;
	Entity* player;
	std::vector<Entity*> monsters;
	std::vector<Entity*> traps;

	sf::Texture* textures;


public:
	int height;
	int width;

	Map(int, int, Entity*, map_locale_t);
	~Map(void);
	void print(void);
	void setTrap(Position*);
	void handleMonsterMovement(void);

	bool isWall(Position*);
	bool isWall(int, int);
	bool isWall(heading_t, Position*);
};


#endif