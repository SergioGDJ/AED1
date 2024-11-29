#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>


typedef struct _content{
    int val;
} Content;

typedef struct _node{
    struct _node *next;
    struct _node *prev;
    Content *primary_key;
} Node;

typedef struct _linked_list{
    Node *begin;
    Node *end;
    int size; 
} LinkedList;

LinkedList *LinkedList_create(){
    LinkedList *L = calloc(1, sizeof(LinkedList));
    return L;
}

Node *Node_create(int val){
    Node *p = calloc(1, sizeof(Node));
    p->primary_key = calloc(1, sizeof(Content));
    p->primary_key->val = val;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

bool LinkedList_is_empty(LinkedList *L){
    if(L->size == 0) return true;
    else return false; 
}

void LinkedList_add_first(LinkedList *L, int val){
    Node *p = Node_create(val);
    if(LinkedList_is_empty(L)){
        L->begin = p;
        L->end = p; 
        L->size++;
    }
    else{
        p->next = L->begin;
        L->begin->prev = p;
        L->begin = p;
        p->prev = NULL;
        L->size++;
    }
}

void LinkedList_add_tail(LinkedList *L, int val){
    Node *p = Node_create(val);
    if(LinkedList_is_empty(L)){
        L->begin = p;
        L->end = p;
        L->size++;
    }
    else{
        L->end = p;
        p->prev = L->end;
        p->next = NULL;
        L->size++;
    }
}

void Node_remove(Node **p_ref){
    Node *p = *p_ref;
    free(p->primary_key);
    free(p);
    p_ref = NULL;
}

void LinkedList_remove(LinkedList *L, int val){
    Node *prev = NULL;
    Node *pos = L->begin;
    while(pos != NULL && pos->primary_key != val){
        prev = pos;
        pos = pos->next;
    } //pos aponta para o no a ser removido caso exista

    if(pos != NULL){
        if(L->end == pos){
            L->end = prev; 
        }
        if(L->begin == pos){
            L->begin == pos->next;
        }
        else {
            prev->next = pos->next;
        }
        Node_remove(pos);
    }
}

void LinkedList_free(LinkedList *L){
    Node *prev = NULL;
    Node *pos = L->begin;
    
    while(pos != NULL){
        prev = pos;
        pos = pos->next;
        Node_remove(prev);
    }
}

void LinkedList_print(LinkedList *L){
    if(!LinkedList_is_empty(L)){
            Node *p = L->begin; 
        while(p != NULL){
            printf("%d =>", p->primary_key->val);
        }
        printf("NULL\n");
        return;
    }
    else {
        print("Linked list is empty\n");
        return;
    }
}
