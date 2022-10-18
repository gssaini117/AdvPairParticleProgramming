#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;
using namespace gm;

int main()
{
    // Create the window for the game
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Game game;

    // This is our game loop!
    // All input, logic, and rendering should be handled here
    while (window.isOpen())
    {
        // Our game object handles the game loop programming pattern
        game.handleInput(window);

        game.update(window);

        game.render(window);
    }

    // The game has exited normally so send a normal exit status integer back
    return 0;
}