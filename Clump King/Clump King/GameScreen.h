#pragma once
#include "Screen.h"
#include <iostream>
#include "Player.h"
#include "CollectableObjectManager.h"
#include "CollectableObject.h"
#include "CollectableCircle.h"

class GameScreen :
	public Screen
{
public:
	GameScreen(void);
	virtual int Run(sf::RenderWindow& window);
	void checkBoundryCollision(Player& player);

private:
	sf::Vector2f levelSize;
};