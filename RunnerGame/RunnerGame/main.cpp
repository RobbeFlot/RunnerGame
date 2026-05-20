#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void drawGame(sf::RenderWindow& window, std::vector<sf::Sprite*>& sprites) {
	window.clear(sf::Color::Blue);
	for (sf::Sprite* sprite : sprites) {
		window.draw(*sprite);
	}
	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "Runner Game!");

	std::vector<sf::Sprite*> sprites;

	sf::Texture SteveText;
	if (!SteveText.loadFromFile("Assets/STEVE.png")) {
		std::cout << "Failed to load texture!";
		return -1;
	}
	sf::Sprite STEVE(SteveText);
	sprites.push_back(&STEVE);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		drawGame(window, sprites);
	}
}