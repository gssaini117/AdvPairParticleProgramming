#include "ParticleEffect.h"

using namespace gm;
using namespace sf;

ParticleEffect::ParticleEffect() {
	origin = Vector2f(400, 300);
	pCount = 10;
	createParticleArray();

}

ParticleEffect::ParticleEffect(Vector2f& o, int count) {
	origin = o;
	pCount = count;
	createParticleArray();
}

ParticleEffect::~ParticleEffect() {
	delete[] particles;
}

void ParticleEffect::createParticleArray() {
	particles = new CircleParticle[pCount];
	for (int i = 0; i < pCount; i++) {
		createParticle(i);
	}
}

void ParticleEffect::createParticle(int i) {

}

const sf::Vector2f& ParticleEffect::getOrigin() const {
	return origin;
}

bool ParticleEffect::isAlive() const {
	bool alive = false; 
	for (int i = 0; i < pCount; i++) {
		alive = alive || particles[i].isAlive();
	}
	return alive;
}

void ParticleEffect::update(sf::RenderWindow& window) {
	for (int i = 0; i < pCount; i++) {
		particles[i].update(window);
	}
}

void ParticleEffect::render(sf::RenderWindow& window) {
	for (int i = 0; i < pCount; i++) {
		particles[i].render(window);
	}
}