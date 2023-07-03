#include "SDL_Handler.h"
#include "HexTile.h"
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
		"../../../Hexagon Minesweeper/res/Bomb_Hexagon.png"
	};
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
				tile.render(filePaths[mouseButtonClickedCounter]);
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
	return 0;
}