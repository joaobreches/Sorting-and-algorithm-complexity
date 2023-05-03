//Aluno: João Victor Breches Alves - Nusp: 13677142 - Universidade de São Paulo

#include "sort.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    TAD t, a, d;
    clock_t time_a=0, all_time=0;
    int increment = 3;

    //We can work with random lists
    for(increment = 3 ; pow(10, increment) <= TAM; increment++){
        all_time = 0;
        float bubble_time = 0;
        float better_b_time = 0;
        float quick_time = 0;
        float radix_time = 0;

        for(int i=0; i<reps; i++){

            //bubbleSort beggins
            //function to add random elemnts 

            list_create(&t);
            for(long j=0; j < pow(10,increment); j++){
                add(&t, rand() % TAM);
            }

            //output(&t); //output all random elements

            time_a = clock(); //save the time

            //BubbleSort function
            bubbleSort(&t);
            all_time += clock() - time_a; 
            bubble_time= all_time; //saves the time used
            all_time = 0;
            printf("Sorted by bubble");
            //output(&t); //output the sorted elemenst
            destroy(&t); //free memory
            //bubblesort ends



            //better bubbleSort beggins
            list_create(&t);
            for(long j=0; j < pow(10,increment); j++){
                add(&t, rand() % TAM);
            }
            //output(&t); //output all random elements

            time_a = clock(); //save the time

            //BetterBubble function
            better_bubble(&t);
            all_time += clock() - time_a; 
            better_b_time= all_time; //saves the time used
            all_time = 0;
            //output(&t); //output the sorted elemenst
            destroy(&t); //free memory
            //better bubbleSort ends

            //quickSort beggins
            list_create(&t);
            for(long j=0; j < pow(10,increment); j++){
                add(&t, rand() % TAM);
            }
            //output(&t); //output all random elements

            time_a = clock(); //save the time

            //QuickSortfunction
            quickSort(&t);
            all_time += clock() - time_a; 
            quick_time= all_time; //saves the time used
            all_time = 0;
            //output(&t); //output the sorted elemenst
            destroy(&t); //free memory
            //quickSort ends

            //radixSort beggins
            list_create(&t);
            for(long j=0; j < pow(10,increment); j++){
                add(&t, rand() % TAM);
            }
            //output(&t); //output all random elements

            time_a = clock(); //save the time

            //QuickSortfunction
            int n;
            Radix_sort(&t, n);
            all_time += clock() - time_a; 
            radix_time= all_time; //saves the time used
            all_time = 0;
            //output(&t); //output the sorted elemenst
            destroy(&t); //free memory
            //radixSort ends

        }
        printf("Input: %0.0f; ", pow(10,increment));
        printf("Time used on bubble-sort: %0.10f\n", (bubble_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on better bubble-sort: %0.10f\n", (better_b_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on quick-sort: %0.10f\n\n\n", (quick_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on radix-sort: %0.10f\n\n\n", (radix_time / (float)reps)/ CLOCKS_PER_SEC);
    }


    //We will work with ascending lists
    for(increment = 3; pow(10, increment) <= TAM; increment++){
        all_time = 0;
        float bubble_time = 0;
        float better_b_time = 0;
        float quick_time = 0;

        for(int i=0; i<reps; i++){

            list_create(&a);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&a, rand() % TAM);
            }
            better_bubble(&a); //sort the function

            time_a = clock(); //save the time

            //BubbleSort function
            bubbleSort(&a);
            all_time += clock() - time_a; 
            bubble_time= all_time; //saves the time used
            all_time = 0;
            //output(&a); //output the sorted elemenst
            destroy(&a); //free memory
            //bubblesort ends


            //betterBubble beggins
            list_create(&a);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&a, rand() % TAM);
            }
            better_bubble(&a); //sort the function

            time_a = clock(); //save the time

            //BetterBubble function
            better_bubble(&a);
            all_time += clock() - time_a; 
            better_b_time= all_time; //saves the time used
            all_time = 0;
            //output(&a); //output the sorted elemenst
            destroy(&a); //free memory
            //better bubbleSort ends


            //quickSort beggins
            list_create(&a);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&a, rand() % TAM);
            }
            better_bubble(&a); //sort the function

            time_a = clock(); //save the time

            //QuickSortfunction
            quickSort(&t);
            all_time += clock() - time_a; 
            quick_time= all_time; //saves the time used
            all_time = 0;
            //output(&t); //output the sorted elemenst
            destroy(&a); //free memory
        }

        printf("Input: %0.0f; ", pow(10,increment));
        printf("Time used on bubble-sort: %0.10f\n", (bubble_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on better bubble-sort: %0.10f\n", (better_b_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on quick-sort: %0.10f\n\n\n", (quick_time / (float)reps)/ CLOCKS_PER_SEC);
    }

    //Time to work with descending lists
    for(increment = 3; pow(10, increment) <= TAM; increment++){
        all_time = 0;
        float bubble_time = 0;
        float better_b_time = 0;
        float quick_time = 0;

        for(int i=0; i<reps; i++){

            list_create(&d);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&d, rand() % TAM);
            }
            inverseSort(&d); //sort the function

            time_a = clock(); //save the time

            //BubbleSort function
            bubbleSort(&d);
            all_time += clock() - time_a; 
            bubble_time= all_time; //saves the time used
            all_time = 0;
            //output(&d); //output the sorted elemenst
            destroy(&d); //free memory
            //bubblesort ends


            //BetterBubble beggins
            list_create(&d);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&d, rand() % TAM);
            }
            inverseSort(&d); //sort the function

            time_a = clock(); //save the time

            //BetterBubble function
            better_bubble(&d);
            all_time += clock() - time_a; 
            better_b_time= all_time; //saves the time used
            all_time = 0;
            //output(&d); //output the sorted elemenst
            destroy(&d); //free memory
            //better bubbleSort ends


            //quickSort beggins
            list_create(&d);
            //function to add random elemnts 
            for(long j=0; j < pow(10,increment); j++){
                add(&d, rand() % TAM);
            }
            inverseSort(&d); //sort the function

            time_a = clock(); //save the time

            //QuickSortfunction 
            quickSort(&d);
            all_time += clock() - time_a; 
            quick_time= all_time; //saves the time used
            all_time = 0;
            //output(&d); //output the sorted elemenst
            destroy(&d); //free memory

        }

        printf("Input: %0.0f; ", pow(10,increment));
        printf("Time used on bubble-sort: %0.10f\n", (bubble_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on better bubble-sort: %0.10f\n", (better_b_time / (float)reps)/ CLOCKS_PER_SEC);
        printf("Time used on quick-sort: %0.10f\n\n\n", (quick_time / (float)reps)/ CLOCKS_PER_SEC);
    }
   

    return 0;
}
