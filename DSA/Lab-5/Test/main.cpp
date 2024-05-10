#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack_functions.h"

void reverse_num_array(int *num_array, int size){
    struct node * top = NULL;   
    int i = 0;
    while(i < size){
        struct element temp;
        temp.d = num_array[i];
        temp.d_type = 0;
        push(&top, temp);
        i++;
    }
    i = 0;
    while(top != NULL){
        struct element temp;
        temp = pop(&top);
        num_array[i] = temp.d;
        i++;
    }
}

int main()
{
    int num_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(num_array) / sizeof(num_array[0]);

    reverse_num_array(num_array, size);
    
    for(int i = 0; i < size; i++){
        printf("%d ", num_array[i]);
    }

    return 0;
}


