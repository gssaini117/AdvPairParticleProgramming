#include "Particle.h"

using namespace gm;
using namespace sf;

Particle::Particle() {
	velocity = Vector2f(0, 0);
	lifespan = 0;
}

Particle::~Particle() {

}

void Particle::update(RenderWindow& window) {
	shape->setPosition(Vector2f(shape->getPosition().x + velocity.x, shape->getPosition().y + velocity.y));
	velocity.y += 0.001;
}

void Particle::render(RenderWindow& window) {
	window.draw(*shape);
}

const sf::Vector2f& Particle::getPosition() const {
	return shape->getPosition();
}

const sf::Vector2f& Particle::getVelocity() const {
	return velocity;
}

void Particle::setPosition(const sf::Vector2f& pos) {
	shape->setPosition(pos);
}

void Particle::setVelocity(const sf::Vector2f& vel) {
	velocity = vel;
}

int Particle::getLifespan() {
	return lifespan;
}

void Particle::setLifespan(const int life) {
	lifespan = life;
}

bool Particle::isAlive() {
	return lifespan > 0;
}