#include "StateManager.h"

void StateManager::PushState(std::unique_ptr<State> state) {
	states.push_back(std::move(state));
}

void StateManager::PopState() {
	states.pop_back();
}

void StateManager::ChangeState(std::unique_ptr<State> state) {
	if (!states.empty()) {
		while (!states.empty()) {
			states.pop_back();
		}
	}
	states.push_back(std::move(state));
}

void StateManager::HandleEvent(const SDL_Event& event) {
	if (!states.empty()) {
		states.back()->HandleEvent(event);
	}
}

void StateManager::Update() {
	if (!states.empty()) {
		states.back()->Update();
	}
}

void StateManager::Render() {
	if (!states.empty()) {
		states.back()->Render();
	}
}

bool StateManager::IsEmpty() {
	return states.empty();
}