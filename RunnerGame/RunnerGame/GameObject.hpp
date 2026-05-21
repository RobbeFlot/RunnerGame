#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
	sf::Sprite* sprite;
	sf::Vector2f pos;

	GameObject(sf::Sprite* sprite, sf::Vector2f pos);

	virtual void move();

	virtual void updatePos();
};