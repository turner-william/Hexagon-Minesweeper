#include "HexTile.h"

void HexTile::render(std::string filePath)
{
	m_texture = m_handler.loadTexture(filePath);

	SDL_Rect srcrect = {0, 0 , 580, 680};
	SDL_Rect destrect = { 0,
					  0,
					  m_TILE_WIDTH,
					  m_TILE_HEIGHT};
	m_handler.DrawRectangle(srcrect, destrect, m_texture);
}

HexTile::HexTile(SDL_Handler& handler)
	:m_handler(handler), m_texture(nullptr)
{
}
HexTile::~HexTile()
{
}