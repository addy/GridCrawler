#include "AnimationNode.h"


AnimationNode::AnimationNode(void)
{
}


AnimationNode::~AnimationNode(void)
{
}

void AnimationNode::tick(sf::Time t) {} //needs current time to update the location of the sprite.

bool AnimationNode::done() { return false; }

void AnimationNode::next(AnimationNode* n) { nextNode = n; }

AnimationNode* AnimationNode::next(void) { return nextNode; }
