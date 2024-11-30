#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _content{
    int val;
    char *name;
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

Node *Node_create(int val, char *name){
    Node *p = calloc(1, sizeof(Node));
    p->primary_key = calloc(1, sizeof(Content));
    p->primary_key->val = val;

    if(strlen(name) != 0) {
        p->primary_key->name = calloc(50, sizeof(char));
        strcpy(p->primary_key->name, name);
    } else {
        p->primary_key->name = NULL;  
    }

    p->next = NULL;
    p->prev = NULL;
    return p;
}

bool LinkedList_is_empty(LinkedList *L){
    return L->size==0; 
}

void LinkedList_add_first(LinkedList *L, int val, char *name){
    Node *p = Node_create(val, name);
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

void LinkedList_add_tail(LinkedList *L, int val, char *name){
    Node *p = Node_create(val, name);
    if(LinkedList_is_empty(L)){
        L->begin = p;
        L->end = p;
        L->size++;
    }
    else{
        L->end->next = p;
        p->prev = L->end;
        L->end = p;
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

void LinkedList_remove(LinkedList *L, int val, char *name){
    Node *prev = NULL;
    Node *pos = L->begin;
    while((pos != NULL && pos->primary_key->val != val) || pos != NULL && strcmp(pos->primary_key->name, name)){
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
        Node_remove(&pos);
    }
}

void LinkedList_free(LinkedList **L_ref){
    LinkedList *L = *L_ref;
    Node *prev = NULL;
    Node *pos = L->begin;
    
    while(pos != NULL){
        prev = pos;
        pos = pos->next;
        Node_remove(&prev);
    }
    L_ref = NULL;
}

void LinkedList_print(LinkedList *L){
    if(!LinkedList_is_empty(L)){
            Node *p = L->begin; 
        while(p != NULL){
            printf("%s => ", p->primary_key->name);
            p = p->next;
            // printf("Oi");
        }
        printf("|NULL|\n");
        
    }
    else {
        printf("Linked list is empty\n");
        return;
    }
}

void LinkedList_swap(LinkedList *L, Node *prev, Node *pos){
    if (prev == pos) return; 

    if (prev->next == pos) {
        prev->next = pos->next;
        if (pos->next != NULL) {
            pos->next->prev = prev;
        } else {
            L->end = prev; 
        }

        pos->prev = prev->prev;
        if (prev->prev != NULL) {
            prev->prev->next = pos;
        } else {
            L->begin = pos; 
        }

        pos->next = prev;
        prev->prev = pos;

        return;
    }

    Node *tempNext = prev->next;
    Node *tempPrev = prev->prev;
    if (prev->prev != NULL) {
        prev->prev->next = pos;
    } else {
        L->begin = pos; 
    }

    if (prev->next != NULL) {
        prev->next->prev = pos;
    }

    if (pos->prev != NULL) {
        pos->prev->next = prev;
    } else {
        L->begin = prev; 
    }

    if (pos->next != NULL) {
        pos->next->prev = prev;
    }

    prev->next = pos->next;
    prev->prev = pos->prev;
    
    pos->next = tempNext;
    pos->prev = tempPrev;

    if (prev->next == NULL) {
        L->end = prev;
    }

    if (pos->next == NULL) {
        L->end = pos;
    }

}

void LinkedList_sort_int_bubble_sort(LinkedList *L){
    if (L == NULL || L->begin == NULL) {
        return; 
    }
    
    Node *pos;
    Node *prev;
    int counter;
    
    do {
        counter = 0;
        prev = L->begin;  
        pos = prev->next; 
        
        while (pos != NULL) {
            if (prev->primary_key->val > pos->primary_key->val) {
                LinkedList_swap(L, prev, pos);
                counter++;
            }
            prev = pos;  
            pos = pos->next;
        }
    } while (counter > 0); 
}

void LinkedList_sort_string_bubble_sort(LinkedList *L){
    if (L == NULL || L->begin == NULL) {
        return; 
    }
    
    Node *pos;
    Node *prev;
    int counter;
    
    do {
        counter = 0;
        prev = L->begin;  
        pos = prev->next; 
        
        while (pos != NULL) {
            if (strcmp(prev->primary_key->name, pos->primary_key->name) > 0) {
                LinkedList_swap(L, prev, pos);
                counter++;
            }
            prev = pos;  
            pos = pos->next;
        }
    } while (counter > 0); 
}


