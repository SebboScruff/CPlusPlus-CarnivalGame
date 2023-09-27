#pragma once

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "GameLoop.h"
#include "TileMap.h"

class TileMap;

class Player {
public:
	Player(SDL_Renderer* r);
	~Player();

	void init();
	void processInput(SDL_Event e);
	void update();
	void draw();
	void clean();


	void SetPosition(int x, int y);


	int GetX();
	int GetY();
	float GetShootingPointX();
	float GetShootingPointY();

	const std::string GetScore();

	void SetCurrentBullets(int bullets);
	int GetCurrentBullets();

private:
	TileMap* map;

	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Rect position;

	int score;
	int maxBullets = 10;
	int currentBullets;
};
