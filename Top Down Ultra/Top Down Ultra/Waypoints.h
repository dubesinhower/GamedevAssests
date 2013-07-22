#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Waypoints
{
public:
	void addPoint(sf::Vector2f point) { points.push_back(point); };
	void addPointsFromVector(std::vector<sf::Vector2f> pointVector) { points.insert(points.end(), pointVector.begin(), pointVector.end()); };
	void setPoint(sf::Vector2f point) 
	{
		points.clear();
		points.push_back(point);
	};
	void setPointsFromVector(std::vector<sf::Vector2f> pointVector)
	{
		points.clear();
		points.insert(points.end(), pointVector.begin(), pointVector.end());
	}
	void clearPoint() { points.erase(points.begin()); };
	sf::Vector2f getNext() { return points[0]; };
	bool isEmpty() 
	{
		if(points.empty())
			return true;
		else
			return false;
	};

private:
	std::vector<sf::Vector2f> points;
};

