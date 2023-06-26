#pragma once
#include "SDL.h"

class SDL_Handler
{
public:
	SDL_Window* m_window;
	SDL_Event m_event;

	void CreateWindow();
	void DestroyWindow();
private:
};