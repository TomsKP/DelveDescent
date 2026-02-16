#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer, TTF_Font* font) : renderer(renderer), font(font), selectedIndex(0) {
	items = { "[N]ew Game", "[O]ptions", "[Q]uit" };
}

void MainMenu::Reset() {
	selectedIndex = 0;
}

MenuResult MainMenu::HandleEvent(const SDL_Event& event) {
	if (event.type == SDL_EVENT_KEY_DOWN) {
		switch (event.key.key) {
		case SDLK_LEFT:
			selectedIndex--;
			if (selectedIndex < 0) {
				selectedIndex = items.size() - 1;
			}
			break;
		case SDLK_RIGHT:
			selectedIndex++;
			if (selectedIndex > items.size() - 1) {
				selectedIndex = 0;
			}
			break;
		case SDLK_RETURN:
		case SDLK_KP_ENTER:
			switch (selectedIndex) {
			case 0:
				return MenuResult::NewGame;
			case 1:
				return MenuResult::Options;
			case 2:
				return MenuResult::Quit;
			}
			break;
		case SDLK_Q:
			return MenuResult::Quit;
			break;
		case SDLK_N:
			return MenuResult::NewGame;
			break;
		case SDLK_O:
			return MenuResult::Options;
			break;
		}
	}
	return MenuResult::None;
}

void MainMenu::Render() {
	for (int i = 0; i < items.size(); i++) {
		RenderItem(items[i], 200 + (i * 150), 200, i == selectedIndex);
	}
}

void MainMenu::RenderItem(const std::string& text, int x, int y, bool selected) {
	SDL_Color color = selected ?
		SDL_Color{ 255,255,0,255 } :
		SDL_Color{ 200,200,200,255 };

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), 0, color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FRect dstRect;
	dstRect.w = (float)surface->w;
	dstRect.h = (float)surface->h;
	dstRect.x = x - dstRect.w / 2;
	dstRect.y = y;

	SDL_RenderTexture(renderer, texture, nullptr, &dstRect);

	SDL_DestroyTexture(texture);
	SDL_DestroySurface(surface);
}