#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "utilities.h"

#include "gameplay.h"


//MAX FPS
const double MAX_FPS = 100;


int main() {
	//We may need to move this code into a graphics handling object and a user input object... or just an IO object.
	sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT_CELLS*CELL_HEIGHT_PX, WINDOW_WIDTH_CELLS*CELL_WIDTH_PX), "Grid Crawler");
	sf::Clock clk;
	sf::Time checkKeyNextTime = clk.restart();
	sf::Time updateScreenNextTime = clk.getElapsedTime();


	GamePlay* g = new GamePlay();


	while (window.isOpen())
	{
		//Check to see if movement animation is completed??
		if(checkKeyNextTime <= clk.getElapsedTime() && g->checkKeys())
			checkKeyNextTime = clk.getElapsedTime()+sf::milliseconds(100);

		g->handleAnimation();
		g->handleMapEnvironment();


		//update the screen at a maximum of a certain times per second
		if(updateScreenNextTime <= clk.getElapsedTime()) {
			window.clear(sf::Color::Black);

			g->draw(&window);
			
			window.display();
			updateScreenNextTime = clk.getElapsedTime()+sf::milliseconds((int)(1000/MAX_FPS)); //current time + milliseconds per frame
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

	}

	return 0;
}