#pragma once
#include "SDL.h"
#include "SDL_Image.h"
#include <string>

class SDL_Handler
{
public:
	
	//screen size
	static const int SCREEN_WIDTH = 960;
	static const int SCREEN_HEIGHT = 720;

	//looks for user input
	SDL_Event event{};

	//renderer
	SDL_Renderer* renderer;

public:

	//constructor creates the window
	SDL_Handler();

	//destructor destroys window
	~SDL_Handler();

	//clears the renderer
	int ClearRenderer();

	//turns a loaded surface into a texture
	SDL_Texture* LoadTexture(SDL_Surface* LoadedSurface);

	// renders the source rectangle of the texture to dest rectangle
	void DrawRectangle(SDL_Rect srcrect, SDL_Rect destrect, SDL_Texture* text);

private:
	//window
	SDL_Window* m_window;

	//surface
	SDL_Surface* m_screen_surface;
};