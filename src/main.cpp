#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Super Smash ÆÜGH");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);
    window.clear(sf::Color::White);
    sf::Texture texture;
    texture.loadFromFile("textures/pufferfish.png");
    texture.update(texture);
    texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);
    float xpos = 30.f, ypos = 30.f;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		xpos = xpos - 7.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		xpos = xpos + 7.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                ypos = ypos - 7.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                ypos = ypos + 7.f;
        }
	sprite.setPosition(xpos, ypos);
	window.clear(sf::Color::White);
	window.draw(sprite);
	window.display();
    }

    return 0;
}
