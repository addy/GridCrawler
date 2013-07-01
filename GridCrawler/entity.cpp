#include "map.h"
#include "entity.h"

Entity::Entity(entity_t t) {
	type = t;
	pos = new Position(0,0);
	heading = NORTH;
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
	AnimationNode* n = new AnimationNode(&sprite, sf::milliseconds(100), 0, 0, -CELL_HEIGHT_PX, 0, rotateDegreesToHeading(NORTH));
	heading = NORTH;
	return n;
}

AnimationNode* Entity::moveEast(void) {
	pos->col++;
	windowX+=32;
	AnimationNode* n = new AnimationNode(&sprite, sf::milliseconds(100), CELL_WIDTH_PX, 0, 0, 0, rotateDegreesToHeading(EAST));
	heading = EAST;
	return n;
}

AnimationNode* Entity::moveSouth(void) {
	pos->row++;
	windowY+=32;
	AnimationNode* n = new AnimationNode(&sprite, sf::milliseconds(100), 0, 0, CELL_HEIGHT_PX, 0, rotateDegreesToHeading(SOUTH));
	heading = SOUTH;
	return n;
}

AnimationNode* Entity::moveWest(void) {
	pos->col--;
	windowX-=32;
	AnimationNode* n = new AnimationNode(&sprite, sf::milliseconds(100), -CELL_WIDTH_PX, 0, 0, 0, rotateDegreesToHeading(WEST));
	heading = WEST;
	return n;
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
	sf::FloatRect sprite_size = sprite.getLocalBounds();
	sprite.setOrigin(sprite_size.width/2,sprite_size.height/2);

}

void Entity::setTexture(sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);

}


sf::Sprite* Entity::getSprite(void) {
	return &sprite;
}


double Entity::rotateDegreesToHeading(heading_t h) {
	if(heading == NORTH) {
		return	(h == NORTH) ?   0.0 :
				(h == EAST)  ?  90.0 :
				(h == SOUTH) ? 180.0 : 
							   -90.0;
	} else if(heading == EAST) {
		return	(h == NORTH) ? -90.0 :
				(h == EAST)  ?   0.0 :
				(h == SOUTH) ?  90.0 : 
							   180.0;
	} else if(heading == SOUTH) {
		return	(h == NORTH) ? 180.0 :
				(h == EAST)  ? -90.0 :
				(h == SOUTH) ?   0.0 : 
							    90.0;
	} else if(heading == WEST) {
		return	(h == NORTH) ?  90.0 :
				(h == EAST)  ? 180.0 :
				(h == SOUTH) ? -90.0 : 
							     0.0;
	} else return 0.0;
}
