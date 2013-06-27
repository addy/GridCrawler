#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class AnimationNode
{
private:
	AnimationNode* nextNode;
	sf::Sprite* sprite;
	sf::Time startTime;
	sf::Time duration;
	double xTranslateFinal;
	double xTransformFinal;
	double yTranslateFinal;
	double yTransformFinal;

public:
	AnimationNode(void);
	AnimationNode(sf::Sprite, sf::Time, sf::Time, double, double, double, double); //sprite to animate, start time, duration, xf, xTf, yf, yTf
	~AnimationNode(void);
	void tick(sf::Time); //needs current time to update the location of the sprite.
	bool done();
	void next(AnimationNode*);
	AnimationNode* next(void);

};

