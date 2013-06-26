
#include "gameplay.h"

GamePlay::GamePlay(void) {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT_CELLS*CELL_HEIGHT_PX, WINDOW_WIDTH_CELLS*CELL_WIDTH_PX), "Grid Crawler");
	checkKeyNextTime = clk.restart();
	updateWindowNextTime = clk.getElapsedTime();

	player = new Entity(PLAYER_TYPE);
	
	player->setTexture("Brain Jelly.png");

	currentMap = new Map(10, 10, player, DUNGEON_MAP);
}


void GamePlay::play(void) {

	while (window->isOpen())
	{
		//Check to see if movement animation is completed??
		if(checkKeyNextTime <= clk.getElapsedTime() && checkKeys())
			checkKeyNextTime = clk.getElapsedTime()+sf::milliseconds(100);

		handleAnimation();
		handleMapEnvironment();


		//update the screen at a maximum of a certain times per second
		if(updateWindowNextTime <= clk.getElapsedTime()) {
			window->clear(sf::Color::Black);

			draw(window);
			
			window->display();
			prevUpdateWindowTime = updateWindowNextTime;
			updateWindowNextTime = clk.getElapsedTime()+sf::milliseconds((int)(1000/MAX_FPS)); //current time + milliseconds per frame
		}


		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window->close();
		}

	}
}



int GamePlay::endGame(void) {
	//free all memory.
	return 0;
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
	window->draw(*player->getSprite());


}

void GamePlay::handleAnimation(void) {


}

void GamePlay::handleMapEnvironment(void) {


}