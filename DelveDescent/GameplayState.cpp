#include "GameplayState.h"

GameplayState::GameplayState(StateManager& manager, SDL_Renderer* renderer, TTF_Font* font) : manager(manager), game(renderer, font) {};

void GameplayState::HandleEvent(const SDL_Event& event) {
	if (event.type == SDL_EVENT_KEY_DOWN) {
		if (event.key.key == SDLK_ESCAPE) {
			manager.PopState();
		}
		else {
			game.HandleEvent(event);
		}
	}
}

void GameplayState::Update() {

}

void GameplayState::Render() {
	game.Render();
}