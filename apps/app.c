#include<stdlib.h>
#include<stdio.h>
#include"vector.h"
#include"simple_linked_list.h"

int main(){
    char x[50] = {"Ola, boa tarde!"};
    char *p = vector_string_to_lower(x);
    vector_string_printf(p);
    printf("\n");
    SimpleLinkedList *L = SimpleLinkedList_create();
    SimpleLinkedList_print(L);
    SimpleLinkedList_add_first(L, 10);
    SimpleLinkedList_add_first(L, 20);
    SimpleLinkedList_add_tail(L, 10);
    SimpleLinkedList_print(L);
    SimpleLinkedList_add_after(L, 10, 43);
    SimpleLinkedList_print(L);
    SimpleLinkedList_remove(L, 10);
    SimpleLinkedList_print(L);
    SimpleLinkedList_destroy(&L);
}