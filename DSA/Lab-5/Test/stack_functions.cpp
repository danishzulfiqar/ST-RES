#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack_functions.h"

struct element pop(struct node ** top)
{
    struct element temp = (*top)->data;   /// I copy the data at the top node into a temporary variable

    struct node * ptr_temp = (*top)->next;

    free(*top);
    *top = ptr_temp;

    return(temp);

}

void push(struct node ** top, struct element new_data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = new_data;      /// I can assign one struct to another if the type is the same

    new_node->next = * top;
    * top = new_node;
}


