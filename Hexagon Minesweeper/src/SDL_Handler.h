#pragma once
#include "SDL.h"
#include "SDL_Image.h"
#include <string>

class SDL_Handler
{
public:
	
	//screen size
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 720;

	//loads a texture
	SDL_Texture* loadTexture(std::string filename);

	//looks for user input
	SDL_Event event{};

	//constructor creates the window
	SDL_Handler();

	//destructor destroys window
	~SDL_Handler();

	// renders the source rectangle of the texture to dest rectangle
	void DrawRectangle(SDL_Rect srcrect, SDL_Rect destrect, SDL_Texture* text);

private:
	//window
	SDL_Window* m_window;

	//surface
	SDL_Surface* m_screen_surface;

	//renderer
	SDL_Renderer* m_renderer;
};