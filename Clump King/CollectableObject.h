#pragma once
#include <SFML\Graphics.hpp>
#include "Shape.h"

class CollectableObject
{
public:
	virtual ~CollectableObject() {};
	virtual float getArea() { return shape.getArea(); };
	virtual void draw(sf::RenderWindow& window) { shape.draw(window); };
	virtual bool checkForCollision(float playerRadius, sf::Vector2f playerPosition, sf::Vector2f playerVelocity, float deltaTime) { return NULL; };

private:
	Shape shape;
};