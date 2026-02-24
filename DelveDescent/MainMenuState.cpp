#include "MainMenuState.h"
#include "GameplayState.h"

MainMenuState::MainMenuState(StateManager& manager, SDL_Renderer* renderer, TTF_Font* font) : manager(manager), renderer(renderer), font(font), menu(renderer, font) {

};

void MainMenuState::HandleEvent(const SDL_Event& event) {
	MenuResult result{ menu.HandleEvent(event) };

	switch (result) {
	case MenuResult::NewGame:
		manager.PushState(std::make_unique<GameplayState>(manager, renderer, font));
		break;
	case MenuResult::Quit:
		SDL_Event quit;
		quit.type = SDL_EVENT_QUIT;
		SDL_PushEvent(&quit);
		break;
	default:
		break;
	}
}

void MainMenuState::Update() {

};

void MainMenuState::Render() {
	menu.Render();
}