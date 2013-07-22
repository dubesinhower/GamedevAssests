#pragma once
#include "CollectableCircle.h"

class CollectableFactory
{
public:
	CollectableCircle* createCircle(sf::Vector2f position, float radius, sf::Color color) { return new CollectableCircle(position, radius, color); };
};