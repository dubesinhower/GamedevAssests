#pragma once
#include "Screen.h"
#include <iostream>
#include "Player.h"
#include "LevelManager.h"
#include "Circle.h"

class GameScreen :
	public Screen
{
public:
	GameScreen(void);
	virtual int run(sf::RenderWindow& window);
	void update(float deltaTime);

private:
	LevelManager lm;
	sf::View view;
};