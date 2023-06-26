#include "SDL_Handler.h"

int main(int argc, char* argv[])
{
	SDL_Handler* handler = new SDL_Handler();

	handler->CreateWindow();

	bool gameRunning = true;

	while (gameRunning)
	{
		while (SDL_PollEvent(&handler->m_event))
		{
			if (handler->m_event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
	}
	return 0;
}