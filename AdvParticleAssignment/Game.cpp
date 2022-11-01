#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {
    effects = new ParticleEffect* [MAX_EFFECTS];
    for (int i = 0; i < MAX_EFFECTS; i++) {
        effects[i] = nullptr;
    }
}

Game::~Game() {
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (effects[i]) delete effects[i];
    }
    delete[] effects;
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
            while (effects[cursor]) {
                cursor++;
                if (cursor >= MAX_EFFECTS) {
                    delete effects[0];
                    effects[0] = nullptr;
                    cursor = 0;
                }
            }

            // left click creates
            if (event.mouseButton.button == Mouse::Left) {
                FireworkParticleEffect* firework = new FireworkParticleEffect(fMouse, 50);
                effects[cursor] = firework;
            }
            // right click creates
            if (event.mouseButton.button == Mouse::Right) {
                SnowfallParticleEffect* snowfall = new SnowfallParticleEffect(fMouse, 200);
                effects[cursor] = snowfall;
            }
        }
    }
}

void Game::update(RenderWindow& window) {
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (effects[i]) {
            effects[i]->update(window);
            if (!effects[i]->isAlive()) {
                delete effects[i];
                effects[i] = nullptr;
            }
        }
    }
}

void Game::render(RenderWindow& window) {
    window.clear();
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (effects[i]) {
            effects[i]->render(window);
        }
    }
    window.display();
}