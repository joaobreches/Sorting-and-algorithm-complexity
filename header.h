//Aluno: João Victor Breches Alves - Nusp: 13677142 - Universidade de São Paulo

#define TAM 1000
#define reps 10

typedef int elem;

typedef struct
{
    elem *element;
    long size;
} TAD;


void list_create(TAD *t);
void destroy(TAD *t);
int add(TAD *t, elem e);
void output(TAD *t);
