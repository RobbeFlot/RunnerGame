#include "GameObject.hpp"

GameObject::GameObject(sf::Sprite* sprite, sf::Vector2f pos) {
	this->sprite = sprite;
	this->pos = pos;
}

void GameObject::move() {
	pos.x -= 10;
}

void GameObject::updatePos() {
	sprite->setPosition(pos);
}