#include "SDL_Handler.h"
#include "HexTile.h"
#include "Asset_Manager.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//creating a handler to manage all user input in the program
	SDL_Handler handler;

	//creating a tile object
	HexTile tile(handler);

	//filePath Array
	std::string filePaths[9] = {
		"../../../Hexagon Minesweeper/res/Unknown_Hexagon.png",
		"../../../Hexagon Minesweeper/res/0_Hexagon.png",
		"../../../Hexagon Minesweeper/res/1_Hexagon.png",
		"../../../Hexagon Minesweeper/res/2_Hexagon.png",
		"../../../Hexagon Minesweeper/res/3_Hexagon.png",
		"../../../Hexagon Minesweeper/res/4_Hexagon.png",
		"../../../Hexagon Minesweeper/res/5_Hexagon.png",
		"../../../Hexagon Minesweeper/res/6_Hexagon.png",
		"../../../Hexagon Minesweeper/res/Bomb_Hexagon.png"};

	//asset manager
	Asset_Manager Asset_Manager(filePaths, handler.renderer);
	Asset_Manager.LoadAssets();

	int mouseButtonClickedCounter = 0;

	bool gameRunning = true;

	while (gameRunning)
	{
		while (SDL_WaitEvent(&handler.event))
		{
			//checking what event is occuring
			switch (handler.event.type)
			{
			case (SDL_QUIT):
				gameRunning = false;
				break;

			case (SDL_MOUSEBUTTONDOWN):
				if (handler.ClearRenderer() == 0)
				{
					std::cout << "Renderer Successfully Cleared.\n";
				}
				else
				{
					std::cout << "WARNING: Renderer Failed to Clear.\n";
				}

				tile.render(Asset_Manager.Assets[mouseButtonClickedCounter]);

				if (mouseButtonClickedCounter < 8)
				{
					mouseButtonClickedCounter++;
				}
				else 
				{
					mouseButtonClickedCounter = 0;
				}
			}

			//breaking out of the WaitEvent
			if (!gameRunning)
			{
				break;
			}
		}
	}
	//destroying assets
	Asset_Manager.DestroyAssets();

	return 0;
}