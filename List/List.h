#include <stdlib.h>
#include <stdio.h>

typedef struct _List List;

List* list_init(void);
void list_push_back(List *list, void* element);
void list_pop_back(List *list);
void* list_end(List *list);

