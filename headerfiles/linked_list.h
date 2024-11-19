#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

typedef _linked_list LinkedList; 
typedef _node Node; 

LinkedList *LinkedList_create();
Node *Node_create(int val);
void LinkedList_add_tail(LinkedList *L, int val); 
void LinkedList_add_first(LinkedList *L, int val);
bool LinkedList_is_empty(LinkedList *L);
void LinkedList_print(LinkedList *L);
void LinkedList_remove(LinkedList *L int val);

#endif
