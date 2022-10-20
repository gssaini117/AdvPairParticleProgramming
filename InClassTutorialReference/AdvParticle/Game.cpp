#include <cstdlib>
#include "Game.h"

using namespace gm;
using namespace sf;

const int NUM_OBJECTS = 50;

Game::Game() {
	objects = new GameObject* [NUM_OBJECTS];
	for (int i = 0; i < NUM_OBJECTS/2; i++) {
		objects[i] = new HCircle();
		objects[i]->setPosition(Vector2f(375, 275));
		objects[i]->setSize(50);

	}
	for (int i = NUM_OBJECTS/2; i < NUM_OBJECTS; i++) {
		objects[i] = new VCircle();
		objects[i]->setPosition(Vector2f(375, 275));
		objects[i]->setSize(50);

	}
	srand(time(NULL));
}

Game::~Game() {
	for (int i = 0; i < NUM_OBJECTS; i++) {
		delete objects[i];
	}
	delete[] objects;
}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update(sf::RenderWindow& window) {
	for (int i = 0; i < NUM_OBJECTS; i++) {
		objects[i]->update(window);
	}
}

void Game::render(sf::RenderWindow& window) {
	window.clear();
	for (int i = 0; i < NUM_OBJECTS; i++) {
		objects[i]->render(window);
	}
	window.display();
}