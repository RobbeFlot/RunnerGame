#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

sf::Sprite* loadSprite(std::string textPath, std::string textName, std::vector<sf::Sprite*>& sprites, std::map<std::string, sf::Texture*>& textures) {
	sf::Texture* texture = new sf::Texture();

	textures[textName] = texture;
	if (!texture->loadFromFile(textPath)) {
		std::cout << "Failed to load sprite texture at path: " << textPath << '\n';
	}

	sf::Sprite* sprite = new sf::Sprite(*texture);
	sprites.push_back(sprite);
	return sprite;
}

void drawGame(sf::RenderWindow& window, std::vector<sf::Sprite*>& sprites) {
	window.clear(sf::Color::Blue);
	for (sf::Sprite* sprite : sprites) {
		window.draw(*sprite);
	}
	window.display();
}