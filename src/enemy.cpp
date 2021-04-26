#include "enemy.hpp"
#include "enemy_data.hpp"
#include "pufferfish.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Sprite enemy;
Texture enemyTexture;
Vector2f enemyPosition(static_cast<Vector2f>(window.getSize()));
float speed;

void createEnemy() {
	enemyTexture.loadFromMemory(enemy_png, enemy_png_len); // Load texture.
	enemyTexture.setSmooth(true); // Set properties.
	enemy.setTexture(enemyTexture);
	enemy.setScale(0.7f, 0.7f);
	enemy.setPosition(enemyPosition);
	if (easy == true) speed = 2.2f;
	else speed = 3.5f;
}

void updateEnemy() {
	float movePerMicrosecond = speed / 33333.3333333f;
	if (pufferfish.getPosition().x > enemy.getPosition().x + 3.5f) enemyPosition.x = enemyPosition.x + movePerMicrosecond * elapsed.asMicroseconds(); // Go towards location of pufferfish at the selected movePerMicrosecond * elapsed.asMicroseconds(). Allow up to an offset of 3.5 to avoid jittering from side to side.
	if (pufferfish.getPosition().x < enemy.getPosition().x) enemyPosition.x = enemyPosition.x - movePerMicrosecond * elapsed.asMicroseconds();
	if (pufferfish.getPosition().y > enemy.getPosition().y + 3.5f) enemyPosition.y = enemyPosition.y + movePerMicrosecond * elapsed.asMicroseconds();
	if (pufferfish.getPosition().y < enemy.getPosition().y) enemyPosition.y = enemyPosition.y - movePerMicrosecond * elapsed.asMicroseconds();
	enemy.setPosition(enemyPosition);
}
