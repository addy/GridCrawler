#ifndef ENT_H
#define ENT_H

#define entity_t		int
#define PLAYER_TYPE		1
#define MONSTER_TYPE	2
#define TRAP_TYPE		3

#include <SFML\Graphics.hpp>
#include "utilities.h"
#include "position.h"

class Entity {
private:
	entity_t type;
	Position* pos;
	sf::Sprite sprite;
	sf::Texture texture;
	float windowX; //Top left corner is 0,0
	float windowY; //Y increases downscreen

public:
	
	Entity(entity_t);
	void move(int, int);
	void moveNorth(void);
	void moveEast(void);
	void moveSouth(void);
	void moveWest(void);
	Position* getPos(void);

	void setTexture(char*);
	sf::Sprite* getSprite(void);

	
};

#endif