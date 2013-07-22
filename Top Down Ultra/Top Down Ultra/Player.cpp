#include "Player.h"
#include <iostream>

Player::~Player(void)
{

}

void Player::update(float deltaTime)
{
	if(!waypoints.isEmpty())
	{
		sf::Vector2f nextPoint = waypoints.getNext();
		sf::Vector2f position = getPosition();
		sf::Vector2f tempVector(nextPoint.x - position.x, nextPoint.y - position.y);
		float magnitude = sqrt(pow(tempVector.x, 2) + pow(tempVector.y, 2));
		sf::Vector2f normalVector(tempVector / magnitude);
		normalVector = normalVector * topSpeed * deltaTime;

		if(pow((position.x - nextPoint.x), 2) + pow((position.y - nextPoint.y), 2) < pow(1 * topSpeed * deltaTime, 2))
		{
			setPosition(nextPoint);
			waypoints.clearPoint();
			setStartingPosition(getPosition());
		}
		else
		{
			velocity = normalVector;
			offsetPosition(velocity);
		}
	}
}