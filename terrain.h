#ifndef TERRAIN_H
#define TERRAIN_H

#define _GNU_SOURCE
#include <SDL2/SDL.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define BUFFSIZE 1024
/* ######## FUNCTIONS ###### */

/* ------ KEY HANDLER ----- */
size_t atExit();
size_t atRotate();

/* ------- FILE HANDLER ------*/
int **_reader(char *fname);

/* ------ MEMORY MANAGMENT ----*/
void free_arv(char **arv);
void free_grid(SDL_Point ***grid);
void free_numbers(int **numbers);

/* -------- TOKENIZE --------*/
char **splitstring(char *str, const char *delim);
char *_strdup(char *str);
int _atoi(char *s);

/* ------- GRID MAKER --------*/
SDL_Point ***allocategrid(void);
SDL_Point ***makegrid(void);
void makerow(SDL_Point ***simple_grid);
void makecol(SDL_Point ***simple_grid);
void makeiso(SDL_Point ***isogrid, char **argv);

/* ------ GRID DRAWER -------*/
void All_isogrid(SDL_Renderer *ren, char **argv);
void Drawgrid(SDL_Renderer *ren, SDL_Point ***grid);

/* ----- GRID ROTATER ------ */
void rotategrid(SDL_Renderer *ren, char **argv, float a);
void makerot(SDL_Point ***grid, float a);

#endif 