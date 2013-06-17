#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "map.h"
#include "entity.h"

class GamePlay {
private:
	Map* currentMap;
	Entity* player;

public:
	GamePlay(void);
	bool checkKeys(void);
	void draw(sf::RenderWindow*);
};

#endif