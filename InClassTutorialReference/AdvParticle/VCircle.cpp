#include "VCircle.h"

using namespace gm;
using namespace sf;

void VCircle::update(sf::RenderWindow& window) {
	int randomMovementY = rand() % 7 - 3;

	setPosition(Vector2f(getPosition().x, getPosition().y + randomMovementY));
}
