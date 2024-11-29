#include "sort_linked_list.h"

void sort_linked_list(LinkedList *L){
    Node *pos = L->begin;
    Node *prev = NULL;
    
    int counter = 0;
    //if prev > pos => swap
    do{
        counter = 0;
        prev = pos; 
        pos = pos->next;
        if(prev > pos){
            LinkedList_swap(L, prev, pos);
            counter = 1; 
        }
    }while(counter != 0);
}