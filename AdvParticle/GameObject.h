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
	
	const int MinMovement = -3;
	const int MaxMovement = 3;

	class GameObject {
	private:
		sf::CircleShape* shape;
	public:
		GameObject();
		GameObject(const sf::Vector2f& position, float size);
		~GameObject();
		virtual void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		void setPosition(const sf::Vector2f& position);
		void setSize(float radius);
	};
}

#endif