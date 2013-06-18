#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "utilities.h"

#include "gameplay.h"





int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT_CELLS*CELL_HEIGHT_PX, WINDOW_WIDTH_CELLS*CELL_WIDTH_PX), "Grid Crawler");
	sf::Clock clk;
	sf::Time checkKeyNextTime = clk.restart();


	GamePlay* g = new GamePlay();


	while (window.isOpen())
	{
		if(checkKeyNextTime <= clk.getElapsedTime() && g->checkKeys())
			checkKeyNextTime = clk.getElapsedTime()+sf::milliseconds(100);

		window.clear(sf::Color::Black);


		g->draw(&window);


		window.display();




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