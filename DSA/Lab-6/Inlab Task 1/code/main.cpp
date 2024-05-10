#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "node.h"
#include "pr_queue_functions.h"

int main()
{
    srand((unsigned int)time(NULL));

    struct node *front = NULL;
    struct node *rear = NULL;

    struct element new_data;
    int new_prior;
    int list_length;

    printf("Enter the length of the list: ");
    scanf("%d", &list_length);

    for (int i = 0; i < list_length; i++)
    {
        printf("Enter the data and priority: ");
        scanf(" %c %d", &(new_data.value), &new_prior);

        pr_enqueue(&rear, &front, new_data, new_prior);
        printf("Enqueue data: %c with priority: %d\n", new_data.value, new_prior);
    }

    printf("\nPriority queue contents:\n");
    while (!pr_isEmpty(&front))
    {
        struct node *dequeued_node = pr_dequeue(&front);
        printf("Data: %c with priority: %d\n", dequeued_node->data.value, dequeued_node->node_priority);
        free(dequeued_node);
    }

    return 0;
}
