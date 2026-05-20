#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

sf::Sprite& loadSprite(std::string textPath, std::string textName, std::vector<sf::Sprite*>& sprites, std::map<std::string, sf::Texture*>& textures) {
	sf::Texture* texture = new sf::Texture();

	textures[textName] = texture;
	if (!texture->loadFromFile(textPath)) {
		std::cout << "Failed to load sprite texture at path: " << textPath << '\n';
	}

	sf::Sprite* sprite = new sf::Sprite(*texture);
	sprites.push_back(sprite);
	return *sprite;
}

void drawGame(sf::RenderWindow& window, std::vector<sf::Sprite*>& sprites) {
	window.clear(sf::Color::Blue);
	for (sf::Sprite* sprite : sprites) {
		std::cout << sprite;
		window.draw(*sprite);
	}
	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "Runner Game!");

	std::vector<sf::Sprite*> sprites;
	std::map<std::string, sf::Texture*> textures;

	sf::Sprite Steve = loadSprite("Assets/STEVE.png", "STEVE", sprites, textures);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		drawGame(window, sprites);
	}
}