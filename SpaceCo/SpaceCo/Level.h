#pragma once
#include "LevelChunk.h"
#include "SFML\Graphics.hpp"
#include "boost\ptr_container\ptr_vector.hpp"

class Level
{
public:
	Level(int chunkSize);
	~Level(void);

	void draw(sf::RenderWindow& window);

private:
	int chunkSize;
	boost::ptr_vector<boost::ptr_vector<LevelChunk> > quadrant1;

	void addChunk(LevelChunk lc, sf::Vector2f position);
};