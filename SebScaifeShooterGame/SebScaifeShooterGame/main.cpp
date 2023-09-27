#include "GameLoop.h"

#undef main

GameLoop* gameLoop = nullptr;

int main() {
	gameLoop = new GameLoop();

	if (!gameLoop->init()) // i.e. if the game does not successfully initialise
	{
		return 1;
	}

	// As long as the game is processing inputs, the update and draw functions will run. This is why processInput is a bool.
	// keep in mind processInput will return true for as long as the input isn't the X at the top right of the window
	while (gameLoop->processInput()) 
	{
		gameLoop->update();
		gameLoop->draw();
	}

	// After the game has stopped processing input
	gameLoop->clean();

	delete gameLoop;

	return 0;
}	