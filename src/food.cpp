#include "food.hpp"
#include "food_data.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
Sprite carrot;
Texture carrotTexture;

Vector2f randomV2f() {
	srand(time(NULL));
	int randomX = rand() % window.getSize().x; // Generate random numbers + logic to prevent carrot from spawning off-screen.
	randomX = (randomX > window.getSize().x / 2)? randomX : randomX + carrot.getGlobalBounds().width;
        int randomY = rand() % window.getSize().y;
	randomY = (randomY > window.getSize().y / 2)? randomY - carrot.getGlobalBounds().height : randomY;
	Vector2f output(static_cast<float>(randomX), static_cast<float>(randomY));
	return output;
}

void createFood() {
	carrotTexture.loadFromMemory(carrot_png, carrot_png_len);
	carrotTexture.setSmooth(true);
	carrot.setTexture(carrotTexture);
	carrot.setScale(0.3f, 0.3f);
	carrot.setRotation(45.f);
	carrot.setPosition(randomV2f());
}

int updateFood() {
	if (carrot.getGlobalBounds().intersects(pufferfish.getGlobalBounds())) {
		reroll:
        	carrot.setPosition(randomV2f());
		if (carrot.getGlobalBounds().intersects(pufferfish.getGlobalBounds())) goto reroll; // If the new positoin is inside of the pufferfish, reroll.
		return 1;
	} else return 0;
}
