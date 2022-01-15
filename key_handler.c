#include "terrain.h"

/**
 * atExit - function that exits when ESC is pressed
 * Return: 1 or 0
 */
size_t atExit()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT ||
				(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			return (1);
	}
	return (0);
}
/**
 * atRotate - function that rotates the grid when left/right
 * is pressed
 * Return: 1 || 0
 */
size_t atRotate()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.key.keysym.sym == SDLK_RIGHT)
			return (1);

		if (event.key.keysym.sym == SDLK_LEFT)
			return (2);
	}
	return (0);
}
