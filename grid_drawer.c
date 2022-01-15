#include "terrain.h"

/**
 * All_isogrid - creates and draws an isometric grid
 * @ren: renderer
 * @argv: arguments passed to the program
 */
void All_isogrid(SDL_Renderer *ren, char **argv)
{
	SDL_Point ***isogrid;

	isogrid = makegrid();
	makeiso(isogrid, argv);
	Drawgrid(ren, isogrid);
	free_grid(isogrid);
}

/**
 * Drawgrid - draws a grid on the renderer
 * @ren: renderer
 * @grid: the grid
 */
void Drawgrid(SDL_Renderer *ren, SDL_Point ***grid)
{
	int i;

	SDL_SetRenderDrawColor(ren, 255,  255, 255, 255);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(ren, grid[0][i], 8);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(ren, grid[1][i], 8);
	SDL_RenderPresent(ren);
}
