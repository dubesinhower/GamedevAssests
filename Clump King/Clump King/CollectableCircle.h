#pragma once
#include "CollectableObject.h"
#include <boost\math\constants\constants.hpp>
#include <math.h>
#include "Circle.h"

class CollectableCircle :
	public CollectableObject
{
public:
	CollectableCircle(sf::Vector2f position, float radius, sf::Color color) : circle(position, radius, color) { };
	~CollectableCircle(void);

	void setPosition(sf::Vector2f position) { circle.setPosition(position); };
	void setPositionX(float xPosition) { circle.setPosition(sf::Vector2f(xPosition, circle.getPosition().y)); };
	void setPositionY(float yPosition) { circle.setPosition(sf::Vector2f(circle.getPosition().x, yPosition)); };
	void setRadius(float radius) { circle.setRadius(radius);	};
	void offsetPosition(sf::Vector2f positionOffset) { circle.offsetPosition(positionOffset); };
	sf::Vector2f getPosition() { return circle.getPosition(); };
	float getRadius() { return circle.getRadius(); };
	float getArea()	{ return circle.getArea(); };
	bool checkForCollision(float playerRadius, sf::Vector2f playerPosition, sf::Vector2f playerVelocity, float deltaTime);
	void draw(sf::RenderWindow& window) { circle.draw(window); };

private:
	Circle circle;
};