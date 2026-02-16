#pragma once
#include "State.h"
#include "StateManager.h"
#include "MainMenu.h"

class MainMenuState : public State {
public:
	MainMenuState(StateManager& manager, SDL_Renderer* renderer, TTF_Font* font);

	void HandleEvent(const SDL_Event& event) override;
	void Update() override;
	void Render() override;

private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	StateManager& manager;
	MainMenu menu;
};