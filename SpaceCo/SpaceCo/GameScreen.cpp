#include "GameScreen.h"

GameScreen::GameScreen(void)
{

}

int GameScreen::run(sf::RenderWindow &window)
{
	float viewSpeed = 1000.0f;

	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Event event;
	sf::Vector2f windowSize = (sf::Vector2f)window.getSize();
	view.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
	
	bool running = true;

	Player player;

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
			if(event.type == sf::Event::MouseButtonPressed)
			{

			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			view.move(sf::Vector2f(0.0f, viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			view.move(sf::Vector2f(0.0f, -viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			view.move(sf::Vector2f(viewSpeed*deltaTime, 0.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			view.move(sf::Vector2f(-viewSpeed*deltaTime, 0.0f));
		}

		//draw management
		window.clear();
		window.setView(view);
		lm.draw(window);
		window.display();
	}

	return (-1);
}