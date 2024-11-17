#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

int main(){
    char *str1 = calloc(50, sizeof(char));
    char *str2 = calloc(50, sizeof(char));
    str2 = "ola mundo";
    str1 = "ola mumdo";
    vector_string_printf(str2);
    printf("\n");
    vector_string_printf(str1);

    printf("\n%d\n", vetctor_strcmp(str1, str2));
}