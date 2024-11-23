#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	struct _node *next; 
	int val;
}Node;

typedef struct _linked_list {
	*Node begin;
	*Node end;
	int size; 
}LinkedList; 

LinkedList *LinkedList_create(){
	LinkedList *L = calloc(1, sizeof(LinkedList));

}
Node *Node_create(int val){
	Node *p = calloc(1, sizeof(Node));
	return p;
}
void LinkedList_add_tail(LinkedList *L, int val){
	
}
void LinkedList_add_first(LinkedList *L, int val);
bool LinkedList_is_empty(LinkedList *L);
void LinkedList_print(LinkedList *L);
void LinkedList_remove(LinkedList *L int val);

