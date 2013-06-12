
#include "gameplay.h"

GamePlay::GamePlay(void) {
	player = new Entity(PLAYER_TYPE);
	
	player->setTexture("Brain Jelly.png");

	currentMap = new Map(10, 10, player);
}


void GamePlay::checkKeys(void) {

	if		(sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) && !currentMap->isWall(WEST, player->getPos())) player->moveWest();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !currentMap->isWall(EAST, player->getPos())) player->moveEast();

	if		(sf::Keyboard::isKeyPressed(sf::Keyboard::Up  ) && !currentMap->isWall(NORTH, player->getPos())) player->moveNorth();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !currentMap->isWall(SOUTH, player->getPos())) player->moveSouth();	

}



void GamePlay::draw(sf::RenderWindow* window) {
	//ANIMATION AND VIDEO STUFFS. HANDLE ANY ANIMATION / SPRITE MOVEMENTS

	
	(*window).draw(*player->getSprite());


}