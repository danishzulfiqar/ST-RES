#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "employee.h"

/** This function takes pointer to a node as argument
    and then prompts user to input the data for that
    employee. The function does not return anything.
*/
void inputNodeData(struct employee *emp)
{
    printf("\nEnter the name of the employee: ");
    fgets(emp->name, 50, stdin);

    printf("\nEnter the age of the employee: ");
    scanf("%d", &(emp->age));

    printf("\nEnter the basic salary of the employee: ");
    scanf("%f", &(emp->bs));

    printf("\nRecord entered !\n");
}

/** This function takes pointer to a node as argument
    and then prints the record on the screen (stdout).
    The function does not return anything.
*/
void printNodeData(struct employee *emp)
{
    printf("\nName:\t %s", emp->name);
    printf("Age:\t %d\n", emp->age);
    printf("Basic Salary:\t %f\n", emp->bs);
}

/** Function to display the list
 */
void printList(struct employee *emp)
{
    struct employee *ptr = emp;
    printf("\nStart of list: \n");

    // start from the beginning
    while (ptr != NULL)
    {
        printNodeData(ptr);
        ptr = ptr->next;
    }

    printf("\nEnd of list.\n");
}

/** Tests if the list is empty. ONLY the head of the list
    should be passed to this function.
*/
bool isListEmpty(struct employee *emp)
{
    return (emp == NULL);
}


int getListLength(struct employee *emp)
{
    int length = 0;
    struct employee *current;

    for (current = emp; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

/** Insert a new node at the last location. i.e. after the current one.
    If the list is currently empty, a new node is created for the head.
    Note: This function takes an argument of type pointer to pointer.
*/
void insertNodeAtEnd(struct employee **first)
{
    struct employee *temp = *first;
    /// create a new node
    struct employee *new_node = (struct employee *)malloc(sizeof(struct employee));

    inputNodeData(new_node); /// get data for the newly created node from the user.

    /// point its next pointer to NULL
    new_node->next = NULL;

    if (isListEmpty(*first)) /// if currently the list is empty
    {
        *first = new_node;
    }
    else
    {
        while ((temp->next) != NULL)
            temp = temp->next; /// scroll to the end of the list
        temp->next = new_node;
    }
}

int searchNodeByName(struct employee *head, char *name)
{

    struct employee *temp = head;
    int index = 0;

    while ((strcmp(temp->name, name) != 0) && ((temp->next) != NULL))
    {
        temp = temp->next;

        index++;
    }
    if ((temp->next == NULL) && (strcmp(temp->name, name) != 0))
    {
        return (-1);
    }

    return (index);
}

int searchNodeByAge(struct employee *head, int age)
{
    int index = 0;
    printf("Searching for age: %d\n", age);

    while (head != NULL)
    {
        printf("%d. Checked %s", index, head->name);
        if (head->age == age)
        {
            return index;
        }
        index++;
        head = head->next;
    }
    return (-1);
}

/** Insert a new node after the node specified by node index.

    It returns 0 (if node is successfully inserted) or -1 (if the index
    exceeds the length of the list).
*/
int insertNodeAfter(struct employee *first, int idx)
{
    int index = 0;

    struct employee *temp = first;

    if (isListEmpty(first)) /// if currently the list is empty return -1
    {
        return (-1);
    }

    /// create a new node
    struct employee *new_node = (struct employee *)malloc(sizeof(struct employee));

    inputNodeData(new_node); /// get data for the newly created node from the user.

    while ((index != idx) && (temp->next) != NULL)
    {
        index++;
        temp = temp->next; /// scroll to the end of the list
    }
    if ((temp->next == NULL) && (index != idx)) /// We reached the end of the list without
    {                                           /// reaching the required index
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return (-1);
    }

    new_node->next = temp->next; /// Setting up the pointers for insertion
    temp->next = new_node;
    return (0); /// Successfully inserted node at idx
}

void deleteLastNode(struct employee **head)
{
    // If the list is empty, nothing to delete
    if (*head == NULL)
    {
        printf("\nList is empty, nothing to delete!\n");
        return;
    }

    // If the head is the only node in the list
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse the list until the last node
    struct employee *current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    // Free the memory of the last node and set the next pointer of the second-to-last node to NULL
    free(current->next);
    current->next = NULL;
    printf("\nLast node deleted successfully!\n");
}
