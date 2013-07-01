#ifndef ENT_H
#define ENT_H

#define entity_t		int
#define PLAYER_TYPE		1
#define MONSTER_TYPE	2
#define TRAP_TYPE		3

#include <SFML\Graphics.hpp>
#include "position.h"
#include "AnimationNode.h"

class Entity {
private:
	entity_t type;
	Position* pos;
	heading_t heading;
	sf::Sprite sprite;
	sf::Texture* texture;
	float windowX; //Top left corner is 0,0
	float windowY; //Y increases downscreen

	double rotateClockWiseDegreesToHeading(heading_t);
	double rotateDegreesToHeading(heading_t);

public:
	
	Entity(entity_t);
	void move(int, int);
	//void moveNorth(void);
	AnimationNode* moveNorth(void);
	AnimationNode* moveEast(void);
	AnimationNode* moveSouth(void);
	AnimationNode* moveWest(void);
	Position* getPos(void);

	void setTexture(char*);
	void setTexture(sf::Texture*);
	sf::Sprite* getSprite(void);

	
};

#endif