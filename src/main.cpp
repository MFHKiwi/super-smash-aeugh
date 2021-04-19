#include "pufferfish.hpp"
#include "food.hpp"
#include "enemy.hpp"
#include "font_data.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace sf;
using namespace std;
#define BG_COLOUR Color::White // Colour for window to use.
#define FG_COLOUR Color::Black // Colour for text.
RenderWindow window(VideoMode(1024, 768), "Super Smash ÆÜGH"); // Create window and set its properties.
Font silkscreen;
Event event;
Text scoreText("", silkscreen);
int score = 0;

void redrawWindow() {
        window.clear(BG_COLOUR); 
        window.draw(pufferfish);
        window.draw(carrot);
        window.draw(enemy);
        window.draw(scoreText);
        window.display();
}

int main() {
	bool paused = false;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	silkscreen.loadFromMemory(silkscreen_ttf, silkscreen_ttf_len);
	scoreText.setCharacterSize(35);
	scoreText.setStyle(Text::Regular);
	scoreText.setFillColor(FG_COLOUR);
	createFish(); // Create sprites.
	createFood();
	createEnemy();
	while (window.isOpen()) { // Run until window closed.
		while (window.pollEvent(event)) { // Detect window close.
			if (event.type == Event::Closed) window.close();
        	}
		updateEnemy(); // Call sprite update function.
		score = score + updateFood();
		scoreText.setString("Score: " + to_string(score));
		if (updateFish() == 1) { // Check if fish contacts enemy.
			window.close();
		} else;
		redrawWindow();
		if (Keyboard::isKeyPressed(Keyboard::Escape)) paused = true; // Detect press of ESC.
		while (Keyboard::isKeyPressed(Keyboard::Escape)); // Ignore subsequent press events until released.
		while (paused == true && window.isOpen()) {
			scoreText.setString("Paused");
			redrawWindow();
			while (window.pollEvent(event)) { // Detect window close.
                        	if (event.type == Event::Closed) window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) paused = false;
			while (Keyboard::isKeyPressed(Keyboard::Escape));
		}
	}
	return 0;
}
