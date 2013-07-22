#include "Level.h"

Level::Level(int chunkSize)
{
	this->chunkSize = chunkSize;
	quadrant1.push_back(new boost::ptr_vector<LevelChunk>);
	quadrant1[0].push_back(new LevelChunk(sf::Vector2f(chunkSize, chunkSize), sf::Vector2f(0, 0)));
}

Level::~Level(void)
{

}

void Level::draw(sf::RenderWindow& window)
{
	for(boost::ptr_vector<LevelChunk> i : quadrant1)
		for(LevelChunk lc : i)
		{
			lc.draw(window);
		}
}

void Level::addChunk(LevelChunk lc, sf::Vector2f position)
{

}