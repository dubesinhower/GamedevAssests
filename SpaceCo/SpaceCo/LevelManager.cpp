#include "LevelManager.h"

LevelManager::LevelManager(void)
{
	theLevel = new Level(10000);
}

LevelManager::~LevelManager(void)
{
	delete theLevel;
}

void LevelManager::draw(sf::RenderWindow& window)
{
	theLevel->draw(window);
}