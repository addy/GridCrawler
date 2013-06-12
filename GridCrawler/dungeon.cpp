#include <SFML\Graphics.hpp>
#include "gameplay.h"

void UpdateWindow(void);

sf::RenderWindow window;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "Grid Crawler");




	GamePlay* g = new GamePlay();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}


		g->checkKeys();

		window.clear(sf::Color::Black);


		g->draw(&window);


		window.display();



	}

	return 0;
}