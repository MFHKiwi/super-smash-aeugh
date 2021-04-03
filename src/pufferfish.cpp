#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
Sprite pufferfish; // Declare pufferfish and texture globally to allow external access.
Texture pufferfishTexture;
Vector2f position(30.f, 30.f); // Declare position variable outside of function to avoid resetting when called again.

void createFish() {
	pufferfishTexture.loadFromFile("textures/pufferfish.png"); // Set pufferfish properties.
	pufferfishTexture.setSmooth(true);
	pufferfishTexture.update(pufferfishTexture);
	pufferfish.setTexture(pufferfishTexture);
	pufferfish.setScale(0.5f, 0.5f);
}

void updateFish() {
        if (Keyboard::isKeyPressed(Keyboard::Left)) position.x  = position.x - 7.f; // Detect key presses and change position variables accordingly. Else ifs avoided intentionally to prevent ignoring keystrokes.
        if (Keyboard::isKeyPressed(Keyboard::Right)) position.x = position.x + 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Up)) position.y = position.y - 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Down)) position.y = position.y + 7.f;
	pufferfish.setPosition(position);
}
