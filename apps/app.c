#include<stdlib.h>
#include<stdio.h>
#include"vector.h"
#include"simple_linked_list.h"
#include"linked_list.h"

int main(){
    LinkedList *L = LinkedList_create();
    FILE *pF = fopen("/home/sergio/Documents/Projects/AED1/textfiles/nomes_aleatorios.txt", "r");
    char line[100];

    while(fgets(line, 100, pF) != NULL){
        LinkedList_add_tail(L, 0, line);
    }

    LinkedList_print(L);
    LinkedList_free(&L);

    fclose(pF);
    return 0;
}