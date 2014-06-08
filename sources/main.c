#include "game.h"

int main(int argc, char *argv[]) {    
  if(initialize() != 0) {    
    printf("Erreur : %s \n", engine_error);  
    destroy_game();  
    return EXIT_FAILURE;
  }
  if(start_game() != 0) {
    printf("Erreur : %s \n", engine_error);
    destroy_game();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
