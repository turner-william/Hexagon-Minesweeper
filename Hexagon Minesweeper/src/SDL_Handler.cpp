#include "SDL_Handler.h"
#include <iostream>

//constructor
SDL_Handler::SDL_Handler()
	:m_screen_surface(NULL)
{
	//initializing video & audio with error catching
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL video could not be initialized: " << SDL_GetError();
	} else
	{
		std::cout << "SDL video system is ready to go.\n";
	}

	//initializing ability to render PNG files
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "SDL_image for PNG Files could not be initialized: " << IMG_GetError << "\n";
	}

	//creating window
	m_window = SDL_CreateWindow("Hexagon Minesweeper",	//window title
		300,	//initial x position
		300,	//initial y position
		SCREEN_WIDTH,	//width in pixels
		SCREEN_HEIGHT,	//height in pixels
		SDL_WINDOW_SHOWN);	//Window Type

	//creating renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

//texture loader
SDL_Texture* SDL_Handler::loadTexture(std::string filename)
{
	SDL_Surface* loadedImage = NULL;

	loadedImage = IMG_Load(filename.c_str());

	if (loadedImage == NULL)
	{
		std::cout << "File failed to load: '" << filename << "'\n";
	}

	SDL_Texture* text = SDL_CreateTextureFromSurface(m_renderer, loadedImage);

	return text;
}

//assigning a rectangle to the file that was loaded
void SDL_Handler::DrawRectangle(SDL_Rect srcrect, SDL_Rect destrect, SDL_Texture* text)
{
	if (text)
	{
		SDL_RenderCopy(m_renderer, text, &srcrect, &destrect);
		SDL_RenderPresent(m_renderer);

		SDL_UpdateWindowSurface(m_window);
	}
	else
	{
		std::cout << "DrawRectangle: text was nullptr\n";
	}
}

//destructor
SDL_Handler::~SDL_Handler()
{
	SDL_FreeSurface(m_screen_surface);
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}