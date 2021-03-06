// PingPong.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "interfejs.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "info.h"

using namespace std;
void StartGame(sf::RenderWindow &window, bool computer)
{
	Ball ball(WIDTH / 2, HEIGHT / 2);

	if (computer == 0)
	{
		

	}
	else
	{

	}

}

int main()
{
	sf::RenderWindow window{ sf::VideoMode(WIDTH, HEIGHT), "PING PONG" };
	window.setFramerateLimit(36);
	sf::CircleShape shape(400.f);
	shape.setFillColor(sf::Color::Green);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem()) {
					case 0:
						StartGame(window, 0);
						break;
					case 1:
						StartGame(window, 1);
						break;
					case 2:
						ShowResults();
						break;
					case 3:
						window.close();
						break;
					}
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
		window.clear(sf::Color::Black);
		menu.draw(window);
		window.display();
	}
	return 0;
}

