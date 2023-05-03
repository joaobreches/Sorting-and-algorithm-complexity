//Aluno: João Victor Breches Alves - Nusp: 13677142 - Universidade de São Paulo

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

//create a new random list
void list_create(TAD *t){
    t->size = 0;
    t->element= malloc(TAM * sizeof(elem));
}


//free array
void destroy(TAD *t){
    free(t->element);
    t->size = 0;
}

//function to add elements
int add(TAD *t, elem e){
    if (t->size == TAM)
        return 1; //error: list is full
    t->element[t->size] = e;
    t->size++;
    return 0;
}

//output function
void output(TAD *t){
    if(t->element == 0)
        printf("[ ], The list is empty\n"); //list is empty
    else{
        printf("[");
        for(long i=0; i< t->size; i++)
            printf("%d, ", t->element[i]);
        printf("\b\b");
        printf("]\n\n");
    }
}


