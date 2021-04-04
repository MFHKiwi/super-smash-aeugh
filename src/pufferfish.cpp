#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite pufferfish; // Declare pufferfish and texture globally to allow external access.
Texture pufferfishTexture;
Vector2f fishPosition(30.f, 30.f); // Declare fishPosition variable outside of function to avoid resetting when called again.

void createFish() {
	pufferfishTexture.loadFromFile("textures/pufferfish.png"); // Set pufferfish properties.
	pufferfishTexture.setSmooth(true);
	pufferfishTexture.update(pufferfishTexture);
	pufferfish.setTexture(pufferfishTexture);
	pufferfish.setScale(0.5f, 0.5f);
}

void updateFish() {
        if (Keyboard::isKeyPressed(Keyboard::Left)) fishPosition.x  = fishPosition.x - 7.f; // Detect key presses and change fishPosition variables accordingly. Else ifs avoided intentionally to prevent ignoring keystrokes.
        if (Keyboard::isKeyPressed(Keyboard::Right)) fishPosition.x = fishPosition.x + 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Up)) fishPosition.y = fishPosition.y - 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Down)) fishPosition.y = fishPosition.y + 7.f;
	pufferfish.setPosition(fishPosition);
}
