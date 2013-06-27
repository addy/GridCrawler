
#include "gameplay.h"

GamePlay::GamePlay(void) {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT_CELLS*CELL_HEIGHT_PX, WINDOW_WIDTH_CELLS*CELL_WIDTH_PX), "Grid Crawler");
	checkKeyNextTime = clk.restart();
	updateWindowNextTime = clk.getElapsedTime();
	animationList = NULL;

	player = new Entity(PLAYER_TYPE);
	player->setTexture("Brain Jelly.png");
	currentMap = new Map(10, 10, player, DUNGEON_MAP);
}

GamePlay::~GamePlay(void) {
	delete window;
	while(animationList != NULL) {
		AnimationNode* prev = animationList;
		animationList = animationList->next();
		delete prev;
	}
	delete currentMap;
	delete player;

}

/**
	play()

	Description:
	The main gameplay loop. This should iterate many times a sec (faster than the framerate).
*/
void GamePlay::play(void) {

	while (window->isOpen())
	{
		handleKeyChecking();
		handleMapEnvironment();
		handleAnimation();
		handleWindow();


	}
}


/**
	handleAnimation()

	Description:
	Handle the animation list. Iterate through a linked list of currently running animations nodes and advance them by a tick.
	Remove a node from the list if it is completed.

*/
void GamePlay::handleKeyChecking(void) {
	if(checkKeyNextTime <= clk.getElapsedTime()) { //Check to see if movement animation is completed??

		bool keyWasPressed = false;

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A )) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D )))
		{
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A )) && !currentMap->isWall(WEST, player->getPos())) {
			player->moveWest();
			keyWasPressed = true;
		} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D )) && !currentMap->isWall(EAST, player->getPos())) {
			player->moveEast();
			keyWasPressed = true;
		}


		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W )) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S )))
		{
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up  ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W )) && !currentMap->isWall(NORTH, player->getPos())) {
			player->moveNorth();
			keyWasPressed = true;
		} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S )) && !currentMap->isWall(SOUTH, player->getPos())) {
			player->moveSouth();
			keyWasPressed = true;
		}

		if(keyWasPressed) checkKeyNextTime = clk.getElapsedTime()+sf::milliseconds(100);

	}
}


/**
	handleAnimation()

	Description:
	Handle the animation list. Iterate through a linked list of currently running animations nodes and advance them by a tick.
	Remove a node from the list if it is completed.

*/
void GamePlay::handleAnimation(void) {

	AnimationNode* currentNode = animationList;
	AnimationNode* prevNode = NULL;
	
	while(currentNode != NULL) {
		currentNode->tick(clk.getElapsedTime());


		if(currentNode->done()) {
			if(prevNode != NULL) prevNode->next(currentNode->next());
			currentNode->~AnimationNode();
			delete currentNode;
		}

		prevNode = currentNode;
		currentNode = currentNode->next();
	}

}

/**
	handleMapEnvironment()

	Description:
	Handle MAP AI and passive map stuffs.
*/
void GamePlay::handleMapEnvironment(void) {


}

/**
	handleWindow()

	Description:
	Handle framerates/window updates and check for close window events.
*/
void GamePlay::handleWindow(void) {

		//update the screen at a maximum of a certain times per second
		if(updateWindowNextTime <= clk.getElapsedTime()) {


			draw(window);
			

			prevUpdateWindowTime = updateWindowNextTime;
			updateWindowNextTime = clk.getElapsedTime()+sf::milliseconds((int)(1000/MAX_FPS)); //current time + milliseconds per frame
		}


		//check for close window events
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
}


/**
	draw()

	Description:
	Print all the sprites to the screen.
*/
void GamePlay::draw(sf::RenderWindow* window) {
	window->clear(sf::Color::Black);

	window->draw(*player->getSprite());
	//iterate through all the entities in currentMap

	window->display();
}