#include "pufferfish.hpp"
#include "food.hpp"
#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace sf;
using namespace std;
#define BG_COLOUR Color::White // Colour for window to use.
#define FG_COLOUR Color::Black // Colour for text.
RenderWindow window(VideoMode(1024, 768), "Super Smash ÆÜGH"); // Create window and set its properties.
Font silkscreen;
Text scoreText("", silkscreen);
int score = 0;

int main() {
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	silkscreen.loadFromFile("textures/silkscreen.ttf");
	scoreText.setCharacterSize(35);
	scoreText.setStyle(Text::Regular);
	scoreText.setFillColor(FG_COLOUR);
	createFish(); // Create sprites.
	createFood();
	createEnemy();
	while (window.isOpen()) { // Run until window closed.
		Event event; // Detect window closing event.
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
        	}
		updateEnemy(); // Call sprite update function.
		score = score + updateFood();
		scoreText.setString("Score: " + to_string(score));
		if (updateFish() == 1) { // Check if fish contacts enemy.
			window.close();
		} else;
		window.clear(BG_COLOUR); // Redraw window.
		window.draw(pufferfish);
		window.draw(carrot);
		window.draw(enemy);
		window.draw(scoreText);
		window.display();
	}
	return 0;
}
