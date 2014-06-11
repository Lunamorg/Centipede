#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _List List;
typedef struct _Element *Element;
//type a definir
typedef float type;

//initialise la liste
void list_init(List* list);
//ajoute en fin de liste un element
void list_push_back(List *list, type element);
//Supprime le dernier element
void list_pop_back(List *list);
//recupere le dernier element
type list_back(List *list);
//Renvoie le nombre d'element de la liste passée en paramètre
size_t list_getSize(List* list);
//Recupere l'element d'index index
//Plante si index invalide
type list_get(List *list, size_t index);
//supprime un element de la liste
void list_delete(List *list, size_t index);
//affiche les elements de la liste sur la sortie standard
void list_print(List* list, void (*func)(type));
//coupe la liste en deux listes. La premiere liste s'arrete a index-1 et la deuxieme commence a index
void list_cut(List* src, List* dst, size_t index);
//retourne true si la liste est vide sinon false
bool list_isEmpty(List* list);
//insert un element à l'index index
void list_insert(List* list, size_t index, type element);