#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "gameplay.h"

void UpdateWindow(void);

sf::RenderWindow window;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "Grid Crawler");
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