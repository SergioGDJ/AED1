#include<stdlib.h>
#include<stdio.h>
#include"vector.h"

int main(){
    char x[50] = {"Ola, bom dia!"};
    char *p = vector_string_to_upper(x);
    vector_string_printf(p);
}