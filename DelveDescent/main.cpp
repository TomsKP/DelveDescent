#include <iostream>
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "StateManager.h"
#include "MainMenuState.h"
#include "InitSDL.h"

int main(int argc, char* argv[]) {
	TTF_Font* font = NULL;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	InitSDL(window, renderer);
	InitTTF(font);
	StateManager manager;

	manager.PushState(std::make_unique<MainMenuState>(manager, renderer, font));

	bool running = true;

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			manager.HandleEvent(event);
		}
		manager.Update();
		SDL_RenderClear(renderer);
		manager.Render();
		SDL_RenderPresent(renderer);
		if (manager.IsEmpty()) {
			running = false;
		}
	}

	return 0;
}