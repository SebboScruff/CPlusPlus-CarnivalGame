#include "BulletManager.h"

BulletManager::BulletManager(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;
}

void BulletManager::init() {
	SDL_Surface* surface = IMG_Load("../SebScaifeShooterGame/Assets/Bullet.png");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Surface* uiSurfaceWhole = IMG_Load("../SebScaifeShooterGame/Assets/UIBulletWhole.png");
	this->uiTextureWhole = SDL_CreateTextureFromSurface(this->renderer, uiSurfaceWhole);
	SDL_FreeSurface(uiSurfaceWhole);
	for (int i = 0; i < player->GetCurrentBullets(); i++)
	{
		// create a rect at the suitable position and push it onto the vector of rects
		// the numbers look arbirary but this will line then along the bottom of the screen starting at the left,
		// then as the player shoots they will be removed from the line starting at the right
		uiBulletPos.push_back(SDL_Rect{i*78,818,39,78});
	}

}

void BulletManager::processInput(SDL_Event e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
	{
		if (SDL_GetTicks() - lastShot > SHOOT_TIME_MS && player->GetCurrentBullets() > 0)
		{
			bullets.push_back(Bullet{ player->GetShootingPointX(), player->GetShootingPointY(), 0.0f });
			lastShot = SDL_GetTicks();

			// UI stuff
			player->SetCurrentBullets(player->GetCurrentBullets() - 1);
			uiBulletPos.pop_back();
			std::cout << "remaining bullets: " << player->GetCurrentBullets() << std::endl;

			// Push the player back after shooting
			player->SetPosition(player->GetX() - recoilDistance, player->GetY());
		}
	}
}

void BulletManager::update() {
	for (auto& b : bullets) {
		b.x += BULLET_SPEED;
		b.distance += BULLET_SPEED;
	}
	auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) {return b.distance > 1000; });
	bullets.erase(remove, bullets.end());
}

void BulletManager::draw() {
	for (auto& b : bullets) {
		SDL_Rect destRect = { b.x, b.y, 27, 12};
		SDL_RenderCopy(renderer, texture, 0, &destRect);
	}
	//TO DO Draw Bullet UI
	for (int i = 0; i < uiBulletPos.size(); i++)
	{
		// draw bullets to bottom of screen
		SDL_RenderCopy(renderer, uiTextureWhole, 0, &uiBulletPos[i]);
	}
}

void BulletManager::clean() {
	SDL_DestroyTexture(this->texture);
}