
#include "entity.h"

Entity::Entity(entity_t t) {
	type = t;
	pos = new Position(0,0);
	texture = new sf::Texture();
	sprite.setPosition(sf::Vector2f(windowX = 0, windowY = 0));
}

void Entity::move(int r, int c) {
	pos->row = r;
	pos->col = c;
}

AnimationNode* Entity::moveNorth(void) {
	pos->row--;
	windowY-=32;
	return new AnimationNode(&sprite, sf::milliseconds(100), 0, 0, -32, 0, 0);
	//sprite.setPosition(sf::Vector2f(windowX, windowY));
}

AnimationNode* Entity::moveEast(void) {
	pos->col++;
	windowX+=32;
	return new AnimationNode(&sprite, sf::milliseconds(100), 32, 0, 0, 0, 0);
	//sprite.setPosition(sf::Vector2f(windowX, windowY));
}

AnimationNode* Entity::moveSouth(void) {
	pos->row++;
	windowY+=32;
	return new AnimationNode(&sprite, sf::milliseconds(100), 0, 0, 32, 0, 0);
	//sprite.setPosition(sf::Vector2f(windowX, windowY));
}

AnimationNode* Entity::moveWest(void) {
	pos->col--;
	windowX-=32;
	return new AnimationNode(&sprite, sf::milliseconds(100), -32, 0, 0, 0, 0);
	//sprite.setPosition(sf::Vector2f(windowX, windowY));
}

Position* Entity::getPos(void) {
	return pos;
}


void Entity::setTexture(char* str) {
	if (!(*texture).loadFromFile(str))
	{
		//ERROR!
	}
	sprite.setTexture(*texture);

}

void Entity::setTexture(sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);

}


sf::Sprite* Entity::getSprite(void) {
	return &sprite;
}
