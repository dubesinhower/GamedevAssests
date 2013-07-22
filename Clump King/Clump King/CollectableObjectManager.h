#pragma once
#include "CollectableFactory.h"
#include "Player.h"
#include <boost\ptr_container\ptr_vector.hpp>
#include <iostream>
#include <vector>

class CollectableObjectManager
{
public:
	CollectableObjectManager(sf::Vector2f levelSize);
	~CollectableObjectManager(void);

	bool handleCollision(Player& player, float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	CollectableFactory CollectableFactory;
	boost::ptr_vector<CollectableObject> collectableObjects;
};