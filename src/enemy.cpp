#include "enemy.hpp"
#include "enemy_data.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite enemy;
Texture enemyTexture;
Vector2f enemyPosition(static_cast<Vector2f>(window.getSize()));

void createEnemy() {
	enemyTexture.loadFromMemory(enemy_png, enemy_png_len); // Load texture.
	enemyTexture.setSmooth(true); // Set properties.
	enemy.setTexture(enemyTexture);
	enemy.setScale(0.7f, 0.7f);
	enemy.setPosition(enemyPosition);
}

void updateEnemy() {
	if (pufferfish.getPosition().x > enemy.getPosition().x) enemyPosition.x = enemyPosition.x + 3.5f; // Go towards location of pufferfish at half its speed.
	if (pufferfish.getPosition().x < enemy.getPosition().x) enemyPosition.x = enemyPosition.x - 3.5f;
	if (pufferfish.getPosition().y > enemy.getPosition().y) enemyPosition.y = enemyPosition.y + 3.5f;
	if (pufferfish.getPosition().y < enemy.getPosition().y) enemyPosition.y = enemyPosition.y - 3.5f;
	enemy.setPosition(enemyPosition);
}
