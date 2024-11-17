#include"vector.h"
#include<stdio.h>
#include<stdlib.h>

void vector_int_print(int *vet, int len){
    int i=0;
    while(*(vet+i) <len){
        printf("%d ", *(vet + i));
        i++;
    }
}

void vector_float_print(float *vet, int len){
    int i=0;
    while(*(vet+i) < len){
        printf("%.3f ", *(vet+i));
        i++;
    }
}

void vector_double_print(double *vet, int len){
    int i=0;
    while(*(vet+i) < len){
        printf("%.3lf ", *(vet+i));
        i++;
    }
}
int vector_strlen(char *str){
    if(str == NULL){
        return -1;
    }
    int i=0;
    while(*(str+i) != '\0'){
        i++;
    }
    return i;
}

void vector_string_printf(char *str){
    int len = vector_strlen(str);
    int i=0;
    while(i<len){
        printf("%c", str[i]);
        i++;
    }
}

char *vector_strcat(char *dest, char *origin){
    int len_dest = vector_strlen(dest);
    int len_origin = vector_strlen(origin); 
    for(int i=0; i<len_origin; i++){
        dest[len_dest] = origin[i];
        len_dest++;
    }
}

int vetctor_strcmp(char *str1, char *str2){
    int k = vector_strlen(str1);
    int w = vector_strlen(str2);
    int i=0;
    int aux=0;
    while(i < k && i<w){
        if(str1[i] != str2[i]){
            break;
        }
        i++;
        aux++;
    }
    if(str1[aux] > str2[aux]) return 1;
    else if (str1[aux] == str2[aux]) return 0;
    else if(str1[aux] < str2[aux]) return -1;

    if(k > w) return 1;
    else return -1;

}

