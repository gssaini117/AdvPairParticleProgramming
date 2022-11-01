#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {
    particles = new CircleParticle* [MAX_EFFECTS];
    for (int i = 0; i < MAX_EFFECTS; i++) {
        particles[i] = nullptr;
    }
}

Game::~Game() {
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (particles[i]) delete particles[i];
    }
    delete[] particles;
}

void Game::inputs(RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close(); // closes window
        // creates new effect
        if (event.type == sf::Event::MouseButtonPressed) {

            // casting mouse from Vector2i to Vector2f
            Vector2i mouse = Mouse::getPosition(window);
            Vector2f fMouse = Vector2f((float)mouse.x, (float)mouse.y);

            // iterate to allocate new 
            int cursor = 0;
            while (particles[cursor]) {
                cursor++;
                if (cursor >= MAX_EFFECTS) {
                    delete particles[0];
                    particles[0] = nullptr;
                    cursor = 0;
                }
            }

            // left click creates
            if (event.mouseButton.button == Mouse::Left) {
                CircleParticle* circle = new CircleParticle(fMouse, Vector2f(0.3, -0.3), 1000, 20, Color::Red);
                particles[cursor] = circle;
            }
            // right click creates
            if (event.mouseButton.button == Mouse::Right) {
                CircleParticle* circle = new CircleParticle(fMouse, Vector2f(-0.3, -0.3), 1000, 20, Color::Blue);
                particles[cursor] = circle;
            }
        }
    }
}

void Game::update(RenderWindow& window) {
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (particles[i]) {
            particles[i]->update(window);
            if (!particles[i]->isAlive()) {
                delete particles[i];
                particles[i] = nullptr;
            }
        }
    }
}

void Game::render(RenderWindow& window) {
    window.clear();
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (particles[i]) {
            particles[i]->render(window);
        }
    }
    window.display();
}