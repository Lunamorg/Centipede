#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_TTF.h>

const char* engine_error;
SDL_Window *fenetre;
SDL_Renderer *rendu;
SDL_Event event;
extern int load_engine(char *title, int width, int height);
extern void unload_engine();
extern SDL_Texture* load_image(char *filename);
extern SDL_Texture* load_texte(char *texte, char *police, size_t size, Uint8 r, Uint8 g, Uint8 b);
extern int clear();
extern int draw(SDL_Texture **t, void*, void*);
extern void drawToScreen();
extern SDL_bool key(Uint8 *state, int* k);

#endif
