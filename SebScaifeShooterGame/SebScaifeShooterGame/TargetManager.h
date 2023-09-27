#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Colliders.h" 
#include "Player.h"

using namespace std;

struct Target {
	float x, y, w, h;
	void update();
	void draw(SDL_Renderer* r, SDL_Texture* t);


};

class TargetManager {
	
public:
	TargetManager(SDL_Renderer* r);
	~TargetManager();

	void init();
	void update();
	void draw();

	void CreateTarget();

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	vector<Target> targets;

};

