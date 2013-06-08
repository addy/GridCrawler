#include "entity.h"

Entity::Entity(Position* currentPos) {
	this->currentPos = currentPos;
}

void Entity::moveUp() {
	if(currentPos->row != 0)
		currentPos->row = currentPos->row - 1;
}

void Entity::moveDown() {
	if(currentPos->row != 9)
		currentPos->row = currentPos->row + 1;
}

void Entity::moveLeft() {
	if(currentPos->col != 0)
		currentPos->col = currentPos->col - 1;
}

void Entity::moveRight() {
	if(currentPos->col != 9)
		currentPos->col = currentPos->col + 1;
}