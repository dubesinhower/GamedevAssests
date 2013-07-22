#pragma once
#include "Level.h"

class LevelManager
{
public:
	LevelManager(void);
	~LevelManager(void);

	void draw(sf::RenderWindow& window);

private:
	Level* theLevel;
};