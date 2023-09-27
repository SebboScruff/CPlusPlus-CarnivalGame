#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <math.h>
#include <algorithm>

#include "Player.h"
#include "Colliders.h"

using namespace std;

class Player;

class BulletManager {
public:
	BulletManager(SDL_Renderer* renderer, Player* player);

	struct Bullet
	{
		float x, y, distance;
		
	};

	void init();

	void processInput(SDL_Event e);

	void update();

	void draw();

	void clean();

private:
	Player* player;

	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Texture* uiTextureWhole;
	SDL_Texture* uiTextureEmpty;
	//SDL_Rect uiBulletPos[10];

	vector<SDL_Rect> uiBulletPos;
	vector<Bullet> bullets;

	const int SHOOT_TIME_MS = 300;
	const int BULLET_SPEED = 15;
	unsigned int lastShot = 0;
	int recoilDistance = 20;

};