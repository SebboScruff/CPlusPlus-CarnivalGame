#include <iostream>

#include "TargetManager.h"

// STUFF FOR INDIVIDUAL TARGETS

void Target::update() {
	//TODO move targets downwards continually
}

void Target::draw(SDL_Renderer* r, SDL_Texture* t) {
	SDL_Rect destRect = {this->x, this->y, this->w, this->h};
	SDL_RenderCopy(r, t, 0, &destRect);
}


// STUFF FOR TARGET MANAGER

TargetManager::TargetManager(SDL_Renderer* renderer) {

	this->renderer = renderer;

}

TargetManager::~TargetManager(){}

void TargetManager::init() {
	SDL_Surface* surface = IMG_Load("../SebScaifeShooterGame/Assets/Target.png");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	CreateTarget();

}

void TargetManager::update() {
	// do the update loop for each target in the vector
	for (auto& t : targets) { t.update(); }
}

void TargetManager::draw() {
	for (auto& t : targets) { t.draw(this->renderer, this->texture); }
}

void TargetManager::CreateTarget() {
	std::cout << "Creating a new target" << std::endl;
	targets.push_back(Target{ 800, 400, 90, 90 });
}
