#include "food.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite carrot;
Texture carrotTexture;

void createFood() {
	carrotTexture.loadFromFile("textures/carrot.png");
	carrotTexture.setSmooth(true);
	carrot.setTexture(carrotTexture);
	carrot.setScale(0.3f, 0.3f);
	carrot.setRotation(45.f);
}

void updateFood() {
	if (carrot.getGlobalBounds().intersects(pufferfish.getGlobalBounds())) {
		reroll:
	        int randomX = rand() % window.getSize().x + 1;
        	int randomY = rand() % window.getSize().y + 1;
        	Vector2f foodPosition(static_cast<float>(randomX), static_cast<float>(randomY));
        	carrot.setPosition(foodPosition);
		if (carrot.getGlobalBounds().intersects(pufferfish.getGlobalBounds())) goto reroll; // If the new positoin is inside of the pufferfish, reroll.
	}
}
