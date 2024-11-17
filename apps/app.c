#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

int main(){
    char *str1 = calloc(50, sizeof(char));
    printf("%d\n", vector_strlen(str1));
    for(int i=0; i<5; i++){
        str1[i] = 'A'+i;
    }
    vector_string_printf(str1);
printf("\n");
    // printf("%d", str1[1]);
    printf("%d\n", vector_strlen(str1));
    char *str2 = calloc(50, sizeof(char));
    for(int i=0; i<20; i++){
        str2[i] = 'A'+i;
    }
    vector_string_printf(str2);
    printf("\n");

    // vector_strcat(str1, str2);
    vector_string_printf(str1);

    printf("\n%d\n", vetctor_strcmp(str2, str2));
}