#include "HCircle.h"

using namespace gm;
using namespace sf;

void HCircle::update(sf::RenderWindow& window) {
	int randomMovementX = rand() % 7 - 3;

	setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y));
}
