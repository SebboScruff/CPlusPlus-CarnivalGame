#include "TileMap.h"

extern TileMap* tileMap;

TileMap::TileMap(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->mapTileSet = nullptr;
}

TileMap::~TileMap() {}

void TileMap::init() {
	SDL_Surface* s = IMG_Load("../SebScaifeShooterGame/Assets/CarnivalTileSet2.png");
	this->mapTileSet = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);
}

/*	This draw function uses a series equations to fill the on-screen map
*	with tiles on the source map, converting a number in the 2D array MAP_DATA
*	to a 32x32 tile on the source map.
*/
void TileMap::draw() {
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			// images in the tile map png are 32x32px, arranged in a 4x4 grid
			SDL_Rect srcRect = { (MAP_DATA[i][j] % 4) * 32, (MAP_DATA[i][j] / 4) * 32, 32, 32 }; // a formula for finding the corresponding tile in the tilemap to a number in the MAP_DATA array

			SDL_Rect destRect = { j * MAP_TILE_SIZE_PX, i * MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX };
			SDL_RenderCopy(renderer, mapTileSet, &srcRect, &destRect);
		}
	}
}