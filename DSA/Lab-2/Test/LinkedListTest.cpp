#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

int makeNewNode(struct Node **start)
{

    struct Node *temp = *start;

    if (*start == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for the node: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for the node: ");
        scanf("%d", &newNode->data);
        temp->next = newNode;
        newNode->next = NULL;
    }

    return 0;
}

int insertNodeAtStart(struct Node **start)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for the node: ");
    scanf("%d", &newNode->data);
    newNode->next = *start;
    *start = newNode;

    return 0;
}

int deleteLastNode(struct Node **start)
{
    struct Node *LastNode = *start;
    struct Node *PreviousNode;

    if (*start == NULL)
    {
        printf("The list is empty please insert nodes before deleting\n");
    }
    else
    {
        while (LastNode->next != NULL)
        {
            PreviousNode = LastNode;
            LastNode = LastNode->next;
        }

        PreviousNode->next = NULL;
    }

    return 0;
}

int deleteFirstNode(struct Node **start)
{
    struct Node *temp = *start;
    *start = temp->next;
    free(temp);

    return 0;
}

int printList(struct Node *start)
{
    int index = 0;
    struct Node *temp = start;

    printf("Printing list\n\n");
    while (temp != NULL)
    {
        printf("[%d]-->%d\n", index, temp->data);
        temp = temp->next;

        index++;
    }

    printf("\n");

    return 0;
}

int searchNodeByData(struct Node *start, int data)
{
    int index = 0;
    struct Node *temp = start;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}

int deleteNodeByData(struct Node **start, int data)
{
    struct Node *temp = *start;
    struct Node *previousNode = NULL;

    if (*start == NULL)
    {
        printf("The list is empty\n");
        return -1;
    }

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            previousNode->next = temp->next;
            free(temp);
            printf("Node with data %d deleted\n", data);
            return 0;
        }
        previousNode = temp;
        temp = temp->next;
    }

    printf("Data not found\n");
    return 0;
}

int insertNodeAfterIndex(struct Node **start, int index)
{
    struct Node *temp = *start;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for the node: ");
    scanf("%d", &newNode->data);

    int position = 0;
    while (temp != NULL)
    {
        if (position == index)
        {
            newNode->next = temp->next;
            temp->next = newNode;

            printf("Node inserted at index %d\n", index);
            return 0;
        }
        temp = temp->next;
        position++;
    }

    printf("Index not found\n");
    return 0;
}

int main()
{
    bool exit = true;
    struct Node *head = NULL;

    while (exit)
    {
        int option;

        printf("Menu:\n1.Insert Node at last\n2.Print List\n3.Delete Last Node\n4.Insert Node at Start\n5.Delete first Node\n6.Search by Data\n7.Delete node by Value\n8.Insert Node After index\n0.Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            makeNewNode(&head);
            break;

        case 2:
            printList(head);
            break;

        case 3:
            deleteLastNode(&head);
            break;

        case 4:
            insertNodeAtStart(&head);
            break;

        case 5:
            deleteFirstNode(&head);
            break;

        case 6:
            int data;
            printf("Enter data to search: ");
            scanf("%d", &data);
            int index;
            index = searchNodeByData(head, data);
            if (index == -1)
            {
                printf("Data not found\n");
            }
            else
            {
                printf("Data found at index: %d\n", index);
            }
            break;

        case 7:
            int dataToDelete;
            printf("Enter data to delete: ");
            scanf("%d", &dataToDelete);
            deleteNodeByData(&head, dataToDelete);
            break;

        case 8:
            int listIndex;
            printf("Enter index to insert after: ");
            scanf("%d", &listIndex);
            insertNodeAfterIndex(&head, listIndex);
            break;

        case 0:
            exit = false;
            break;

        default:
            printf("Incorrect input\n");
            break;
        }
    }

    printf("Main menu exited!\n");
}