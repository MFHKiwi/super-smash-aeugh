#ifndef RANDOMV2F_HPP
#define RANDOMV2F_HPP
#include "sprite.hpp"
#include "window.hpp"
#include <ctime>
using namespace sf;

Vector2f randomV2f(CustomWindow& window) {
	for (static bool first = true; first; first=false) {
		srand(time(NULL));
	}
	int randomX = rand() % window.window.getSize().x;
	int randomY = rand() % window.window.getSize().y;
	Vector2f output(static_cast<float>(randomX), static_cast<float>(randomY));
	return output;
}

Vector2f randomV2f(CustomWindow& window, CustomSprite& sprite) {
        for (static bool first = true; first; first=false) {
                srand(time(NULL));
        }
	int randomX = rand() % window.window.getSize().x; // Generate random numbers.
        int randomY = rand() % window.window.getSize().y;
        randomX = (randomX > window.window.getSize().x / 2)? randomX : randomX + sprite.sprite.getGlobalBounds().width;
        randomY = (randomY > window.window.getSize().y / 2)? randomY - sprite.sprite.getGlobalBounds().height : randomY;
        Vector2f output(static_cast<float>(randomX), static_cast<float>(randomY));
        return output;
}

#endif
