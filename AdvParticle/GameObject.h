#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class GameObject {
	private:
		sf::CircleShape* shape;
	public:
		GameObject();
		GameObject(const sf::Vector2f& position, float size);
		~GameObject();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		void setPosition(const sf::Vector2f& position);
		void setSize(float radius);
	};
}

#endif