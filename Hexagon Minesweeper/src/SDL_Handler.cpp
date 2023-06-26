#include "SDL.h"
#include "SDL_Handler.h"
#include <iostream>


void SDL_Handler::CreateWindow()
{
	//initializing with error catching
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	}
	else {
		std::cout << "SDL video system is ready to go\n";
	}

	m_window = SDL_CreateWindow("Hexagon Minesweeper",	//window title
		300,	//initial x position
		300,	//initial y position
		640,	//width in pixels
		480,	//height in pixels
		SDL_WINDOW_SHOWN);	//Window Type
}

void SDL_Handler::DestroyWindow()
{
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}