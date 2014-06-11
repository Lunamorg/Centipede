#include "List.h"

struct _List{
	size_t size;
	Element element;
};

struct _Element{
	type element;
	Element next;
};

void list_init(List* list)
{
	list->size = 0;
	list->element = NULL;
}

void list_push_back(List *list, type element)
{
	if(list->element == NULL){
		list->element = malloc(sizeof(Element));
		list->element->next = NULL;
		list->element->element = element;
		list->size = 1;		
		return;
	}
	Element el = list->element;
	while(el->next != NULL){
		el = el->next;
	}
	el->next = malloc(sizeof(Element));
	el = el->next;
	el->element = element;
	el->next = NULL;
	list->size++;
}

void list_pop_back(List *list)
{
	Element el = list->element;
	size_t i = 0;
	while(el->next != NULL){
		el = el->next;
		++i;
	}
	free(el);
	el = list->element;
	for(size_t j = 0; j<i-1; ++j){
		el = el->next;
	}
	list->size--;
	el->next = NULL;
}

size_t list_getSize(List *list)
{
	return list->size;
}

type list_get(List *list, size_t index){
	assert(list_getSize(list) > index && index >= 0 && list_getSize(list) != 0);
		
	Element tmp = list->element;
	for(size_t i=0; i<index; ++i){
		tmp = tmp->next;
	}
	return tmp->element;
}

void list_delete(List *list, size_t index){
	assert(list_getSize(list) > index && index >= 0 && list_getSize(list) != 0);
	
	Element tmp = list->element;
	for(size_t i=0; i<index; ++i){
		tmp = tmp->next;
	}
	Element el = tmp->next;
	free(tmp);
	tmp = el;
}

void list_print(List* list, void (*func)(type)){
	Element tmp = list->element;
	for(size_t i=0; i<list_getSize(list); ++i){
		func(tmp->element);
		printf("-");
		tmp = tmp->next;
	}
	printf("\n");
}

void list_cut(List* src, List* dst, size_t index){
	assert(list_getSize(src) > index && index >= 0 && list_getSize(src) != 0);
	
	Element tmp = src->element;
	for(size_t i=0; i<index; ++i){
		tmp = tmp->next;
	}
	dst->element = tmp;
	dst->size = src->size - index;
	src->size = index;
	
	tmp = src->element;
	for(size_t i=0; i<index-1; ++i){
		tmp = tmp->next;
	}
	tmp->next = NULL;
}

type list_back(List* list){
	assert(list->element != NULL);
	Element el = list->element;
	while(el->next != NULL){
		el = el->next;
	}
	return el->element;
}

bool list_isEmpty(List* list){
	return list->element == NULL;
}

void list_insert(List* list, size_t index, type element){
	assert(list_getSize(list) > index && index >= 0 && list_getSize(list) != 0);
	Element el = list->element;
	for(size_t i = 0; i < index; ++i){
		el = el->next;
	}
	Element el2 = malloc(sizeof(Element));
	el2->element = element;
	el2->next = el->next;
	el->next = el2;
	
	list->size++;
}