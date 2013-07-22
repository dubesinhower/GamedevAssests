#include "Player.h"
#include <iostream>

Player::~Player(void)
{

}

void Player::updateVelocity(float deltaTime)
{
	float accelerationMultiplyer = 1000.0f;

	//deccelerate and change movement if no keys are pressed
	acceleration = sf::Vector2f(-accelerationMultiplyer * deltaTime, -accelerationMultiplyer * deltaTime);
	verticalMovement = horizontalMovement = 0;

	//otherwise apply acceleration and change movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		acceleration.y = accelerationMultiplyer * deltaTime;
		verticalMovement = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		acceleration.x = accelerationMultiplyer * deltaTime;
		horizontalMovement = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		acceleration.y = accelerationMultiplyer * deltaTime;
		verticalMovement = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		acceleration.x = accelerationMultiplyer * deltaTime;
		horizontalMovement = -1;
	}

	if(horizontalMovement > 0)
	{
		velocity.x += acceleration.x;
	}
	else if(horizontalMovement < 0)
	{
		velocity.x -= acceleration.x;
	}
	else
	{
		if(velocity.x > -acceleration.x)
			velocity.x += acceleration.x;
		else if(velocity.x < acceleration.x)
			velocity.x -= acceleration.x;
		else
			velocity.x = 0.0f;
	}

	if(verticalMovement > 0)
	{
		velocity.y -= acceleration.y;
	}
	else if(verticalMovement < 0)
	{
		velocity.y += acceleration.y;
	}
	else
	{
		if(velocity.y > -acceleration.y)
			velocity.y += acceleration.y;
		else if(velocity.y < acceleration.y)
			velocity.y -= acceleration.y;
		else
			velocity.y = 0.0f;
	}

	if(horizontalMovement > 0 && velocity.x > maxVelocity.x)
		velocity.x = maxVelocity.x;
	if(horizontalMovement < 0 && velocity.x < -maxVelocity.x)
		velocity.x = -maxVelocity.x;
	if(verticalMovement > 0 && velocity.y < -maxVelocity.y)
		velocity.y = -maxVelocity.y;
	if(verticalMovement < 0 && velocity.y > maxVelocity.y)
		velocity.y = maxVelocity.y;

	// std::cout << velocity.x << "," << velocity.y << std::endl;
}

void Player::integrate(float deltaTime)
{
	offsetPosition(velocity * deltaTime);
}

void Player::transferObject(boost::ptr_vector<CollectableObject>& objects, int objectIndex)
{
	collectedObjects.transfer(collectedObjects.end(), objects.begin() + objectIndex, objects);
	updateSize();
}

void Player::updateSize()
{
	float areaRatio = 0.1f;
	float tempArea = 0.0f;
	for(auto& object : collectedObjects)
	{
		tempArea += object.getArea();
	}

	float pi = boost::math::constants::pi<float>();
	float tempRadius = tempArea/pi;
	tempRadius = sqrt(tempRadius);
	setRadius(getRadius() + tempRadius * areaRatio);
	//std::cout << "radius: " << getRadius() << std::endl;
}