#pragma once

#include <SDL.h>
#include <SDL_image.h>

#define MAP_SIZE_X 18
#define MAP_SIZE_Y 14

#define MAP_TILE_SIZE_PX 64

class TileMap {
public:
	TileMap(SDL_Renderer*);
	~TileMap();
	void init();
	void draw();

	// A 2D array of integers which represent the different tiles that make up the map:
	// imagine the source map to be a zero-index array, incrementing horizontally from the top-left to the bottom-right
	const int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] = {
		{4,5,5,5,5,5,5,5,5,5,5,2,3,3,3,3,3,6},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{8,9,9,9,9,9,9,9,9,9,9,2,1,1,1,1,1,10},
		{12,13,13,13,13,13,13,13,13,13,13,2,15,15,15,15,15,14}
	};

private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* mapTileSet  = nullptr;
};

