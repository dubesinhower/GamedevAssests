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

	Player player(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f), 15.0f, sf::Color::White, 250.0f, 1.0f, 100, 100, 100, 10);

	levelSize = sf::Vector2f(1024, 768);

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
				if(event.mouseButton.button == sf::Mouse::Right)
				{
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
						player.addWaypoint(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y));
					else
						player.setWaypoint(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y));
				}
			}
		}

		player.update(deltaTime);

		//draw management
		window.clear();
		player.draw(window);
		window.display();
	}


	return (-1);
}