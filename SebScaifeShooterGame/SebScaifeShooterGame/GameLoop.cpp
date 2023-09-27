#include <iostream>
#include "GameLoop.h"

GameLoop::GameLoop()
{
	window = nullptr;
	renderer = nullptr;

	player = nullptr;
	tileMap = nullptr;
	scoreText = nullptr;
	targetManager = nullptr;
}

// Check if everything is working and the programme can run
bool GameLoop::init() {
	//a variety of criteria under which the game cannot start; return false for each
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not initialise SDL! SDL error: \n" << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Seb Scaife Shooter Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1152, 896, SDL_WINDOW_SHOWN); // create the window for the game to display on
	if (window == NULL)
	{	
		std::cerr << "Could not create window! SDL Error: \n" << SDL_GetError() << std::endl; // console out an error message if the window cannot be made. 
		return false;
	} 
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
	{
		std::cerr << "Could not create renderer! SDL Error: \n" << SDL_GetError() << std::endl; // console out an error message if the window cannot be made. 
		return false;
	}

	// Initialise all the necessary classes (players, maps etc.)
	//tilemap is declared and initialised before the player etc. so that it is furthest in the background; likewise, text UI is declared last
	tileMap = new TileMap(this->renderer);
	tileMap->init();

	player = new Player(this->renderer);
	player->init();

	bm = new BulletManager(this->renderer, this->player);
	bm->init();

	targetManager = new TargetManager(this->renderer);
	targetManager->init();

	scoreText = new FontManager(this->renderer);
	scoreText->init();

	return true;
}

// Check if any input has been done and act accordingly
bool GameLoop::processInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		// close the window when the window is closed haha xd
		if (e.type == SDL_QUIT)
			return false;

		player->processInput(e);
		bm->processInput(e);
	}

	return true;
}

void GameLoop::update() {
	player->update();
	bm->update();
	targetManager->update();
	scoreText->update(player->GetScore());
}

void GameLoop::draw() {
	SDL_RenderClear(renderer);

	// All draw methods from other classes
	tileMap->draw();
	player->draw();
	bm->draw();
	targetManager->draw();
	scoreText->draw();


	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	player->clean();
	bm->clean();

	SDL_Quit();
}