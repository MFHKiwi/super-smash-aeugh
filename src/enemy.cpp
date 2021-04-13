#include "enemy.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite enemy;
Texture enemyTexture;

void createEnemy() {
	enemyTexture.loadFromFile("textures/gordon-ramsay.png");
	enemyTexture.setSmooth(true);
	enemy.setTexture(enemyTexture);
	enemy.setScale(0.9f, 0.9f);
	enemy.setPosition(30.f, 150.f);
}

void updateEnemy() {
	
}
