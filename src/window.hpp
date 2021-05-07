#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class CustomWindow {
	private:
		Image icon;
	public:
		RenderWindow window;
		CustomWindow(int xres, int yres, String title, unsigned char* iconPointer, size_t iconPointer_len) {
			window.create(VideoMode(xres, yres), title);
			icon.loadFromMemory(iconPointer, iconPointer_len);
			window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		}
};

#endif
