#include "utilities.h"
#include "AnimationNode.h"


AnimationNode::AnimationNode(void)
{
}

AnimationNode::AnimationNode(sf::Sprite* s, sf::Time t, double xT, double xTf, double yT, double yTf, double r) 
{
	sprite = s;
	duration = (double)t.asMicroseconds();
	startTime = 0.0;

	sf::Vector2f pos = sprite->getPosition();
	sf::Vector2f scale = sprite->getScale();

	rotationStart = sprite->getRotation();
	rotation = r;

	xTranslateStart = pos.x;
	xTranslate = xT;
	xTransformStart = scale.x;
	xTransform = xTf;

	yTranslateStart = pos.y;
	yTranslate = yT;
	yTransformStart = scale.y;
	yTransform = yTf;

	progressRatio = 1.0;

	nextNode = NULL;
}

AnimationNode::~AnimationNode(void)
{
	sprite = NULL;
}


void AnimationNode::start(sf::Time t) {
	startTime = (double)t.asMicroseconds();
}

void AnimationNode::tick(sf::Time t) 
{
	//elapsed time / duration (min restricts from going too far).
	progressRatio = min(fabs((double)t.asMicroseconds()-startTime)/duration, 1.0) ;

	sprite->setPosition((float)(xTranslateStart + progressRatio*xTranslate),(float)(yTranslateStart + progressRatio*yTranslate));
	sprite->setScale((float)(xTransformStart + progressRatio*xTransform), (float)(yTransformStart + progressRatio*yTransform));
	sprite->rotate((float)(rotationStart + progressRatio*rotation));
}

bool AnimationNode::done(void) 
{
	return (progressRatio == 1.0);
}

void AnimationNode::next(AnimationNode* n) { nextNode = n; }

AnimationNode* AnimationNode::next(void) { return nextNode; }
