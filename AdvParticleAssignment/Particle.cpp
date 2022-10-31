#include "Particle.h"

using namespace gm;
using namespace sf;

Particle::Particle() {

}

Particle::~Particle() {

}

void Particle::update(RenderWindow& window) {

}

void Particle::render(RenderWindow& window) {

}

const sf::Vector2f& Particle::getPosition() const {
	return position;
}

const sf::Vector2f& Particle::getVelocity() const {
	return velocity;
}

void Particle::setPosition(const sf::Vector2f& pos) {
	position = pos;
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