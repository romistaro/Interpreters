#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char* name;
	
	struct node *next;
	
	struct node *previous;
	
}
node;

typedef struct List
{
	struct node *start;
	struct node *end;
}
List;

node* find(List* list, char* n);

void freeList(List* list)
{
   node* tmp = malloc(sizeof(node));
   tmp = list -> start;

   while (list->start != NULL)
    {
       tmp = list->start;
	   free(tmp);
       list -> start = (list->start) -> next;
    }

}

void append(List* list, char* n)
{
	node* new = malloc(sizeof(node));
	new->name = malloc(strlen(n) + 1); 
	strcpy(new->name, n);  
	new->next = NULL;
	new->previous = NULL;
	new->previous = list->end;
	list->end->next = new;
	list->end = new;
}

void delete(List* list, char* n)
{	
	node* node = find(list, n);
	if (node->previous != NULL)
		node->previous->next = node->next;
	else
		list->start = node->next;

	if (node->next != NULL)
		node->next->previous = node->previous;
	else
		list->end = node->previous;

	free(node->name); 
	free(node); 
}

node* find(List* list, char* n)
{
	node* p = list->start;
	while (p->next != NULL) {
		if (strcmp(p->name, n) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}


List* newlist(char* n)
{
	
	List* list = malloc(sizeof(List)); 
	node* node = malloc(sizeof(node));
	node -> name = malloc(sizeof(strlen(n)));
	node -> name = n;
	node -> next = NULL;
	node -> previous = NULL;
	list -> start = node;
	list -> end = node;
	return list;
}


void printlist(List* list)
{
	node* p = list ->start;
	char* name;
	while(p->next!=NULL){
		name = p->name;
		printf("%s, ", name);
		p = p -> next;
	}
	name = p->name;
	printf("%s\n", name);
}

void printback(List* list)
{
	node* p = list -> end;
	char* name;
	while(p->previous!=NULL){
		name = p->name;
		printf("%s, ", name);
		p = p -> previous;
	}
	name = p->name;
	printf("%s\n", name);
}


void insert(List* list, List* node, char* newname)
{
	
}

int main()
{
	List* list = newlist("andy");

	append(list, "gerald");
	append(list, "britney");
	append(list, "Anthony");
	append(list, "Carl");
	
	printlist(list);

	delete(list, "britney");
	
	printlist(list);

	printback(list);

	freeList(list);

}









