#include <iostream>
#include <SDL.h>

#include "util/util.h"

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG_ERROR_SDL("SDL_Init");
	}

	SDL_Quit();

	return 0;
}