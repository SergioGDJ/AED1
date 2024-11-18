#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H
#include<stdbool.h>

typedef struct _snode SNode;
typedef struct _simple_linked_list SimpleLinkedList;

SimpleLinkedList *SimpleLinkedList_create();
SNode *SNode_create(int val);
bool SimpleLinkedList_is_empty(SimpleLinkedList *L);
void SimpleLinkedList_add_first(SimpleLinkedList *L, int val);
void SimpleLinkedList_add_tail(SimpleLinkedList *L, int val);
void SimpleLinkedList_add_after(SimpleLinkedList *L, int node_val, int val);
void SimpleLinkedList_print(SimpleLinkedList *L);
#endif