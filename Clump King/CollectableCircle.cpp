#include "CollectableCircle.h"
#include <iostream>

CollectableCircle::~CollectableCircle(void)
{

}

bool CollectableCircle::checkForCollision(float playerRadius, sf::Vector2f playerPosition, sf::Vector2f playerVelocity, float deltaTime)
{
	playerVelocity = playerVelocity * deltaTime;

	float c = playerRadius + circle.getRadius();
	c *= c;

	float a = (playerPosition.x + playerVelocity.x) - circle.getPosition().x;
	a *= a;

	float b = (playerPosition.y + playerVelocity.y) - circle.getPosition().y;
	b *= b;

	//std::cout << a + b << " ----- " << c << std::endl; 

	if(c < a + b)
		return false;
	else if(c >= a + b)
		return true;

	return false;
}