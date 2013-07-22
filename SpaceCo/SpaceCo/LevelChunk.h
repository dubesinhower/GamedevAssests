#pragma once
#include "SFML\Graphics.hpp"
#include "Circle.h"
#include "boost\ptr_container\ptr_vector.hpp"

class LevelChunk
{
public:
	LevelChunk(sf::Vector2f chunkSize, sf::Vector2f position);
	~LevelChunk(void);

	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f chunkSize;
	sf::Vector2f position;

	boost::ptr_vector<Circle> test;
};

