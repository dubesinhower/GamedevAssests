#pragma once
#include <boost\ptr_container\ptr_vector.hpp>
#include "CollectableCircle.h"
#include <iostream>
#include <boost\math\constants\constants.hpp>
#include <math.h>

class Player :
	public CollectableCircle
{
public:
	Player(sf::Vector2f position, float radius, sf::Color color) : CollectableCircle(position, radius, color)
	{
		velocity = sf::Vector2f(0.0f, 0.0f);
	};
	~Player(void);

	void setMaximumVelocity(float maxVelocity) { this->maxVelocity = sf::Vector2f(maxVelocity, maxVelocity); };
	void setVelocity(sf::Vector2f velocity) { this->velocity = velocity; };
	void setVelocityX(float velocityX) { velocity.x = velocityX; };
	void setVelocityY(float velocityY) { velocity.y = velocityY; };
	sf::Vector2f getVelocity() { return velocity; };
	void updateVelocity(float deltaTime);
	void updateSize();
	void integrate(float deltaTime);
	void transferObject(boost::ptr_vector<CollectableObject>& objects, int objectIndex);

private:
	int horizontalMovement;
	int verticalMovement;
	sf::Vector2f acceleration;
	sf::Vector2f maxVelocity;
	sf::Vector2f velocity;
	boost::ptr_vector<CollectableObject> collectedObjects;
};

