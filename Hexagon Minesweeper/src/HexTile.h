#pragma once
#include "SDL_Handler.h"

class HexTile
{
public:
	//renders a tile object
	void render(std::string filePath);

	//constructor
	HexTile(SDL_Handler& handler);

	//destructor
	~HexTile();

private:
	const int m_TILE_WIDTH = 58;
	const int m_TILE_HEIGHT = 68;

	//using this coordinate system for the tiles:
	//https://stackoverflow.com/questions/2459402/hexagonal-grid-coordinates-to-pixel-coordinates
	struct m_location
	{
		int r;
		int g;
		int b;
		int x;
		int y;
	};
protected:
	SDL_Texture* m_texture;

	SDL_Handler m_handler;
};