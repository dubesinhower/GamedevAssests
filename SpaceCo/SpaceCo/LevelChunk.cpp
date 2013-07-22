#include "LevelChunk.h"

LevelChunk::LevelChunk(sf::Vector2f chunkSize, sf::Vector2f position)
{
	this->chunkSize = chunkSize;
	this->position = position;
	test.push_back(new Circle(sf::Vector2f(512.0f, 512.0f), 20.0f, sf::Color::White));
}

LevelChunk::~LevelChunk(void)
{

}

void LevelChunk::draw(sf::RenderWindow& window)
{
	for(Circle circle : test)
	{
		circle.draw(window);
	}
}