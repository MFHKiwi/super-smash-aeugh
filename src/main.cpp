#include "pufferfish.hpp"
#include "food.hpp"
#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
#define BG_COLOUR Color::White // Colour for window to use.
RenderWindow window(VideoMode(800, 600), "Super Smash ÆÜGH"); // Create window and set its properties.

int main() {
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	createFish(); // Create pufferfish.
	createFood();
	createEnemy();
	while (window.isOpen()) { // Run until window closed.
		Event event; // Detect window closing event.
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
        	}
		updateFish(); // Call pufferfish update function.
		updateFood();
		window.clear(BG_COLOUR); // Redraw window.
		window.draw(pufferfish);
		window.draw(carrot);
		window.draw(enemy);
		window.display();
	}
	return 0;
}
