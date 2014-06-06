#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "List.h"

int main(int argc, char **argv)
{
	List *l = list_init();
	int i = 12;
	list_push_back(l, &i);
	printf("Valeur: %d\n", *((int*)list_end(l)));
	
	int f = 3;
	list_push_back(l, &f);
	printf("Valeur: %d\n", *((int*)list_end(l)));
	
	return EXIT_SUCCESS;
}