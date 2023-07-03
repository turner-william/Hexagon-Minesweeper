#include "Asset_Manager.h"
#include <iostream>

//constructor
Asset_Manager::Asset_Manager(std::string (&Assetlinks)[AssetCount], SDL_Renderer* renderer)
	:AssetLinks(Assetlinks), m_renderer(renderer)
{
}

//loads all the assets
void Asset_Manager::LoadAssets()
{
	for (int i = 0; i < AssetCount; i++)
	{
		Assets[i] = Asset_Manager::LoadTexture(AssetLinks[i]);
	}
}

//destroys all the assets
void Asset_Manager::DestroyAssets()
{
	for (int i = 0; i < AssetCount; i++)
	{
		Asset_Manager::DestroyTexture(Assets[i]);
	}
}

//texture loader
SDL_Texture* Asset_Manager::LoadTexture(std::string filename)
{
	SDL_Surface* LoadedSurface = NULL;

	LoadedSurface = IMG_Load(filename.c_str());

	if (LoadedSurface == NULL)
	{
		std::cout << "File failed to load: '" << filename << "'\n";
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, LoadedSurface);

	return texture;
}

//texture destroyer
void Asset_Manager::DestroyTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}