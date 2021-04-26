#include "pufferfish.hpp"
#include "food.hpp"
#include "enemy.hpp"
#include "font_data.hpp"
#include "icon_data.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;
#define BG_COLOUR Color::White // Colour for window to use.
#define FG_COLOUR Color::Black // Colour for text.
RenderWindow window(VideoMode(1024, 768), "Super Smash AEUGH"); // Create window and set its properties.
Font silkscreen;
Event event;
Image icon;
Text scoreText("", silkscreen);
int score = 0;
bool easy = false;
Clock clocktime;
Time elapsed;

void redrawWindow() {
        window.clear(BG_COLOUR); 
        window.draw(pufferfish);
        window.draw(carrot);
        window.draw(enemy);
        window.draw(scoreText);
        window.display();
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		string arg = argv[1];
		if ((arg == "-e") || (arg == "--easy")) easy = true;
		else easy = false;
		if ((arg == "-h") || (arg == "--help")) {
			cout << "-h, --help: print this help message\n-e, --easy: make enemy move slower\n";
			return 0;
		}
	}
	bool paused = false;
	icon.loadFromMemory(icon_png, icon_png_len);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	silkscreen.loadFromMemory(silkscreen_ttf, silkscreen_ttf_len);
	scoreText.setCharacterSize(35);
	scoreText.setStyle(Text::Regular);
	scoreText.setFillColor(FG_COLOUR);
	createFish(); // Create sprites.
	createFood();
	createEnemy();
	while (window.isOpen()) { // Run until window closed.
		elapsed = clocktime.restart();
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
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				paused = false;
				clocktime.restart();
			}
			while (Keyboard::isKeyPressed(Keyboard::Escape));
		}
	}
	return 0;
}
