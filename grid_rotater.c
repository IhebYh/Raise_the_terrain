#include "terrain.h"
/**
 * makerot - rotates the points of a grid
 * @grid: initial grid
 * @a: angle of rotation
 */
void makerot(SDL_Point ***grid, float a)
{
	int i, j, k, rotx, roty;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				rotx =
				(grid[k][i][j].x - 1050) * cos(a) -
				(grid[k][i][j].y - 350) * sin(a) +
					1050;

				roty =
				(grid[k][i][j].x - 1050) * sin(a) +
				(grid[k][i][j].y - 350) * cos(a) +
					350;
				grid[k][i][j].x = rotx;
				grid[k][i][j].y = roty;
			}
		}
	}
}

/**
 * rotategrid - creates a grid, rotates its points and draws it
 * @ren: renderer
 * @argv: arguments passed to the program
 * @a: angle of rotation
 */
void rotategrid(SDL_Renderer *ren, char **argv, float a)
{
	SDL_Point ***rotgrid;

	rotgrid = makegrid();
	makerot(rotgrid, a);
	makeiso(rotgrid, argv);
	Drawgrid(ren, rotgrid);
	free_grid(rotgrid);
}
