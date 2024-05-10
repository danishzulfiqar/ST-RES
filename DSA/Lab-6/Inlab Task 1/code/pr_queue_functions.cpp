#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "pr_queue_functions.h"

struct node *pr_dequeue(struct node **qfront)
{
    if (*qfront == NULL) 
    {
        printf("The queue was empty. Returning NULL! \n\n");
        return NULL;
    }
    struct node *dequeued_node = *qfront;

    struct node *ptr_temp = (*qfront)->next;

    *qfront = ptr_temp;

    return dequeued_node;
}

void pr_enqueue(struct node **qrear, struct node **qfront, struct element new_data, int priority)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = new_data;
    temp->node_priority = priority;
    temp->next = NULL;

    if (*qfront == NULL || priority < (*qfront)->node_priority) 
    {
        temp->next = *qfront;
        *qfront = temp;
    }
    else
    {
        struct node *cur = *qfront;
        while (cur->next != NULL && cur->next->node_priority <= priority) 
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }
}

int pr_isEmpty(struct node **qfront)
{
    return (*qfront == NULL);
}
