#ifndef SOUND_HPP
#define SOUND_HPP
#include <SFML/Audio.hpp>
using namespace sf;

class CustomSound {
	private:
		SoundBuffer buffer;
	public:
		Sound sound;
		CustomSound(unsigned char* soundPointer, size_t soundPointer_len) {
			buffer.loadFromMemory(soundPointer, soundPointer_len);
			sound.setBuffer(buffer);
		}
};

#endif
