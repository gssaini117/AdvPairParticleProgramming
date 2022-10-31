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
	class Particle
	{
	private:
		int lifespan;
	public:
		Particle();
		~Particle();
		virtual void update(sf::RenderWindow& window);
		virtual void render(sf::RenderWindow& window);
		int getLifespan();
		void setLifespan(const int life);
		bool isAlive();
	};
}

#endif