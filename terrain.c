#include "terrain.h"

/**
 * main - set point to create my first SDL program 
 * @argv: char
 * @argc: int
 * Return: int
 */
int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int Angle;
	float a;

	if (argc != 2)
	{
		printf("Usage %s terrain\n",argv[0]);
		return 1;
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow(
		"Welcome to SDL 2.0!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1000,
		800,
		SDL_WINDOW_OPENGL
	);
	renderer = SDL_CreateRenderer(
				window,
				-1,
				SDL_RENDERER_ACCELERATED
				| SDL_RENDERER_PRESENTVSYNC
				);
	if (window == NULL)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	All_isogrid(renderer,argv);
	while ("Here where magic is created...")
	{
		if (atExit() == 1)
			break;
		if (atRotate() != 0)
		{
			Angle = (atRotate() == 1) ? Angle + 1 : Angle - 1;
			a = Angle * M_PI / 180;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			rotategrid(renderer, argv, a);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
