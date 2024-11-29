#include<stdlib.h>
#include<stdio.h>
#include"vector.h"
#include"simple_linked_list.h"
#include"linked_list.h"

int main(){
    LinkedList *L = LinkedList_create();
    LinkedList_print(L);
    LinkedList_add_first(L, 10, NULL);
    LinkedList_add_first(L, 20, NULL);
    LinkedList_add_first(L, 30, NULL);
    LinkedList_print(L);
    LinkedList_sort_int_bubble_sort(L);
    LinkedList_print(L);
}