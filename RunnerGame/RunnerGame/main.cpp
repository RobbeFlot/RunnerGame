#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "Runner Game!");

	sf::Texture SteveText;
	if (!SteveText.loadFromFile("Assets/STEVE.png")) {
		std::cout << "Failed to load texture!";
		return -1;
	}
	sf::Sprite STEVE(SteveText);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		window.draw(STEVE);
		window.display();
	}
}