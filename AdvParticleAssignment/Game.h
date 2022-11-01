#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleEffect.h"
#include "FireworkParticleEffect.h"
#include "SnowfallParticleEffect.h"
#include "Particle.h"
#include "CircleParticle.h"


namespace gm {
	class Game {
	private:
		const int MAX_EFFECTS = 30;
		ParticleEffect** effects;
	public:
		Game();										// Constructor
		~Game();									// Destructor
		void inputs(sf::RenderWindow& window);		// Inputs
		void update(sf::RenderWindow& window);		// Update
		void render(sf::RenderWindow& window);		// Render
	};
}

#endif