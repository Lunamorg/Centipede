#include "game_engine.h"

int load_engine(char *title, int width, int height) {  
  if(SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    return -1;
  }
  if(IMG_Init(IMG_INIT_PNG) == 0) { 
    return -1;
  }  
  if(!TTF_WasInit() && TTF_Init() != 0) {    
    return -1;
  }
  fenetre = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if(!fenetre) {
    return -1;
  }   
  rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  if(!rendu) {
    return -1;
  }  
  return 0; 
}

SDL_Texture* load_image(char *filename) {  
  SDL_Surface *surface = IMG_Load(filename);
  if(!surface) {
    return NULL;
  }    
  SDL_Texture* texture = SDL_CreateTextureFromSurface(rendu, surface);
  if(texture == NULL) {
    SDL_FreeSurface(surface);
    return NULL;
  }
  SDL_FreeSurface(surface);
  return texture;  
}

SDL_Texture* load_texte(char *mot, char *police, size_t size, Uint8 r, Uint8 g, Uint8 b) {    
  TTF_Font *font = TTF_OpenFont(police, size);  
  if(!font) {
    return NULL;
  }   
  SDL_Color color = {r, g, b}; 
  SDL_Surface *texte = TTF_RenderText_Solid(font, mot, color);
  if(!texte) {
    TTF_CloseFont(font);
    font = NULL;
    return NULL;
  }
  TTF_CloseFont(font);
  font = NULL;
  SDL_Texture* texture = SDL_CreateTextureFromSurface(rendu, texte);  
  if(texture == NULL) {
    SDL_FreeSurface(texte);
    return NULL;
  }
  SDL_FreeSurface(texte);    
  return texture;
}

int clear() {
  if(SDL_RenderClear(rendu)) {
    return -1;
  }
  return 0;
}

int draw(SDL_Texture **texture, void *frame, void *position) { 
  if(frame == NULL) { 
    if(position == NULL) {
      SDL_RenderCopy(rendu, *texture, NULL, NULL);
    }
    else {
      SDL_Rect *rect_dst = (SDL_Rect*)position;
      SDL_RenderCopy(rendu, *texture, NULL, rect_dst);
    }
  }
  else {
    if(frame == NULL) {
      SDL_Rect *rect_src = (SDL_Rect*)frame;
      SDL_RenderCopy(rendu, *texture, rect_src, NULL);
    }
    else {
      SDL_Rect *rect_src = (SDL_Rect*)frame;
      SDL_Rect *rect_dst = (SDL_Rect*)position;
      SDL_RenderCopy(rendu, *texture, rect_src, rect_dst);    
    }
  }
  return 0;
}

void drawToScreen() {
  SDL_RenderPresent(rendu);
}

SDL_bool key(Uint8 *state, int *key) {       
  while(SDL_PollEvent(&event)) {          
      (*key) = event.key.keysym.sym;
      (*state) = event.key.state;
      return SDL_TRUE;   
  } 
  return SDL_FALSE;
}

void unload_engine() {
  engine_error = SDL_GetError();
  if(rendu != NULL) {
    SDL_DestroyRenderer(rendu);
    rendu = NULL;  
  }
  if(fenetre != NULL) {
    SDL_DestroyWindow(fenetre);  
    fenetre = NULL;
  }  
  IMG_Quit();  
  TTF_Quit();  
  SDL_Quit();  
}
