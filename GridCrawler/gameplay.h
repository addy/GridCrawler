#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "AnimationNode.h"
#include "map.h"

//MAX FPS
const double MAX_FPS = 100;

class GamePlay {
private:
	Map* currentMap;
	Entity* player;
	sf::RenderWindow* window;
	sf::Clock clk;
	sf::Time checkKeyNextTime;
	sf::Time updateWindowNextTime;
	sf::Time prevUpdateWindowTime;
	AnimationNode* animationList;

public:
	GamePlay(void);
	~GamePlay(void);
	void play(void);
	void draw(sf::RenderWindow*);

	void handleKeyChecking(void);
	void handleAnimation(void);
	void handleMapEnvironment(void);
	void handleWindow(void);
};

#endif