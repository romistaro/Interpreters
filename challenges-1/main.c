#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node
{
	char* name;
	struct node* next;
	struct node* prev;
}
node;

typedef struct List
{
	struct node* phead;
	struct node* ptail;
}
List;

List* newlist(char* name)
{
	List* list = malloc(sizeof(List));
	node* node = malloc(sizeof(node));
	list -> phead = node;
	list -> ptail = node;
	node -> name = name;
	node -> next = NULL;
	node -> prev = NULL;
	return list;
}

node* makenode(char* name)
{
	node* node = malloc(sizeof(node));
	node -> name = name;
	node -> next = NULL;
	node -> prev = NULL;
	return node;
}

void append(List* list, char* name)
{
	node* node = malloc(sizeof(node));
	node -> name = name;
	node -> next = NULL;
	node -> prev = list -> ptail;
	list -> ptail -> next = node;
	list -> ptail = node;
}

void pop(List* list)
{
	node* popped = list->ptail;
	popped -> prev -> next = NULL;
	list -> ptail = popped->prev;
	free(popped);	
}

void printlist(List* list)
{
	node* node = list -> phead;
	printf("%s", node->name);
	node = node->next;
	while(node != NULL)
	{
	printf(", %s", node->name);
	node = node-> next;
	}
	printf("\n");
}

void insert(List* list, char* name)
{
	node* node1 = list -> phead;
	node* node2 = makenode(name);

	if (strcmp(list -> phead -> name, node2 -> name) >= 0){
		node2 -> next = node1;
		list -> phead = node2;
		node1 -> prev = node2;
		return;
	}
	do
	{
		node1 = node1->next;
		if (strcmp(node1 -> name, node2 -> name) >= 0)
		{
			node2 -> next = node1;
			node1 -> prev -> next = node2;
			node2 -> prev = node1 -> prev;
			node1 -> prev = node2;
			
			return;
		}
		
		
	}while (node1->next != NULL);
	
	node2 -> prev = node1;
	list -> ptail = node2;
	node1 -> next = node2;
	return;
	
}

node* find(List* list, char* name)
{
	node* node = list ->phead;
	while(node != NULL)
	{
		if (node -> name == name){
			return node;
		}
		node = node->next;
	}
	return NULL;
}

bool delete(List* list, char* name)
{
	node* node = find(list, name);
	if (node == NULL){
		return false;
	}
	if (node == list->phead)
	{
		list->phead = node -> next;
		node -> next -> prev = NULL;
	}
	else if (node == list->ptail)
	{
		list -> ptail = node -> prev;
		node -> prev -> next = NULL;
	}
	else
	{
		node -> prev -> next = node -> next;
		node -> next -> prev =  node -> prev;
	}
	free(node);
	return true;
}

int main(){
	List* list = newlist("a");
	char* name = list -> phead -> name;
	append(list, "b");
	append(list, "d");

	printlist(list);
	insert(list, "a");
	printlist(list);
	insert(list, "ac");
	printlist(list);
	insert(list, "c");
	printlist(list);
	insert(list, "e");
	printlist(list);
	insert(list, "1");
	printlist(list);
	delete(list, "ac");
	printlist(list);
}
