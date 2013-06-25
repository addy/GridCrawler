
#include "gameplay.h"

GamePlay::GamePlay(void) {
	player = new Entity(PLAYER_TYPE);
	
	player->setTexture("Brain Jelly.png");

	currentMap = new Map(10, 10, player, DUNGEON_MAP);
}


bool GamePlay::checkKeys(void) {
	bool keyWasPressed = false;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A )) && !currentMap->isWall(WEST, player->getPos())) {
		player->moveWest();
		keyWasPressed = true;
	} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D )) && !currentMap->isWall(EAST, player->getPos())) {
		player->moveEast();
		keyWasPressed = true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up  ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W )) && !currentMap->isWall(NORTH, player->getPos())) {
		player->moveNorth();
		keyWasPressed = true;
	} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S )) && !currentMap->isWall(SOUTH, player->getPos())) {
		player->moveSouth();
		keyWasPressed = true;
	}

	return keyWasPressed;

	//Need to not call this method again till animation sequence is finished.
}



void GamePlay::draw(sf::RenderWindow* window) {
	//ANIMATION AND VIDEO STUFFS. HANDLE ANY ANIMATION / SPRITE MOVEMENTS

	
	(*window).draw(*player->getSprite());


}

void GamePlay::handleAnimation(void) {


}

void GamePlay::handleMapEnvironment(void) {


}