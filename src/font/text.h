#ifndef FONT_TEXT_H
#define FONT_TEXT_H


//Render a text string to a texture, for fast text rendering.


#include "sdl/texture.h"

#include <string>

class Font;

namespace sdl {
class Renderer;
}

//XXX so far this only caters for ASCII text.
//TODO add UTF-8 support


class Text
{
public:
	Text();
	Text(const sdl::Renderer &rend, Font &font, const std::string &str);

	//Block copy, implement move
	Text(const Text &copy) = delete;
	Text(Text &&move) = default;
	Text& operator=(const Text &copy) = delete;
	Text& operator=(Text &&move) = default;

private:
	sdl::Texture texture;
	std::string str;

	int width = 0;
	int height = 0;

public:
	const sdl::Texture& GetTexture() const { return texture; }

	int GetWidth() const { return width; }
	int GetHeight() const { return height; }


	void SetText(const sdl::Renderer &rend, Font &font, const std::string &newstr);

	void Render(const sdl::Renderer &rend, int x, int y) const;
};

#endif // FONT_TEXT_H
