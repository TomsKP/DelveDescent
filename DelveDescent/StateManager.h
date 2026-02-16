#pragma once
#include <memory>
#include <vector>
#include "State.h"

class StateManager {
public:
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State> state);

	void HandleEvent(const SDL_Event& event);
	void Update();
	void Render();

	bool IsEmpty();

private:
	std::vector<std::unique_ptr<State>> states;
};
