#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue_functions.h"

struct element q_delete(struct node ** qfront)
{
    if(*qfront == NULL)                      /// if a dequeue operation is sought when the queue is already empty
    {
        printf("The queue was empty. Returning garbage data! \n\n");
        struct element temp;
        return(temp);
    }
    struct element temp = (*qfront)->data;   /// I copy the data at the front node into a temporary variable

    struct node * ptr_temp = (*qfront)->next;

    free(*qfront);
    *qfront = ptr_temp;

    return(temp);

}

void q_insert(struct node ** qrear, struct node ** qfront, struct element new_data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = new_data;      /// I can assign one struct to another if the type is the same

    new_node->next = NULL;
    if(*qrear != NULL)              /// If the queue is currently empty
        (*qrear)->next = new_node;

    *qrear = new_node;
    if(*qfront == NULL)             /// This operation will only be perfomed when the que is empty
        *qfront = new_node;

    (*qrear)->next = NULL;
}

struct element q_peek(struct node ** qfront)
{
    if(*qfront == NULL)                      /// if a dequeue operation is sought when the queue is already empty
    {
        printf("The queue was empty. Returning garbage data! \n\n");
        struct element temp;
        return(temp);
    }
    struct element temp = (*qfront)->data;   /// I copy the data at the front node into a temporary variable

    return(temp);   /// Return the node data without deleting it from the queue
}

/* Function returns true if the queue is empty false otherwise*/
int q_isEmpty(struct node ** qfront)
{
    return(*qfront == NULL);
}
