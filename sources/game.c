#include "game.h"

int initialize() {
  if(load_engine("Centipede", WIDTH_SCREEN, HEIGHT_SCREEN)) {    
    return -1;
  }  
  background = load_image("images/background.png");
  if(background == NULL) {    
    return -1;
  }
  tileset = load_image("images/tileset.png");
  if(tileset == NULL) {
    return -1;
  }
  score = load_texte("Hello", "polices/arial.ttf", 16, 120, 255, 120);
  if(score == NULL) {
    return -1;
  }
  if(init_tilesmap()) {
    return -1;
  } 
  ship.pos.x = 0;
  ship.pos.y = 0;
  ship.pos.w = 30;
  ship.pos.h = 30;
  
  ship.frame.x = 0;
  ship.frame.y = 0;
  ship.frame.w = 30;
  ship.frame.h = 30;
  
  snake.pos.x = 0;
  snake.pos.y = 0;
  snake.pos.w = 30;
  snake.pos.h = 30;
  
  snake.frame.x = 30;
  snake.frame.y = 30;
  snake.frame.w = 30;
  snake.frame.h = 30;
  return 0;  
}

int init_tilesmap() {
  nb_tiles = 2;
  rect = realloc(rect, nb_tiles * sizeof(SDL_Rect));
  if(rect == NULL) {
    return -1;
  }
  rect[0].x = 0;
  rect[0].y = 0;
  rect[0].h = 30;
  rect[0].w = 30;
  
  rect[1].x = 0;
  rect[1].y = 0;
  rect[1].h = 30;
  rect[1].w = 30;
  return 0;
}

int start_game() {       
  add_rect(0, 0, 100, 50);
  while(keyboard()) {          
    deplacement();  
    move_snake();  
    if(clear()) {
      return -1;
    }    
    if(draw(&background, NULL, NULL)) {
      return -1;
    }  
    if(draw(&tileset, &ship.frame, &ship.pos)) {
      return -1;
    }
    if(draw(&tileset, &snake.frame, &snake.pos)) {
      return -1;
    }
    if(draw(&score, NULL, &rect[2])) {
      return -1;
    }
    drawToScreen(); 
  }  
  destroy_game();
  return 0;
}

void menu() {
   
}

SDL_bool keyboard() {
  SDL_Keycode code;
  Uint8 state;
  if(key(&state, &code)) {
    if(state == SDL_PRESSED) {
      if(code == SDLK_ESCAPE) return SDL_FALSE;
      if(code == SDLK_UP) haut = true;
      if(code == SDLK_RIGHT) droite = true;
      if(code == SDLK_LEFT) gauche = true;
      if(code == SDLK_DOWN) bas = true;
      //if(code == SDLK_SPACE) 
    }
    if(state == SDL_RELEASED) {
      if(code == SDLK_UP) haut = false;
      if(code == SDLK_DOWN) bas = false;
      if(code == SDLK_RIGHT) droite = false;
      if(code == SDLK_LEFT) gauche = false;
    }
  }
  return SDL_TRUE;
}

void move_snake() {
  if(snake.pos.x < WIDTH_SCREEN - 30) {
    snake.pos.x += 1;
  }  
}

void deplacement() {
  if(haut && ship.pos.y > 0)    ship.pos.y -= 1;  
  if(gauche && ship.pos.x > 0)  ship.pos.x -= 1;
  if(droite && ship.pos.x < WIDTH_SCREEN - 30)  ship.pos.x += 1;
  if(bas && ship.pos.y < HEIGHT_SCREEN - 30)     ship.pos.y += 1;
  anim();
}

void anim() {
  if(haut) {
    if(gauche) {
      ship.frame.x = 150;
    }
    else if(droite) {
      ship.frame.x = 180;
    }
    else if(bas) {
      ship.frame.x = 0;
    }
    else {
      ship.frame.x = 30;
    }
  }
  else if(bas) {
    if(gauche) {
      ship.frame.x = 210;
    }
    else if(droite) {
      ship.frame.x = 240;
    }
    else {
      ship.frame.x = 60;
    }
  }
  else if(gauche) {
    if(droite) {
      ship.frame.x = 0;
    }
    else {
      ship.frame.x = 90;
    }
  }
  else if(droite) {
    ship.frame.x = 120;
  }
  else {
    ship.frame.x = 0;
  }
}

void destroy_game() {  
  if(background != NULL) {
    SDL_DestroyTexture(background);
    background = NULL;
  }  
  if(tileset != NULL) {
    SDL_DestroyTexture(tileset);
    tileset = NULL;
  }  
  if(score != NULL) {
    SDL_DestroyTexture(score);
    score = NULL;
  }
  free(rect);
  rect = NULL;
  unload_engine();
}

int add_rect(int x, int y, int w, int h) {  
  ++nb_tiles;
  SDL_Rect *temp = realloc(rect, nb_tiles * sizeof(SDL_Rect));
  if(temp == NULL) {
    return -1;
  }
  rect = temp;
  rect[nb_tiles-1].x = x;
  rect[nb_tiles-1].y = y;
  rect[nb_tiles-1].w = w;
  rect[nb_tiles-1].h = h;
  return 0;
}

int delete_tiles() {
  // Pour le moment //
  return 0;
}
