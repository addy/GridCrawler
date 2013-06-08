#include <iostream>
#include "functions.h"
#include "gameplay.h"
#include <SFML\Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Grid Crawler");

	sf::Sprite sprite;
    sf::Texture image;

	image.loadFromFile("\Graphics\Textures\dirt_0.png");
	sprite.setTexture(image);
	sprite.setPosition(50.0f, 50.0f);
	window.draw(sprite);

	Functions* p = new Functions();
	GamePlay* g = new GamePlay();

	while(true) {
		system("CLS");
		p = g->turn(p);
	}

	system("PAUSE");
	return 0;
}