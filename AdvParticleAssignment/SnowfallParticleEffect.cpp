#include "SnowfallParticleEffect.h"

using namespace gm;
using namespace sf;

SnowfallParticleEffect::SnowfallParticleEffect() {
	origin = Vector2f(400, 300);
	pCount = 100;
	createParticleArray();
}

SnowfallParticleEffect::SnowfallParticleEffect(Vector2f& o, int count) {
	origin = o;
	pCount = count;
	createParticleArray();
}

SnowfallParticleEffect::~SnowfallParticleEffect() {
	for (int i = 0; i < pCount; i++)
		delete particles[i];
	delete[] particles;
}

void SnowfallParticleEffect::createParticle(int i) {
	int gray = Random::Range(200, 255);
	Color grey = Color(gray, gray, gray, gray);

	float xPos = Random::Range((float) -400.0, 400.0);
	float yPos = std::abs(xPos) * 0.05;
	Vector2f pos = Vector2f(origin.x + xPos, origin.y + yPos);

	float xVel = Random::Range((float) -0.1, 0.1);
	float yVel = Random::Range((float) -0.1, 0.1);
	Vector2f vel = Vector2f(xVel, yVel);

	particles[i] = new CircleParticle(pos, vel, 800, Random::Range(10, 20), grey);
}
