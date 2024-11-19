#include<stdlib.h>
#include<stdio.h>
#include"simple_linked_list.h"

typedef struct _snode {
    int val; 
    struct _snode *next; 
}SNode;

typedef struct _simple_linked_list{
    SNode *begin;
    SNode *end;
    int list_length;
} SimpleLinkedList;

SimpleLinkedList *SimpleLinkedList_create(){
    SimpleLinkedList *L = calloc(1, sizeof(SimpleLinkedList));
    return L; 
}

SNode *SNode_create(int val){
    SNode *p = calloc(1, sizeof(SNode));
    p->val = val; 
    return p;
}
bool SimpleLinkedList_is_empty(SimpleLinkedList *L){
    return !(L->list_length);
}

void SimpleLinkedList_add_first(SimpleLinkedList *L, int val){
    SNode *p = SNode_create(val);
    if(SimpleLinkedList_is_empty(L)){
        L->begin = p;
        L->end = p;
        L->list_length++;
    }
    else{
        p->next = L->begin;
        L->begin = p;
    }
}

void SimpleLinkedList_add_tail(SimpleLinkedList *L, int val){
    SNode *p = SNode_create(val);
    if(SimpleLinkedList_is_empty(L)){
        L->begin = p;
        L->end = p;
        L->list_length++;
    }
    else{
        L->end->next = p;
        p->next = NULL;
        L->list_length++;
    }
}

void SimpleLinkedList_add_after(SimpleLinkedList *L, int node_val, int val){
    SNode *aux = L->begin; 
    while(aux != NULL && aux->val != node_val){
        aux = aux->next;
    }
    if(aux != NULL){
        SNode *p = SNode_create(val);
        p->next = aux->next;
        aux->next = p;
    }
}

void SimpleLinkedList_print(SimpleLinkedList *L){
    if(!SimpleLinkedList_is_empty(L)){
        SNode *p = L->begin; 
        while(p != NULL){
            printf("%d => ", p->val);
            p = p->next;
        }
        printf("NULL\n");
    }
    else printf("NULL\n");
}

void SimpleLinkedList_remove(SimpleLinkedList *L, int val){
    SNode *prev = NULL;
    SNode *pos = L->begin;

    while(pos != NULL && pos->val != val){
        prev = pos; 
        pos = pos->next;
    }

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
        free(pos);
    }
}

void SimpleLinkedList_destroy(SimpleLinkedList **L_ref){
    SimpleLinkedList *L = *L_ref; 
    SNode *p = L->begin;
    SNode *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}
