#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <map>

#include "Helper.hpp"
#include "GameObject.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "Runner Game!");

	std::vector<sf::Sprite*> sprites;
	std::map<std::string, sf::Texture*> textures;

	sf::Sprite* tempSprite = loadSprite("Assets/STEVE.png", "STEVE", sprites, textures);
	GameObject Steve(tempSprite);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		drawGame(window, sprites);
	}
}