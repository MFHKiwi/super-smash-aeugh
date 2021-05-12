#include "font_data.hpp"
#include "icon_data.hpp"
#include "pufferfish_data.hpp"
#include "enemy_data.hpp"
#include "food_data.hpp"
#include "death_sound.hpp"
#include "eat_sound.hpp"
#include "sprite.hpp"
#include "sound.hpp"
#include "window.hpp"
#include "randomV2f.hpp"
#include "text.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;
const string version = "Beta v1.0.2";

int main(int argc, char* argv[]) {
	float speed = 3.7f / 33333.3333333f;
	if (argc > 1) { // Run if command line argument given.
		string arg = argv[1];
		if ((arg == "-e") || (arg == "--easy")) speed = 2.2f / 33333.3333333f; // Activate easy mode if easy flag is given.
		else;
		if ((arg == "-h") || (arg == "--help")) {
			cout << "\nSuper Smash ÆÜGH Help\n" << version << "\n\n-h, --help: print this help message\n-e, --easy: make enemy move slower\n";
			return 0;
		}
	}
	Clock gameClock;
	Font silkscreen;
	silkscreen.loadFromMemory(silkscreen_ttf, silkscreen_ttf_len);
	CustomText scoreText(silkscreen_ttf, silkscreen_ttf_len, 35, Text::Regular, Color::Black, "");
	CustomText versionText(silkscreen_ttf, silkscreen_ttf_len, 35, Text::Regular, Color::Black, version);
	CustomWindow window(1024, 768, "Super Smash AEUGH", icon_png, icon_png_len);
	versionText.text.setPosition(window.window.getSize().x - versionText.text.getGlobalBounds().width - 10.f, 0.f);
	window.window.setVerticalSyncEnabled(true);
	CustomSprite pufferfish(pufferfish_png, pufferfish_png_len, 0.4f, 0.4f, 0.f, 30.f, 30.f);
	CustomSprite carrot(carrot_png, carrot_png_len, 0.3f, 0.3f, 45.f, randomV2f(window));
	CustomSound death(death_wav, death_wav_len);
	CustomSound eat(eat_wav, eat_wav_len);
	int score = 0;
	bool paused = false;
	do {
		carrot.teleport(randomV2f(window, carrot));
	} while (carrot.touches(pufferfish));
	CustomSprite enemy(enemy_png, enemy_png_len, 0.6f, 0.6f, 0.f, window.window.getSize().x, window.window.getSize().y);
	while (window.window.isOpen()) {
		Time elapsedSinceLastTick = gameClock.restart(); // Get time stamp since last time this code was run.
		Event event;
		while (window.window.pollEvent(event)) { // Detect window close.
                        if (event.type == Event::Closed) window.window.close();
			if (event.type == Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.window.setView(sf::View(visibleArea));
				versionText.text.setPosition(window.window.getSize().x - versionText.text.getGlobalBounds().width - 10.f, 0.f);
			}
                }
		// Detect keystrokes and move fish within window bounds.
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && !(pufferfish.sprite.getPosition().x <= 0)) {
			pufferfish.move(CustomSprite::left, 0.00021f * elapsedSinceLastTick.asMicroseconds());
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) && !(pufferfish.sprite.getPosition().x + pufferfish.sprite.getGlobalBounds().width >= window.window.getSize().x)) {
			pufferfish.move(CustomSprite::right, 0.00021f * elapsedSinceLastTick.asMicroseconds());
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && !(pufferfish.sprite.getPosition().y <= 0)) {
			pufferfish.move(CustomSprite::up, 0.00021f * elapsedSinceLastTick.asMicroseconds());
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && !(pufferfish.sprite.getPosition().y + pufferfish.sprite.getGlobalBounds().height >= window.window.getSize().y)) {
			pufferfish.move(CustomSprite::down, 0.00021f * elapsedSinceLastTick.asMicroseconds());
		}
		if (carrot.touches(pufferfish)) { // Detect collision with carrot.
			do {
				carrot.teleport(randomV2f(window, carrot));
			} while (carrot.touches(pufferfish));
			score = score + 1;
			eat.sound.play();
		}
		FloatRect enemyBoundingBox(enemy.sprite.getGlobalBounds().left + 20.f, enemy.sprite.getGlobalBounds().top + 25.f, enemy.sprite.getGlobalBounds().width - 50.f, enemy.sprite.getGlobalBounds().height - 30.f);
		if (pufferfish.sprite.getPosition().x > enemy.sprite.getPosition().x) enemy.move(CustomSprite::right, speed * elapsedSinceLastTick.asMicroseconds());
		if (pufferfish.sprite.getPosition().x < enemy.sprite.getPosition().x) enemy.move(CustomSprite::left, speed * elapsedSinceLastTick.asMicroseconds());
		if (pufferfish.sprite.getPosition().y > enemy.sprite.getPosition().y) enemy.move(CustomSprite::down, speed * elapsedSinceLastTick.asMicroseconds());
                if (pufferfish.sprite.getPosition().y < enemy.sprite.getPosition().y) enemy.move(CustomSprite::up, speed * elapsedSinceLastTick.asMicroseconds());
		if (pufferfish.touches(enemyBoundingBox)) { // Detect collision with enemy.
			death.sound.play();
			while (death.sound.getStatus() != Sound::Status::Stopped);
			window.window.close();
		}
		window.window.clear(Color::White);
		window.window.draw(pufferfish.sprite);
		window.window.draw(carrot.sprite);
		window.window.draw(enemy.sprite);
		scoreText.text.setString("Score: " + to_string(score));
		while (Keyboard::isKeyPressed(Keyboard::Escape)) {
                        paused = true;
                        scoreText.text.setString("Paused");
                }
		window.window.draw(scoreText.text);
		window.window.draw(versionText.text);
		window.window.display();
                while (paused == true && window.window.isOpen()) {
                        while (window.window.pollEvent(event)) { // Detect window close.
                                if (event.type == Event::Closed) window.window.close();
				if (event.type == Event::Resized) {
                          		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                                	window.window.setView(sf::View(visibleArea));
					versionText.text.setPosition(window.window.getSize().x - versionText.text.getGlobalBounds().width - 10.f, 0.f);
                        	}
                        }
                        while (Keyboard::isKeyPressed(Keyboard::Escape)) {
                                paused = false;
                                gameClock.restart();
                        }
                }
	}
	return 0;
}
