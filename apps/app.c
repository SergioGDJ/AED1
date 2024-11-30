#include<stdlib.h>
#include<stdio.h>
#include"vector.h"
#include"simple_linked_list.h"
#include"linked_list.h"

int main(){
    LinkedList *L = LinkedList_create();
    FILE *pF = fopen("/home/sergio/Documents/Projects/AED1/textfiles/nomes_aleatorios.txt", "r");
    char line[50];
    int c =0;
    while(fgets(line, 50, pF) != NULL){
        c++;
        // line[strcspn(line, "\n")] = '\0';
        // printf("%s", line);
        LinkedList_add_tail(L, 0, line);
    }

    LinkedList_print(L);
    printf("\n\n");
    LinkedList_sort_string_bubble_sort(L);
    LinkedList_print(L);

    LinkedList_free(&L);
    

    printf("\nNumero de nomes lidos: %d\n", c);
    fclose(pF);
    return 0;
}