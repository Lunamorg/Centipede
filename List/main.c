#include <stdlib.h>
#include <stdio.h>
#include "List.h"

void print(type t){
	printf("%f", t);
}

int main(int argc, char **argv)
{
	List *l = malloc(sizeof(List*));
	list_init(l);
	if(list_isEmpty(l) == true){
		printf("Liste vide\n");
	}
	list_push_back(l, 1.67853);
	list_push_back(l, 2);
	list_push_back(l, 4);
	list_push_back(l, 8);
	list_push_back(l, 16);
	list_push_back(l, 32);
	list_push_back(l, 64);
	list_push_back(l, 128);
	list_push_back(l, 256);
	list_push_back(l, 512);
	list_push_back(l, 1024);
	
	if(list_isEmpty(l) == false){
		printf("Liste non vide\n");
	}
	print(list_back(l));
	printf("\n");
	
	printf("Size : %d\n", list_getSize(l));
	printf("%f\n", list_get(l, 0));
	list_pop_back(l);
	printf("Size : %d\n", list_getSize(l));
	
	list_print(l, print);
	
	list_insert(l, 4, 20);
	list_print(l, print);
	
	List *l2 = malloc(sizeof(List*));
	list_init(l2);
	list_cut(l, l2, 4);
	list_print(l, print);
	list_print(l2, print);
	
	list_push_back(l, 56);
	list_push_back(l2, 28);
	
	list_print(l, print);
	list_print(l2, print);
	
	return EXIT_SUCCESS;
}