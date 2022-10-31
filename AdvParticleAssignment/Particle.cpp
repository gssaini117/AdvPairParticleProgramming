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

int Particle::getLifespan() {
	return lifespan;
}

void Particle::setLifespan(const int life) {
	lifespan = life;
}

bool Particle::isAlive() {
	return lifespan > 0;
}