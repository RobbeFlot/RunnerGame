#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <map>

#include "Helper.hpp"

int main()
{
	bool playing = true;

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "Runner Game!");

	std::vector<sf::Sprite*> sprites;
	std::map<std::string, sf::Texture*> textures;

	sf::Sprite* Bg1 = loadSprite("Assets/BG-1B.png", "Bg1", sprites, textures);
	sf::Sprite* Bg2 = loadSprite("Assets/BG-2B.png", "Bg2", sprites, textures);
	Bg2->setPosition({ 1000, 0 });
	sf::Sprite* G1 = loadSprite("Assets/Ground.png", "G1", sprites, textures);
	G1->setPosition({ 0, 440 });
	sf::Sprite* G2 = loadSprite("Assets/Ground.png", "G1", sprites, textures);
	G2->setPosition({ 1000, 440 });
	sf::Sprite* Steve = loadSprite("Assets/STEVE.png", "STEVE", sprites, textures);

	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		if (playing) {
			//scrolling background
			Bg1->move({ -100.f * deltaTime.asSeconds(), 0.f});
			Bg2->move({ -100.f * deltaTime.asSeconds(), 0.f });
			if (Bg1->getPosition().x <= -1000) {
				Bg1->setPosition({ 1000, 0 });
			}
			if (Bg2->getPosition().x <= -1000) {
				Bg2->setPosition({ 1000, 0 });
			}

			//scrolling ground
			G1->move({ -100.f * deltaTime.asSeconds(), 0.f });
			G2->move({ -100.f * deltaTime.asSeconds(), 0.f });
			if (G1->getPosition().x <= -1000) {
				G1->setPosition({ 1000, 440 });
			}
			if (G2->getPosition().x <= -1000) {
				G2->setPosition({ 1000, 440 });
			}
		}

		drawGame(window, sprites);
	}
}