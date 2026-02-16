#include "InitSDL.h"

bool InitSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Error initialising SDL: " << SDL_GetError() << "\n";
		return false;
	}
	if (!(window = SDL_CreateWindow("Delve", 1280, 640, NULL))) {
		std::cout << "Error creating window: " << SDL_GetError() << "\n";
		return false;
	}
	if (!(renderer = SDL_CreateRenderer(window, NULL))) {
		std::cout << "Error creating renderer: " << SDL_GetError() << "\n";
		return false;
	}
	return true;
}

bool InitTTF(TTF_Font*& font) {
	if (!TTF_Init()) {
		std::cout << "Error initialising TTF: " << SDL_GetError() << "\n";
		return false;
	}
	if (!(font = TTF_OpenFont("C:\\PersonalProjects\\DelveDescent\\DelveDescent\\assets\\fonts\\MainFont.ttf", 24))) {
		std::cout << "Error opening font: " << SDL_GetError() << "\n";
		return false;
	}
	return true;
}