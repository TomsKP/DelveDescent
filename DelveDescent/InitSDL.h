#pragma once
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <iostream>

bool InitSDL(SDL_Window* &window, SDL_Renderer* &renderer);
bool InitTTF(TTF_Font* &font);