#include "GameScreen.h"

GameScreen::GameScreen(void)
{

}

int GameScreen::Run(sf::RenderWindow &window)
{
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Event event;
	sf::View view(sf::Vector2f((float)window.getSize().x/2.0f, (float)window.getSize().y/2.0f), (sf::Vector2f)window.getSize());
	window.setView(view);
	bool running = true;

	levelSize = sf::Vector2f(1024, 768);

	Player player(sf::Vector2f((float)window.getSize().x/2.0f, (float)window.getSize().y/2.0f), 20.0f, sf::Color::White);
	player.setMaximumVelocity(300.0f);

	CollectableObjectManager collidableManager(levelSize);

	while(true == running)
	{
		deltaTime = clock.restart().asSeconds();
		//std::cout << deltaTime << std::endl;

		//event management
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				return (-1);
			}

			if(event.type == sf::Event::KeyPressed)
			{
				switch(event.key.code)
				{
				case sf::Keyboard::Escape:
					return (-1);
					break;
				default:
					break;
				}
			}
		}

		player.updateVelocity(deltaTime);
		checkBoundryCollision(player);
		collidableManager.handleCollision(player, deltaTime);

		//draw management
		window.clear();
		collidableManager.draw(window);
		player.draw(window);
		window.display();
	}

	return (-1);
}

void GameScreen::checkBoundryCollision(Player& player)
{
	float tempPlayerRadius = player.getRadius();
	sf::Vector2f tempPlayerPosition = player.getPosition();
	sf::Vector2f tempTopLeftBoundry = sf::Vector2f(tempPlayerRadius, tempPlayerRadius);
	sf::Vector2f tempBottomRightBoundry = levelSize - tempTopLeftBoundry;

	if(tempPlayerPosition.x < tempTopLeftBoundry.x)
	{
		player.setPositionX(tempTopLeftBoundry.x);
		player.setVelocityX(0.0f);
	}
	if(tempPlayerPosition.x > tempBottomRightBoundry.x)
	{
		player.setPositionX(tempBottomRightBoundry.x);
		player.setVelocityX(0.0f);
	}
	if(tempPlayerPosition.y < tempTopLeftBoundry.y)
	{
		player.setPositionY(tempTopLeftBoundry.y);
		player.setVelocityY(0.0f);
	}
	if(tempPlayerPosition.y > tempBottomRightBoundry.y)
	{
		player.setPositionY(tempBottomRightBoundry.y);
		player.setVelocityY(0.0f);
	}
}