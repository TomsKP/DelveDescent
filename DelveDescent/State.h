#pragma once
#include "SDL3/SDL.h"

//A base class for all of the different game states.
//As all of the states have the same basic functions to be used by the state manager, these functions are virtual, which allows for the child states to override them

class State {
public:
	virtual ~State() = default;

	virtual void HandleEvent(const SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	//Used to know if the state is to be transparent. In the state stack, this would be used to decide whether or not to render the next state in the stack
	//For example, a pause screen that allows you to see the paused game screen in the background
	virtual bool IsTransparent() const { return false; };
};
