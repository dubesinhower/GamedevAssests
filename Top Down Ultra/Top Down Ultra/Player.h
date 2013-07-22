#pragma once
#include "Waypoints.h"
#include "Movable.h"
#include "Combat.h"
#include <boost\ptr_container\ptr_vector.hpp>
#include <boost\math\constants\constants.hpp>
#include <iostream>
#include <math.h>

class Player : public Movable, public Combat
{
public:
	Player(sf::Vector2f position, float radius, sf::Color color, float topSpeed, float accelerationTime, int healthPoints, int armorPoints, int shieldPoints, int basicAttackDamage) : 
		Movable(position, radius, color, topSpeed, accelerationTime), 
		Combat(healthPoints, armorPoints, shieldPoints) {};
	~Player(void);
	
	//public interface
	void setWaypoint(sf::Vector2f point) { waypoints.setPoint(point); };
	void addWaypoint(sf::Vector2f point) { waypoints.addPoint(point); };
	void update(float deltaTime);

private:

	//members
	Waypoints waypoints;
};

