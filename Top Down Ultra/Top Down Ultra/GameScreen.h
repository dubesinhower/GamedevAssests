#pragma once
#include "Screen.h"
#include <iostream>
#include "Player.h"

class GameScreen :
	public Screen
{
public:
	GameScreen(void);
	virtual int Run(sf::RenderWindow& window);

private:
	sf::Vector2f levelSize;
};