#ifndef FIREWORK_PARTICLE_EFFECT_H
#define FIREWORK_PARTICLE_EFFECT_H

#include "ParticleEffect.h"

namespace gm {
	class FireworkParticleEffect : public ParticleEffect
	{
	public:
		FireworkParticleEffect();
		FireworkParticleEffect(sf::Vector2f& o, int count);
		~FireworkParticleEffect();
		void createParticle(int i);
	};
}

#endif