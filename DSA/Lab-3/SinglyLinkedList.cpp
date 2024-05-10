#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Node.h"
#include "SinglyLinkedList.h"

/** This function takes pointer to the data part of the node
    (employee) as argument and then prompts user to input
    the data for that employee. The function does not return
    anything.
*/
void inputEmployeeData(struct employee *emp)
{
    printf("\nEnter the name of the employee: ");
    fgets(emp->name, 50, stdin);

    printf("\nEnter the age of the employee: ");
    scanf("%d", &(emp->age));

    printf("\nEnter the basic salary of the employee: ");
    scanf("%f", &(emp->bs));

    printf("\nRecord entered !\n");
}


/** This function takes pointer to the data part of the node
    (employee) as argument and then prints the data for
    that employee. The function does not return anything.
*/
void printEmployeeData(struct employee *emp)
{
    printf("\nName:\t %s", emp->name);
    printf("Age:\t %d\n", emp->age);
    printf("Basic Salary:\t %f\n", emp->bs);
}

void inputNodeData(struct node *node_x)
{
    inputEmployeeData(&node_x->data);
}

void printNodeData(struct node *node_x)
{
    printEmployeeData(&node_x->data);
}

/** Function to display the data of all the records
    in the list.
*/
void printList(struct node *head)
{
    struct node *ptr = head;
    printf("\nStart of list: \n");

    // start from the beginning
    while (ptr != NULL)
    {
        printNodeData(ptr);
        ptr = ptr->next;
    }

    printf("\nEnd of list.\n");
}


void insertNodeAtEnd(struct node **head)
{

    struct node *temp = *head;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    inputNodeData(new_node); 

    new_node->next = NULL;

    if (isListEmpty(*head)) 
    {
        *head = new_node;
    }
    else
    {
        while ((temp->next) != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

/** Tests if the list is empty. ONLY the head of the list
    should be passed to this function.
*/
bool isListEmpty(struct node *head)
{
    return (head == NULL);
}

/** Function to find the length (in number of nodes) of the list.
 */
int getListLength(struct node *head)
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

/** This function searches the linked list pointed to by 'head', for
    the data field given by 'field_num'. It returns the index of the
    first node in the list containning the field or -1 if the searched
    item is not found in any of the nodes.
*/
int searchNodeByData(struct node *head, int field_num)
{
    int idx = 0;
    switch (field_num)
    {
    case EMP_NAME:
    {
        printf("\nEnter a name to search: ");
        char searchName[50];
        fgets(searchName, 50, stdin);
        idx = searchDataByName(head, searchName);

        if (idx == -1)
            printf("\nName searched for is not found!!\n");
        else
            printf("\nThe name exists at index %d", idx);

        break;
    }

    case EMP_AGE:
    {
        printf("\nEnter an age to search: ");
        int searchAge = 0;
        scanf("%d", &searchAge);
        idx = searchDataByAge(head, searchAge);

        if (idx == -1)
            printf("\nName searched for is not found!!\n");
        else
            printf("\nThe name exists at index %d", idx);

        break;
    }

    case EMP_BS:
    {
        printf("\nEnter a Basic Salary to search: ");
        float searchBS;
        scanf("%f", &searchBS);
        idx = searchDataByBasicSalary(head, searchBS);

        if (idx == -1)
            printf("\nName searched for is not found!!\n");
        else
            printf("\nThe name exists at index %d", idx);

        break;
    }
    }
    return (idx);
}

int searchDataByName(struct node *head, char *name)
{

    struct node *temp = head;
    int index = 0;

    while ((strcmp(temp->data.name, name) != 0) && ((temp->next) != NULL))
    {
        temp = temp->next; /// scroll through the list till we find the name
                           /// or the end of the list is reached.
        index++;
    }
    if ((temp->next == NULL) && (strcmp(temp->data.name, name) != 0)) /// Name not found
        return (-1);

    return (index); /// name found at index
}

int searchDataByAge(struct node *head, int age)
{

    struct node *temp = head;
    int index = 0;

    while (((temp->data.age) != age) && ((temp->next) != NULL))
    {
        temp = temp->next; /// scroll through the list till we find the age
                           /// or the end of the list is reached.
        index++;
    }
    if ((temp->next == NULL) && ((temp->data.age) != age)) /// Age not found
        return (-1);

    return (index); /// name found at index
}

int searchDataByBasicSalary(struct node *head, float basic_salary)
{

    struct node *temp = head;
    int index = 0;

    while (((temp->data.bs) != basic_salary) && ((temp->next) != NULL))
    {
        temp = temp->next; /// scroll through the list till we find the Basic Salary
                           /// or the end of the list is reached.
        index++;
    }
    if ((temp->next == NULL) && ((temp->data.bs) != basic_salary)) /// Basic Salary not found
        return (-1);

    return (index); /// BAsic Salary found at index
}

/** Insert a new node after the node specified by node index.
    It returns 0 (if node is successfully inserted) or -1 (if the index
    exceeds the length of the list).
*/
int insertNodeAfter(struct node *head, int idx)
{
    int index = 0;

    struct node *temp = head;

    if (isListEmpty(head)) /// if currently the list is empty return -1
    {
        return (-1);
    }

    /// create a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

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

/** This function deletes the last node from the list.
 */
void deleteNodeFromEnd(struct node *head)
{
    struct node *p1 = head, *p2;

    while (p1->next != NULL)
    {
        p2 = p1;       /// to store the second last node we visit.
        p1 = p1->next; /// to store the last node in the list
    }

    free(p2->next);
    p2->next = NULL;
}

int loadListFromFile(struct node **head, FILE *fptr)
{
    struct employee new_record;

    struct node *temp = *head;

    while (fread(&new_record, sizeof(struct employee), 1, fptr)) /// read data from the file.
    {
        /// create a new node
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        new_node->data = new_record;
        /// point its next pointer to NULL
        new_node->next = NULL;

        if (*head == NULL) /// The list will be empty the first time
        {
            *head = new_node;
            temp = *head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    return (0);
}


int insertNodeBefore(struct node *head, int idx)
{
    idx = idx - 1;
    int index = 0;
    struct node *temp = head;
    if (isListEmpty(head)) 
    {
        return (-1);
    }
   
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    inputNodeData(new_node); 
    while ((index != idx) && (temp->next) != NULL)
    {
        index++;
        temp = temp->next; 
    }
    if ((temp->next == NULL) && (index != idx)) 
    {                                         
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return (-1);
    }
    new_node->next = temp->next; 
    temp->next = new_node;

    return (0);
}


int insertNodeAtStart(struct node **head)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    inputNodeData(new_node);
    new_node->next = *head;
    *head = new_node;

    return 0;
}

void deleteNodeFromStart(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}


int deleteNodeAfter(struct node *head, int idx)
{
    int index = 0;
    struct node *temp = head;
    if (isListEmpty(head)) 
    {
        return (-2);
    }
    while ((index != idx) && (temp->next) != NULL)
    {
        index++;
        temp = temp->next; 
    }
    if ((index != idx) || (temp->next) == NULL) 
    {                                           
        return (-1);
    }
    struct node *next = temp->next->next;
    free(temp->next); 
    temp->next = next;

    return (0);
}

int saveListToFile(struct node *head, FILE *fptr)
{
    struct employee new_record;
    while (head != NULL)
    {
        new_record = head->data;
        fwrite(&new_record, sizeof(struct employee), 1, fptr);
        head = head->next;
    }
    return 0;
}
