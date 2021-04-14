#include "enemy.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite enemy;
Texture enemyTexture;
Vector2f enemyPosition(30.f, 150.f);

void createEnemy() {
	enemyTexture.loadFromFile("textures/gordon-ramsay.png");
	enemyTexture.setSmooth(true);
	enemy.setTexture(enemyTexture);
	enemy.setScale(0.9f, 0.9f);
	enemy.setPosition(enemyPosition);
}

void updateEnemy() {
	if (pufferfish.getPosition().x > enemy.getPosition().x) enemyPosition.x = enemyPosition.x + 7.f;
	if (pufferfish.getPosition().x < enemy.getPosition().x) enemyPosition.x = enemyPosition.x - 7.f;
	enemy.setPosition(enemyPosition);
}
