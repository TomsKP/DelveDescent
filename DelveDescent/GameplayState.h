#pragma once
#include "State.h"
#include "Gameplay.h"
#include "StateManager.h"

class GameplayState : public State {
public:
	GameplayState(StateManager& manager, SDL_Renderer* renderer, TTF_Font* font);

	void HandleEvent(const SDL_Event& event) override;
	void Update() override;
	void Render() override;

	void OnEnter() override;

private:
	StateManager& manager;
	Gameplay game;
};
