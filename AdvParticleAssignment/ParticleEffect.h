#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Particle.h"
#include "CircleParticle.h"
#include "Random.h"

namespace gm {
	class ParticleEffect {
	protected:
		Particle* particles;
		sf::Vector2f origin;
		int pCount;
	public:
		ParticleEffect();
		ParticleEffect(sf::Vector2f& o, int count);
		~ParticleEffect();
		void createParticleArray();
		virtual void createParticle(int i);
		const sf::Vector2f& getOrigin() const;
		bool isAlive() const;
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
	};
}

#endif