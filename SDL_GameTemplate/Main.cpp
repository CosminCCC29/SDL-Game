#include "Game.h"
#include <SDL.h>


const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 736;

int main(int argc, char* args[])
{
	const int fps = 60;

	const int frameDelay = 1000 / fps;
	Game* game = new Game();

	game->init("Zombie Apocalypse", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running())
	{
		Uint32 frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		const int frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		
	}

	game->clean();
	delete game;
	return 0;
}
