#ifndef SNOWFALL_PARTICLE_EFFECT_H
#define SNOWFALL_PARTICLE_EFFECT_H

#include "ParticleEffect.h"

namespace gm {
	class SnowfallParticleEffect : public ParticleEffect
	{
	public:
		SnowfallParticleEffect();
		SnowfallParticleEffect(sf::Vector2f& o, int count);
		~SnowfallParticleEffect();
		void createParticle(int i);
	};
}

#endif