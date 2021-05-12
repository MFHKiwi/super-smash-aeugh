#ifndef TEXT_HPP
#define TEXT_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class CustomText {
	private:
		Font font;
	public:
		Text text;
		CustomText(unsigned char* fontPointer, size_t fontPointer_len, int characterSize, Text::Style style, Color colour, string textString) {
			font.loadFromMemory(fontPointer, fontPointer_len);
			text.setFont(font);
			text.setStyle(style);
			text.setFillColor(colour);
			text.setString(textString);
		}
};
#endif
