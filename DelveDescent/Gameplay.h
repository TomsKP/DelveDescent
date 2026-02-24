#pragma once
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "SDL3_image/SDL_image.h"
#include "Entity.h"
#include <vector>

class Gameplay {
public:
	Gameplay(SDL_Renderer* renderer, TTF_Font* font);

	void HandleEvent(const SDL_Event& event);
	void Update();
	void Render();

private:
	SDL_Renderer* renderer;
	TTF_Font* font;

	Entity player = Entity(3, 3, 10, 2, 1, "assets/images/character.png");

	std::vector<std::vector<int>> map = { {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0} };

	void RenderTile(const char* spriteFile, int x, int y);
	void RenderCharacter(const char* spriteFile, int x, int y);
};
