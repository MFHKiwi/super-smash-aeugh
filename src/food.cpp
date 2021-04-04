#include "food.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite carrot;
Texture carrotTexture;

void createFood() {
	carrotTexture.loadFromFile("textures/carrot.png");
	carrotTexture.setSmooth(true);
	carrotTexture.update(carrotTexture);
	carrot.setTexture(carrotTexture);
	carrot.setScale(0.3f, 0.3f);
	carrot.setRotation(45.f);
}

void updateFood() {
	if (carrot.getGlobalBounds().intersects(pufferfish.getGlobalBounds())) {
	        int randomX = rand() % 1000 + 1;
        	int randomY = rand() % 1000 + 1;
        	Vector2f foodPosition(static_cast<float>(randomX), static_cast<float>(randomY));
        	carrot.setPosition(foodPosition);
	}
}
