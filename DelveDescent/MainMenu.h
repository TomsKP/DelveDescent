#pragma once
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <vector>
#include <string>

enum class MenuResult {
	None,
	NewGame,
	Options,
	Quit
};

class MainMenu {
public:
	MainMenu(SDL_Renderer* renderer, TTF_Font* font);

	MenuResult HandleEvent(const SDL_Event& event);
	void Render();
	void Reset();

private:
	SDL_Renderer* renderer;
	TTF_Font* font;

	std::vector<std::string> items;
	int selectedIndex{};

	void RenderItem(const std::string& text, int x, int y, bool selected);
};