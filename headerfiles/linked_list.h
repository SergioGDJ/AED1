#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;
typedef struct _content Content;
LinkedList *LinkedList_create();
bool LinkedList_is_empty(LinkedList *L);
Node *Node_create(int val, char *name);
void LinkedList_add_first(LinkedList *L, int val, char *name);
void LinkedList_add_tail(LinkedList *L, int val, char *name);
void Node_remove(Node **p_ref);
void LinkedList_remove(LinkedList *L, int val, char *name);
void LinkedList_print(LinkedList *L);
void LinkedList_sort_int_bubble_sort(LinkedList *L);
void LinkedList_swap(LinkedList *L, Node *prev, Node *pos);

#endif