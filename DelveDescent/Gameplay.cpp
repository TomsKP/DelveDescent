#include "Gameplay.h"
#include <iostream>
#include "Level1.cpp"

Gameplay::Gameplay(SDL_Renderer* renderer, TTF_Font* font) : renderer(renderer), font(font) {};

void Gameplay::HandleEvent(const SDL_Event& event) {
	if (event.type == SDL_EVENT_KEY_DOWN) {
		switch (event.key.key) {
		case SDLK_UP:
			if (player.GetX() - 1 == enemies[0].GetX() && player.GetY() == enemies[0].GetY()) {
				enemies[0].SetX(enemies[0].GetX() - 1);
			}
			player.SetX(player.GetX() - 1);
			break;
		case SDLK_DOWN:
			player.SetX(player.GetX() + 1);
			break;
		case SDLK_RIGHT:
			player.SetY(player.GetY() + 1);
			break;
		case SDLK_LEFT:
			player.SetY(player.GetY() - 1);
			break;
		}
	}
}

void Gameplay::Update() {

}

void Gameplay::Render() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 0) {
				RenderTile(tileSprites[0], 560 + (32 * j), 200 + (32 * i));
				if (i == player.GetX() && j == player.GetY()) {
					RenderEntity(playerSprite, 560 + (32 * j), 200 + (32 * i));
				}
				for (int x = 0; x < enemies.size(); x++) {
					if (i == enemies[0].GetX() && j == enemies[0].GetY()) {
						RenderEntity(enemySprites[x], 560 + (32 * j), 200 + (32 * i));
					}
				}
				continue;
			}
			else if (map[i][j] == 1) {
				RenderTile(tileSprites[1], 560 + (32 * j), 200 + (32 * i));
				if (i == player.GetX() && j == player.GetY()) {
					RenderEntity(playerSprite, 560 + (32 * j), 200 + (32 * i));
				}
				for (int x = 0; x < enemies.size(); x++) {
					if (i == enemies[0].GetX() && j == enemies[0].GetY()) {
						RenderEntity(enemySprites[x], 560 + (32 * j), 200 + (32 * i));
					}
				}
				continue;
			}
			
		}
	}
}

void Gameplay::RenderTile(SDL_Surface* sprite, int x, int y) {
	SDL_Surface* surface = sprite;
	std::cout << SDL_GetError();
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FRect dstRect;
	dstRect.w = (float)surface->w;
	dstRect.h = (float)surface->h;
	dstRect.x = x - dstRect.w / 2;
	dstRect.y = y;

	SDL_RenderTexture(renderer, texture, nullptr, &dstRect);
	SDL_DestroyTexture(texture);
}

void Gameplay::RenderEntity(SDL_Surface* sprite, int x, int y) {
	SDL_Surface* surface = sprite;
	std::cout << SDL_GetError();
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FRect dstRect;
	dstRect.w = (float)surface->w;
	dstRect.h = (float)surface->h;
	dstRect.x = x - dstRect.w / 2;
	dstRect.y = y;

	SDL_RenderTexture(renderer, texture, nullptr, &dstRect);
	SDL_DestroyTexture(texture);
}

void Gameplay::LoadLevel(int level) {
	if (level == 1) {
		level1 currentLevel;
		enemies.push_back(currentLevel.enemy0);
		map = currentLevel.map1;
		enemySprites.push_back(IMG_Load(currentLevel.enemy0.GetSprite()));
		tileSprites.push_back(IMG_Load("assets/images/stonefloor.png"));
		tileSprites.push_back(IMG_Load("assets/images/stonefloor.png"));
	}
}

