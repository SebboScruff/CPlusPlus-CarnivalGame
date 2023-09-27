#include <iostream>

#include "Player.h"

// Set up an enum to determine which keys are being pressed
// This makes the inputs a very fluid system programatically, as more inputs can just be added here very simply
enum KeyStates {
	LEFT = 0,
	RIGHT,
	UP,
	DOWN,
	KEYSTATES_COUNT // since enums are 0 indexed, having an 'unused' key at the end allows the length of the enum to be accessed
};
bool keyStates[KeyStates::KEYSTATES_COUNT];

Player::Player(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->texture = nullptr;

	// initialise Rect properties (position and scale) when the player class is created
	this->position.x = 0;
	this->position.y = 0;

	this->position.w = 92;
	this->position.h = 128;

	this->currentBullets = 0;
	this->map = nullptr;
}

Player::~Player() {}

void Player::init() {
	// Set up the player texture
	SDL_Surface* surface = IMG_Load("../SebScaifeShooterGame/Assets/PlayerSprite2.png");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	// Initialise position etc.
	this->position.x = 0;
	this->position.y = 0;

	this->position.w = 92;
	this->position.h = 128;

	this->score = 0;
	this->currentBullets = this->maxBullets;

	this->map = new TileMap(this->renderer);
}

void Player::processInput(SDL_Event e) {
	// Detect Key Down Inputs, activating boolean keystates accordingly.
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			keyStates[LEFT] = true;
			break;
		case SDLK_RIGHT:
			keyStates[RIGHT] = true;
			break;
		case SDLK_UP:
			keyStates[UP] = true;
			break;
		case SDLK_DOWN:
			keyStates[DOWN] = true;
			break;
		default:
			break;
		}
	}
	// Detect Key Up Inputs
	if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			keyStates[LEFT] = false;
			break;
		case SDLK_RIGHT:
			keyStates[RIGHT] = false;
			break;
		case SDLK_UP:
			keyStates[UP] = false;
			break;
		case SDLK_DOWN:
			keyStates[DOWN] = false;
			break;
		default:
			break;
		}
	}

}

void Player::update() {
	//store previous location for use with tilemap collisions
	int oldX = position.x;
	int oldY = position.y;

	
	// Movement based on keystate bools
	// Additionally, switch to left/right facing when appropriate
	if (keyStates[LEFT]) {
		this->SetPosition(this->GetX() - 5, this->GetY());
	}
	if (keyStates[RIGHT]) {
		this->SetPosition(this->GetX() + 5, this->GetY());
	}


	if (keyStates[UP])
		this->SetPosition(this->GetX(), this->GetY() - 5);
	if (keyStates[DOWN])
		this->SetPosition(this->GetX(), this->GetY() + 5);

	// tilemap collision - cannot move past the grey strip in the middle of the screen
	// don't get too close otherwise the carnival game isn't enough of a scam
	for (int i = 0; i < 14; i++)
	{
		for (int ii = 0; ii < 18; ii++)
		{
			if (map->MAP_DATA[i][ii] == 2)
			{
				SDL_Rect mapTile = { ii * 64, i * 64, 32, 32 };
				if (SDL_HasIntersection(&position, &mapTile))
				{
					position.x = oldX;
					position.y = oldY;
				}
			}
		}
	}
	// cannot move off the edge of the window either :)
	if (position.x < 0 || position.x > 1152)
		position.x = oldX;
	if (position.y < 0 || position.y + position.h > 896)
		position.y = oldY;

}

void Player::draw() {
	SDL_RenderCopy(this->renderer, this->texture, 0, &this->position);
}

void Player::clean() {
	SDL_DestroyTexture(this->texture);
}

/////////////////////////////////////////////////////////
// More Class-Specific functions related to the Player //
/////////////////////////////////////////////////////////

void Player::SetPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

// Might use this at some point so that the player actually faces the way that they move
/*void Player::SwitchDirection() {
	if (this->isFacingRight)
		isFacingRight = false;
	else
		isFacingRight = true;
}*/

int Player::GetX(){ return position.x; }
int Player::GetY() { return position.y; }
//bool Player::GetFacingRight() { return isFacingRight; }

// Disclaimer: this just makes the bullets seem like they get instantiated in front of the gun because I'm too lazy to actually do it properly 
// This is a separate function to the normal GetX and GetY because the shooting point will flip
float Player::GetShootingPointX() {
	float point = this->position.x + this->position.w;
	return point;
}

float Player::GetShootingPointY() {
	float point = this->position.y + (this->position.h / 2);
	return point;
}

// Return the score text to be displayed to the UI, score functionality added elsewhere
const std::string Player::GetScore() {
	std::string text = "Score: " + std::to_string(score);
	return text;
}

// Gets and Sets for player HP. 
// Being done this way rather than a void TakeDamage() because this way healing and damage can be done with the same functions
void Player::SetCurrentBullets(int bullets) {
	this->currentBullets = bullets;
}

int Player::GetCurrentBullets() {
	int bullets = this->currentBullets;
	return bullets;
}