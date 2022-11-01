#include "CircleParticle.h"

using namespace gm;
using namespace sf;

// default constructor
CircleParticle::CircleParticle() {
	shape = new CircleShape(50);
	shape->setPosition(350, 250);
	velocity = Vector2f(0.3, -0.3);
	lifespan = 10;
	maxLife = lifespan;
}

// override constructor
CircleParticle::CircleParticle(sf::Vector2f pos, sf::Vector2f vel, int life, float radius, sf::Color c) {
	shape = new CircleShape(radius);
	shape->setPosition(pos);
	shape->setFillColor(c);
	velocity = vel;
	lifespan = life;
	maxLife = lifespan;
	color = c;
}

// destructor
CircleParticle::~CircleParticle() {
	delete shape;
}

void CircleParticle::update(sf::RenderWindow& window) {
	shape->setPosition(Vector2f(shape->getPosition().x + velocity.x, shape->getPosition().y + velocity.y));
	velocity.y += 0.001;
	lifespan--;
}

void CircleParticle::render(sf::RenderWindow& window) {
	window.draw(*shape);
}

float CircleParticle::getRadius() {
	return shape->getRadius();
}

void CircleParticle::setRadius(float radius) {
	shape->setRadius(radius);
}

void CircleParticle::fade() {
	color.a = 255 * lifespan / maxLife;
	shape->setFillColor(color);
}