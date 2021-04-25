#include "pufferfish.hpp"
#include "pufferfish_data.hpp"
#include "death_sound.hpp"
#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
Sprite pufferfish;
Texture pufferfishTexture;
SoundBuffer deathBuffer;
Sound death;
Vector2f fishPosition(30.f, 30.f); // Declare fishPosition variable outside of function to avoid resetting when called again.
int delay = 0;
const float movePerMillisecond = 0.21f;

void createFish() {
	pufferfishTexture.loadFromMemory(pufferfish_png, pufferfish_png_len); // Set texture.
	pufferfishTexture.setSmooth(true); // Set properties
	pufferfish.setTexture(pufferfishTexture);
	pufferfish.setScale(0.4f, 0.4f);
	deathBuffer.loadFromMemory(death_wav, death_wav_len); // Load sound effect.
	death.setBuffer(deathBuffer);
}

int updateFish() {
        if (Keyboard::isKeyPressed(Keyboard::Left)) fishPosition.x  = fishPosition.x - movePerMillisecond * elapsed.asMilliseconds(); // Detect key presses and change fishPosition variables accordingly. Else ifs avoided intentionally to prevent ignoring keystrokes.
        if (Keyboard::isKeyPressed(Keyboard::Right)) fishPosition.x = fishPosition.x + movePerMillisecond * elapsed.asMilliseconds();
        if (Keyboard::isKeyPressed(Keyboard::Up)) fishPosition.y = fishPosition.y - movePerMillisecond * elapsed.asMilliseconds();
        if (Keyboard::isKeyPressed(Keyboard::Down)) fishPosition.y = fishPosition.y + movePerMillisecond * elapsed.asMilliseconds();
	if (pufferfish.getPosition().x <= 0) fishPosition.x = fishPosition.x + movePerMillisecond * elapsed.asMilliseconds(); // Detect collision with window borders.
	if (pufferfish.getPosition().y <= 0) fishPosition.y = fishPosition.y + movePerMillisecond * elapsed.asMilliseconds();
	if (pufferfish.getPosition().x + pufferfish.getGlobalBounds().width >= window.getSize().x) fishPosition.x = fishPosition.x - movePerMillisecond * elapsed.asMilliseconds();
	if (pufferfish.getPosition().y + pufferfish.getGlobalBounds().height >= window.getSize().y) fishPosition.y = fishPosition.y - movePerMillisecond * elapsed.asMilliseconds();
	pufferfish.setPosition(fishPosition);
	if (pufferfish.getGlobalBounds().intersects(enemy.getGlobalBounds())) { // Detect collision with enemy.
		delay++;
		if (delay == 10) { // Give 333ms buffer zone (30 fps / 3).
			death.play(); // Play death sound effect.
			while (death.getStatus() != Sound::Status::Stopped); // Wait for sound effect to stop.
			return 1;
		}
	}
	else delay = 0;
	return 0;
}
