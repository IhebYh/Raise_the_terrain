#include "terrain.h"
/**
 * free_arv - frees the array of words arv
 *@arv: array of words
 */

void free_arv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
/**
 * free_grid - frees a grid
 * @grid: the original grid
 */
void free_grid(SDL_Point ***grid)
{
	int k, i;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			free(grid[k][i]);
		}
		free(grid[k]);
	}
	free(grid);
}

/**
 * free_numbers - frees a 2D array of integers
 * @numbers: name of the array
 */
void free_numbers(int **numbers)
{
	int i;

	for (i = 0; i < 8; i++)
		free(numbers[i]);
	free(numbers);
}