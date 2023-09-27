#pragma once

#include <SDL.h>
#include "Player.h"
#include "TileMap.h"
#include "FontManager.h"
#include "BulletManager.h"
#include "TargetManager.h"


class Player;
class BulletManager;
class TargetManager;

class GameLoop {

public:
	GameLoop();

	bool init();

	bool processInput();

	void update();

	void draw();

	void clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Player* player;
	BulletManager* bm;
	TileMap* tileMap;
	FontManager* scoreText;
	TargetManager* targetManager;
};