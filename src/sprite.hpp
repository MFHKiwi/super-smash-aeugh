#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class CustomSprite {
        private:
                Texture spriteTexture;
        public:
                Sprite sprite;
		enum Direction {left, right, up, down};
		CustomSprite(unsigned char* texturePointer, size_t texturePointer_len, float xscale, float yscale, float rotation, float xpos, float ypos) {
			spriteTexture.loadFromMemory(texturePointer, texturePointer_len);
			sprite.setTexture(spriteTexture);
			sprite.setScale(xscale, yscale);
			sprite.setRotation(rotation);
			sprite.setPosition(xpos, ypos);
		}

                CustomSprite(unsigned char* texturePointer, size_t texturePointer_len, float xscale, float yscale, float rotation, Vector2f position) {
                        spriteTexture.loadFromMemory(texturePointer, texturePointer_len);
                        sprite.setTexture(spriteTexture);
                        sprite.setScale(xscale, yscale);
                        sprite.setRotation(rotation);
                        sprite.setPosition(position);
                }

		void move(Direction direction, float distance) {
			if (direction == left) sprite.setPosition(sprite.getPosition().x - distance, sprite.getPosition().y);
			else if (direction == right) sprite.setPosition(sprite.getPosition().x + distance, sprite.getPosition().y);
			else if (direction == up) sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - distance);
			else if (direction == down) sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + distance);
		}

		void teleport(float xpos, float ypos) {
			sprite.setPosition(xpos, ypos);
		}

		void teleport(Vector2f position) {
			sprite.setPosition(position);
		}

		bool touches(CustomSprite otherSprite) {
			if (sprite.getGlobalBounds().intersects(otherSprite.sprite.getGlobalBounds())) return true;
			else return false;
		}

		bool touches(FloatRect rectangle) {
                        if (sprite.getGlobalBounds().intersects(rectangle)) return true;
                        else return false;
                }

};

#endif
