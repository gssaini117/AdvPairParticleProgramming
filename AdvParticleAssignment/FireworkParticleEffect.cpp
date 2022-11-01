#include "FireworkParticleEffect.h"

using namespace gm;
using namespace sf;

FireworkParticleEffect::FireworkParticleEffect() {
	origin = Vector2f(400, 300);
	pCount = 100;
	createParticleArray();
}

FireworkParticleEffect::FireworkParticleEffect(Vector2f& o, int count) {
	origin = o;
	pCount = count;
	createParticleArray();
}

FireworkParticleEffect::~FireworkParticleEffect() {
	for (int i = 0; i < pCount; i++)
		delete particles[i];
	delete[] particles;
}

void FireworkParticleEffect::createParticle(int i) {
	int r = Random::Range(225, 255);
	int g = Random::Range(100, 200);
	int b = Random::Range(0, 20);
	Color orange = Color(r, g, b);

	float xVel = Random::Range((float) -0.4, 0.4);
	float yVel = Random::Range((float) -0.2, -0.4);
	if (xVel < 0.25 && xVel > -0.25) yVel = Random::Range((float) -0.2, -0.6);
	if (xVel < 0.1 && xVel > -0.1) yVel = Random::Range((float) -0.2, -0.75);
	Vector2f vel = Vector2f(xVel, yVel);
	
	particles[i] = new CircleParticle(origin, vel, 800, 15, orange);
}