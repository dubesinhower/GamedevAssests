#include "CollectableObjectManager.h"

CollectableObjectManager::CollectableObjectManager(sf::Vector2f levelSize)
{
	collectableObjects.push_back(CollectableFactory.createCircle(sf::Vector2f(15.0f, 15.0f), 10.0f, sf::Color::Blue));
	collectableObjects.push_back(CollectableFactory.createCircle(sf::Vector2f(50.0f, 15.0f), 10.0f, sf::Color::Red));
	
}

CollectableObjectManager::~CollectableObjectManager(void)
{

}

bool CollectableObjectManager::handleCollision(Player& player, float deltaTime)
{
	bool collision = false;
	if(!collectableObjects.empty())
	{
		for(unsigned int i = 0; i < collectableObjects.size(); i++)
		{
			if(collectableObjects[i].checkForCollision(player.getRadius(), player.getPosition(), player.getVelocity(), deltaTime))
			{
				if((player.getArea()/2.0) >= collectableObjects[i].getArea())
				{
					player.transferObject(collectableObjects, i);
				}
				else
					collision = true;
			}
		}
	}

	if(collision)
		player.setVelocity(sf::Vector2f(0.0f, 0.0f));
	else
		player.integrate(deltaTime);

	return collision;
}

void CollectableObjectManager::draw(sf::RenderWindow& window)
{
	for(auto& object : collectableObjects)
	{
		object.draw(window);
	}
}