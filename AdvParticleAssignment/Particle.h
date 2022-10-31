#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class Particle {
	protected:
		sf::Vector2f position;
		sf::Vector2f velocity;
		int lifespan;
	public:
		Particle();
		~Particle();
		virtual void update(sf::RenderWindow& window);
		virtual void render(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getVelocity() const;
		void setPosition(const sf::Vector2f& pos);
		void setVelocity(const sf::Vector2f& vel);
		int getLifespan();
		void setLifespan(const int life);
		bool isAlive();
	};
}

#endif