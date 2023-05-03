//Aluno: João Victor Breches Alves - Nusp: 13677142 - Universidade de São Paulo

#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//BubbleSort function
void bubbleSort(TAD *t){
    elem sup;
    //Compare the elements and, if necessary, swap them
    for(int i=0; i < t->size -1; i++){
        for(int j=0; j < t->size -1 - i; j++){
            if(t->element[j] > t->element[j+1]){
                sup = t->element[j];
                t->element[j] = t->element[j+1];
                t->element[j+1] = sup;
            }
        }
    }
}

//Better BubbleSort function
void better_bubble(TAD *t){
    long perm = 1, step = 1;
    elem sup;
    for(long i=0; i< t->size -1; i++){
        perm = 0;
        //Compare the elements and, if necessary, swap them
        for(long j = 0; j<t->size-1 -i; j++)
            if(t->element[j] > t->element[j+1]){
                sup = t->element[j];
                t->element[j] = t->element[j+1];
                t->element[j+1] = sup;
                perm = 1;
            }
        perm++;
    }
    
}

//QuickSort function
void quickSort_r(TAD *t, long low, long high) {
    long i, j;
    elem sup;

    //Partition the list
    i = low;
    for(j = low; j < high; j++){
        //verify pivot
        if(t->element[j] < t->element[high]){
            //swap
            sup = t->element[j];
            t->element[j] = t->element[j+1];
            t->element[j+1] = sup; 
        }
    }
    sup = t->element[high];
    t->element[high] = t->element[i];
    t->element[i] = sup; 

    if(low < i-1)
        quickSort_r(t, low, i-1);
    if(i+1<high)
        quickSort_r(t, i+1, high);


}

void quickSort(TAD *t){
    return quickSort_r(t, 0, t->size-1);
}

void inverseSort(TAD *t){
    bool perm = true;

    for (int i = 0; i < t->size - 1 && perm; i++) {
        perm = false;
        elem sup = 0;
        for (int j = 0; j < t->size - i - 1; j++) {
            if (t->element[j] < t->element[j + 1]) {
                sup = t->element[j];
                t->element[j] = t->element[j+1];
                t->element[j+1] = sup;
                perm = true;
            }
        }
    }
}

void Couting_sort(TAD *t, int n, int posicao){

  int *B=(int*)malloc(10*sizeof(int));

  for(int i=0;i<10;i++){
    B[i]=0;
  }

  int chave;

  for(int i=0;i<n;i++){
    chave=t->element[i]/posicao;
    chave=chave%10;
    B[chave]+=1;
  }

  for(int i=1;i<10;i++){
    B[i]+=B[i-1];
  }

  int *C=(int*)malloc(n*sizeof(int));

  for(int i=n-1;i>=0;i--){
    chave=t->element[i]/posicao;
    chave=chave%10;
    B[chave]-=1;
    C[B[chave]]=t->element[i];
  }

  for(int i=0;i<n;i++){
    t->element[i]=C[i];
  }
  
}

void Radix_sort(TAD *t, int n){
  
  int maior=t->element[0];

  for(int i=0;i<n;i++){
    if(t->element[i]>maior){
      maior=t->element[i];
    }
  }
  
  int posicao=1;

  while(maior>posicao){
    Couting_sort(t, n, posicao);
    posicao*=10;
  }
  
}

void max_heapify(TAD *t, int father, int n){
    int son = father*2;
    int aux;
    if (son > n) return;
    if (t->element[son] > t->element[father] || (son + 1 <= n && t->element[son + 1] > t->element[father]) ){
        if (son + 1 <= n && t->element[son + 1] > t->element[son]){
            aux = t->element[father];
            t->element[father] = t->element[son + 1];
            t->element[son + 1] = aux;
       } else {
                aux = t->element[father];
                t->element[father] = t->element[son];
                t->element[son] = aux;
        }
    }
}

void min_heapify(TAD *t, int father, int n){
    int son = father*2;
    int aux;
    if (son > n) return;
    if (t->element[son] < t->element[father] || (son + 1 <= n && t->element[son + 1] < t->element[father] )){
        if (son + 1 <= n && t->element[son + 1] < t->element[son]){
            aux = t->element[father];
            t->element[father] = t->element[son + 1];
            t->element[son + 1] = aux;
           } else {
                aux = t->element[father];
                t->element[father] = t->element[son];
                t->element[son] = aux;
            }
        }
    }

void heap_sort(TAD *t){
    elem aux;
    
    for (int i=(int)(t->size/2) - 1; i >= 1; i--){
        max_heapify(t, i, t->size);
    }
    aux = t->element[0];
    t->element[0] = t->element[t->size-1];
    t->element[t->size-1] = aux;


        
}


