
#include "entity.h"

Entity::Entity(entity_t t) {
	type = t;
	pos = new Position(0,0);
	windowX = 100;
	windowY = 100;
}

void Entity::move(int r, int c) {
	pos->row = r;
	pos->col = c;
}

void Entity::moveNorth(void) {
	pos->row--;
	
	//ANIMATION QUEUE
	windowY-=10;
	sprite.setPosition(sf::Vector2f(windowX, windowY));
}

void Entity::moveEast(void) {
	pos->col++;
	
	//ANIMATION QUEUE
	windowX+=10;
	sprite.setPosition(sf::Vector2f(windowX, windowY));
}

void Entity::moveSouth(void) {
	pos->row++;
	//ANIMATION QUEUE
	windowY+=10;
	sprite.setPosition(sf::Vector2f(windowX, windowY));
}

void Entity::moveWest(void) {
	pos->col--;
	//ANIMATION QUEUE
	windowX-=10;
	sprite.setPosition(sf::Vector2f(windowX, windowY));
}

Position* Entity::getPos(void) {
	return pos;
}


void Entity::setTexture(char* str) {
	if (!texture.loadFromFile(str))
	{
		//ERROR!
	}
	sprite.setTexture(texture);

	sprite.setPosition(sf::Vector2f(100, 100)); //TEMP

}

sf::Sprite* Entity::getSprite(void) {
	return &sprite;
}
