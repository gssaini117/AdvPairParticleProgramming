#include "GameObject.h"

using namespace sf;
using namespace gm;

GameObject::GameObject() {
	shape = new CircleShape();
}

GameObject::GameObject(const sf::Vector2f& position, float size) {
	shape = new sf::CircleShape(size);
	shape->setPosition(position);
	shape->setFillColor(Color::White);
}

GameObject::~GameObject() {
	delete shape;
}

void GameObject::update(sf::RenderWindow& window) {
	int randomMovementX = rand() % 7 - 3;
	int randomMovementY = rand() % 7 - 3;

	shape->setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y + randomMovementY));
}

void GameObject::render(sf::RenderWindow& window) {
	window.draw(*shape);
}

const Vector2f& GameObject::getPosition() const {
	return shape->getPosition();
}

void GameObject::setPosition(const Vector2f& position) {
	shape->setPosition(position);
}

void GameObject::setSize(float radius) {
	shape->setRadius(radius);
}