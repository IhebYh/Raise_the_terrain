#include "terrain.h"

/**
 * _reader - read altitudes from the given file
 * @fname: file name
 * Return: 2D array of integers
 */
int **_reader(char *fname)
{
	char buffer[BUFFSIZE];
	char **lines;
	char **chars[8];
	int **numbers;
	int fd, i, j;

	fd = open(fname, O_RDWR);
	read(fd, buffer, BUFFSIZE - 1);
	close(fd);

	numbers = malloc(sizeof(int *) * 8);
	for (i = 0; i < 8; i++)
	{
		numbers[i] = malloc(sizeof(int) * 8);
	}
	lines = splitstring(buffer, "\n");
	for (i = 0; lines[i]; i++)
	{
		chars[i] = splitstring(lines[i], " ");
	}
	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			numbers[j][i] = _atoi(chars[j][i]);
		}
	}
	free_arv(lines);
	for (i = 0; i < 8; i++)
		free_arv(chars[i]);

	return (numbers);
}