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
	void LoadLevel(int level);

private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	std::vector<Entity> enemies;

	Entity player = Entity(3, 3, 10, 2, 1, "assets/images/character.png");

	std::vector<std::vector<int>> map;

	void RenderTile(const char* spriteFile, int x, int y);
	void RenderEntity(const char* spriteFile, int x, int y);
	
};
