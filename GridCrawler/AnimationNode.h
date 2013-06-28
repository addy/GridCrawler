#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>


class AnimationNode
{
private:
	AnimationNode* nextNode;
	sf::Sprite* sprite;
	double startTime;
	double duration;

	sf::Vector2f startingPos;
	sf::Vector2f startingScale;

	double progressRatio;

	double xTranslateStart;
	double xTranslate;
	double xTransformStart;
	double xTransform;

	double yTranslateStart;
	double yTranslate;
	double yTransformStart;
	double yTransform;

	double rotationStart;
	double rotation;

public:
	AnimationNode(void);
	AnimationNode(sf::Sprite*, sf::Time, double, double, double, double, double); //sprite to animate,  duration, xf, xTf, yf, yTf
	~AnimationNode(void);
	void start(sf::Time);
	void tick(sf::Time); //needs current time to update the location of the sprite.
	bool done(void);
	void next(AnimationNode*);
	AnimationNode* next(void);

};

