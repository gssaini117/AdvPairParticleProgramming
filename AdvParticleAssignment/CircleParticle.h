#ifndef CIRCLEPARTICLE_H
#define CIRCLEPARTICLE_H

#include "Particle.h"
#include "Random.h"

namespace gm {
	class CircleParticle : public Particle {
	protected:
		sf::CircleShape* shape; 
		sf::Color color;
		int maxLife;
	public:
		CircleParticle();
		CircleParticle(sf::Vector2f pos, sf::Vector2f vel, int lifespan, float radius, sf::Color color);
		~CircleParticle();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		float getRadius();
		void setRadius(float radius);
		void fade();
	};
}

#endif