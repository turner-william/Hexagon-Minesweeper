#include "HexTile.h"

//constructor
HexTile::HexTile(SDL_Handler& handler)
	:m_handler(handler), m_texture(nullptr)
{
}

//destructor
HexTile::~HexTile()
{
}

void HexTile::render(SDL_Texture* texture)
{
	m_texture = texture;

	SDL_Rect srcrect = {0, 0 , 580, 680};

	SDL_Rect destrect = { ((m_handler.SCREEN_WIDTH) / 2) - (m_TILE_WIDTH / 2), //topleft tile position x axis (centered)
						  ((m_handler.SCREEN_HEIGHT) / 2) - (m_TILE_HEIGHT / 2), //topleft tile position y axis (centered)
						  m_TILE_WIDTH, //tile width
						  m_TILE_HEIGHT }; // tile height

	m_handler.DrawRectangle(srcrect, destrect, m_texture);

}