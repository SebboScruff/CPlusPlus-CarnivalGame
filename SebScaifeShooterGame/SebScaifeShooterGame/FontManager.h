#pragma once

#include <SDL_ttf.h>
#include <string>
#include <iostream>

class FontManager {
public:
	FontManager(SDL_Renderer* renderer) {
		this->renderer = renderer;
		this->font = nullptr;
		this->texture = nullptr;
		this->surface = nullptr;

		this->textPos.x = 1152, this->textPos.y = 896;
		textWidth = 300, textHeight = 50;
		textColour = {212, 40, 40}; // this is a dark red so that it will stand out against the tile map background
	}
	~FontManager() {
		texture = nullptr;
		TTF_CloseFont(font);
		font = nullptr;
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
		TTF_Quit();
	}
	// Check if all the TTF stuff initialises correctly
	bool init() {
		if (TTF_Init() == -1)
		{
			std::cerr << "SDL_ttf could not be initialised! TTF Error: \n" << TTF_GetError() << std::endl;
			return false;
		}

		// Give a value to the font variable
		font = TTF_OpenFont("../SebScaifeShooterGame/Assets/scoreFont.ttf", 35);
		if (font == nullptr)
		{
			std::cerr << "Font not found! TTF Error: \n" << TTF_GetError() << std::endl;
			return false;
		}

		return true;
	}

	// this is a bool so it will stop during runtime if stuff goes south
	bool update(const std::string& textureText) {
		SDL_DestroyTexture(this->texture);

		surface = TTF_RenderText_Solid(font, textureText.c_str(), textColour);
		if (surface == nullptr)
		{
			std::cerr << "Could not render text surface! TTF Error: \n" << TTF_GetError() << std::endl;
			return false;
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (texture == nullptr)
			{
				std::cerr << "Font not found! TTF Error: \n" << TTF_GetError() << std::endl;
				return false;
			}
			else
			{
				textWidth = surface->w;
				textHeight = surface->h;
			}
			SDL_FreeSurface(surface);
		}
		// align the text to the top-right corner of the screen
		textPos.x = 1152 - textWidth;
		textPos.y = 0;

		textPos.w = textWidth;
		textPos.h = textHeight;

		return true;
	}

	void draw() {
		SDL_RenderCopy(this->renderer, this->texture, 0, &this->textPos);
	}


private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Surface* surface;
	SDL_Rect textPos;
	
	int textWidth, textHeight;
	SDL_Color textColour;

};
