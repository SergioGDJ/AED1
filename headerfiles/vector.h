#ifndef VECTOR_H
#define VECTOR_H

void vector_int_print(int *vet, int len);
void vector_float_print(float *vet, int len);
void vector_double_print(double *vet, int len);
int vector_strlen(char *str);
void vector_string_printf(char *str);
char *vector_string_strcat(char *dest, char *origin);
int vetctor_string_strcmp(char *str1, char *str2);
char *vector_string_strcpy(char *dest, char *source);
char *vector_string_to_upper(char *string);
#endif