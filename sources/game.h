#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "game_engine.h"

#define WIDTH_SCREEN 1024
#define HEIGHT_SCREEN 768
#define WIDTH_TILES 30
#define HEIGHT_TILES 25

typedef struct {
  SDL_Rect pos;
  SDL_Rect frame;
} tiles;

tiles ship;
tiles snake;
SDL_Texture *background;
SDL_Texture *tileset;
SDL_Texture *score;
SDL_Rect *rect;
bool haut;
bool bas;
bool gauche;
bool droite;
unsigned int timer;
unsigned int nb_tiles;
extern int initialize();
extern int start_game();
extern int init_tilesmap();
extern int add_rect(int x, int y, int w, int h);
extern int delete_rect();
extern void destroy_game();
extern void menu();
extern void deplacement();
extern SDL_bool keyboard();
extern void anim();
extern void move_snake();
//Remplit le SDL_Rect* passé en parametre 
//Retourne -1 si la taille n'est pas valide ou/et les positions ne sont pas valides, Sinon retourne 0
extern int newRect(SDL_Rect* rect, int x, int y, int w, int h);

#endif
