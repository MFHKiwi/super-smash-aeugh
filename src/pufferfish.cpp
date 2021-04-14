#include "pufferfish.hpp"
#include "enemy.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite pufferfish; // Declare pufferfish and texture globally to allow external access.
Texture pufferfishTexture;
Vector2f fishPosition(30.f, 30.f); // Declare fishPosition variable outside of function to avoid resetting when called again.

void createFish() {
	pufferfishTexture.loadFromFile("textures/pufferfish.png"); // Set pufferfish properties.
	pufferfishTexture.setSmooth(true);
	pufferfish.setTexture(pufferfishTexture);
	pufferfish.setScale(0.4f, 0.4f);
}

int updateFish() {
        if (Keyboard::isKeyPressed(Keyboard::Left)) fishPosition.x  = fishPosition.x - 7.f; // Detect key presses and change fishPosition variables accordingly. Else ifs avoided intentionally to prevent ignoring keystrokes.
        if (Keyboard::isKeyPressed(Keyboard::Right)) fishPosition.x = fishPosition.x + 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Up)) fishPosition.y = fishPosition.y - 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Down)) fishPosition.y = fishPosition.y + 7.f;
	if (pufferfish.getPosition().x <= 0) fishPosition.x = fishPosition.x + 7.f; // Detect collision with window borders.
	if (pufferfish.getPosition().y <= 0) fishPosition.y = fishPosition.y + 7.f;
	if (pufferfish.getPosition().x + pufferfish.getGlobalBounds().width >= window.getSize().x) fishPosition.x = fishPosition.x - 7.f;
	if (pufferfish.getPosition().y + pufferfish.getGlobalBounds().width >= window.getSize().y) fishPosition.y = fishPosition.y - 7.f;
	pufferfish.setPosition(fishPosition);
	if (pufferfish.getGlobalBounds().intersects(enemy.getGlobalBounds())) return 1;
	else return 0;
}
