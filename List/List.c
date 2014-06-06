#include "List.h"

struct _List{
	void* element;
	void* next;
};

List* list_init(void)
{
	List* list = malloc(sizeof(List*));
	list->element = NULL;
	list->next = NULL;
	return list;
}

void list_push_back(List *list, void* element)
{
	List tmp;
	tmp = *((List*)list);
	
	size_t b = 0;
	
	while(tmp.next != NULL){
		printf("%d\n", *((int*)tmp.element));
		tmp = *((List*)tmp.next);
		printf("Boucle\n");
		++b;
	}
	if(b == 0)
	{
		list->element = element;
		//printf("%d\n", *((int*)tmp->element));
		list->next = NULL;
		return;
	}
	tmp.next = malloc(sizeof(List*));
	((List*)tmp.next)->element = element;
	((List*)tmp.next)->next = NULL;
}

void list_pop_back(List *list)
{

}

void* list_end(List *list)
{
	List tmp = *list;
	
	while(tmp.next != NULL){
		tmp = *((List*)tmp.next);
		printf("Boucle 2\n");
	}
	
	return tmp.element;
}