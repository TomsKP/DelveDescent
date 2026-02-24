#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(SDL_Renderer* renderer, TTF_Font* font) : renderer(renderer), font(font) {};

void Gameplay::HandleEvent(const SDL_Event& event) {
	if (event.type == SDL_EVENT_KEY_DOWN) {
		switch (event.key.key) {
		case SDLK_UP:
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
				RenderTile("assets/images/stonefloor.png", 560 + (32 * j), 200 + (32 * i));
				if (i == player.GetX() && j == player.GetY()) {
					RenderCharacter("assets/images/character.png", 560 + (32 * j), 200 + (32 * i));
				}
				continue;
			}
			RenderTile("assets/images/stonefloor.png", 560 + (32 * j), 200 + (32 * i));
			if (i == player.GetX() && j == player.GetY()) {
				RenderCharacter("assets/images/character.png", 560 + (32 * j), 200 + (32 * i));
			}
			continue;
		}
	}
}

void Gameplay::RenderTile(const char* spriteFile, int x, int y) {
	SDL_Surface* surface = IMG_Load(spriteFile);
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

void Gameplay::RenderCharacter(const char* spriteFile, int x, int y) {
	SDL_Surface* surface = IMG_Load(spriteFile);
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

