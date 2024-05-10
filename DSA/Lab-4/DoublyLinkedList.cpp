#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Node2.h"
#include "DoublyLinkedList.h"


/** This function takes pointer to the data part of the node
    (employee) as argument and then prompts user to input
    the data for that employee. The function does not return
    anything.
*/
void inputEmployeeData(struct employee * emp)
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
void printEmployeeData(struct employee * emp)
{
    printf("\nName:\t %s", emp->name);
    printf("Age:\t %d\n", emp->age);
    printf("Basic Salary:\t %f\n", emp->bs);
}


void inputNodeData(struct node_d * node_x)
{
   inputEmployeeData(& node_x->data);
}

void printNodeData(struct node_d * node_x)
{
   printEmployeeData(& node_x->data);
}

/** Function to display the data of all the records
    in the list.
*/
void printList(struct node_d * head)
{
    struct node_d * ptr = head;
    printf("\nStart of list: \n");

    if(isListEmpty(head))
    {
        printf("\nList is empty: \n");
        return;
    }
    //start from the beginning and go till the last node
    do
    {
       printNodeData(ptr);
       ptr = ptr->next;
    }
    while(ptr != head);

    printf("\nEnd of list.\n");
}

/** Insert a new node at the last location. i.e. after the current one.
    If the list is currently empty, a new node is created for the head.
    Note: This function takes an argument of type pointer to pointer.
*/
void  insertNodeAtEnd(struct node_d ** head)
{

   struct node_d * temp = *head;

   ///create a new node
   struct node_d * new_node = (struct node_d*) malloc(sizeof(struct node_d));

   inputNodeData(new_node);  /// get data for the newly created node from the user.


   if(isListEmpty(*head))    /// if currently the list is empty
   {
        *head = new_node;
        ///point its next and previous pointers to the start
        new_node->next = * head;
        new_node->prev = * head;
   }
   else
   {
        while((temp->next) != *head)
            temp = temp->next;      /// scroll to the end of the list
        temp->next = new_node;
        new_node->next = * head;    /// Point to the first location
        new_node->prev = temp;      /// Point to the second last item
   }


}

/** Tests if the list is empty. ONLY the head of the list
    should be passed to this function.
*/
bool isListEmpty(struct node_d * head)
{
    return (head == NULL);
}

/** Function to find the length (in number of nodes) of the list.
*/
int getListLength(struct node_d * head)
{
    int length = 0;
    struct node_d * current;

    if(isListEmpty(head))
        return(0);

    for(current = head; current->next != head; current = current->next)
    {
      length++;
    }

   return (length+1);
}

/** This function searches the linked list pointed to by 'head', for
    the data field given by 'field_num'. It returns the index of the
    first node in the list containning the field or -1 if the searched
    item is not found in any of the nodes.
*/
int searchNodeByData(struct node_d * head, int field_num)
{
    int idx = 0;
    switch(field_num)
    {
        case EMP_NAME:
        {
            printf("\nEnter a name to search: ");
            char searchName[50];
            fgets(searchName, 50, stdin);
            idx = searchDataByName(head, searchName);

            if(idx == -1)
                printf("\nName searched for is not found!!\n");
            else
                printf("\nThe name exists at index %d", idx);

            break;
        }

        case EMP_AGE:
        {
            printf("\nEnter an age to search: ");
            int searchAge=0;
            scanf("%d", &searchAge);
            idx = searchDataByAge(head, searchAge);

            if(idx == -1)
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

            if(idx == -1)
                printf("\nName searched for is not found!!\n");
            else
                printf("\nThe name exists at index %d", idx);


            break;
        }

    }
    return(idx);
}

int searchDataByName(struct node_d * head, char * name)
{

    struct node_d * temp = head;
    int index = 0;

    while((strcmp(temp->data.name,name) != 0) && ((temp->next) != head))
    {
        temp = temp->next;      /// scroll through the list till we find the name
                                /// or the end of the list is reached.
        index ++;
    }
    if((temp->next == head) && (strcmp(temp->data.name,name) != 0))  /// Name not found
        return(-1);

    return (index); /// name found at index
}

int searchDataByAge(struct node_d * head, int age)
{

    struct node_d * temp = head;
    int index = 0;

    while(((temp->data.age) != age) && ((temp->next) != head))
    {
        temp = temp->next;      /// scroll through the list till we find the age
                                /// or the end of the list is reached.
        index ++;
    }
    if((temp->next == head) && ((temp->data.age) != age))  /// Age not found
        return(-1);

    return (index); /// name found at index
}

int searchDataByBasicSalary(struct node_d * head, float basic_salary)
{

    struct node_d * temp = head;
    int index = 0;

    while(((temp->data.bs) != basic_salary) && ((temp->next) != head))
    {
        temp = temp->next;      /// scroll through the list till we find the Basic Salary
                                /// or the end of the list is reached.
        index ++;
    }
    if((temp->next == head) && ((temp->data.bs) != basic_salary))  /// Basic Salary not found
        return(-1);

    return (index); /// BAsic Salary found at index
}


/** Insert a new node after the node specified by node index.
    It returns 0 (if node is successfully inserted) or -1 (if the index
    exceeds the length of the list).
*/
int  insertNodeAfter(struct node_d * head, int idx)
{
    int index = 0;

    struct node_d * temp = head;

    if(isListEmpty(head))    /// if currently the list is empty return -1
    {
        return(-1);
    }

    ///create a new node
    struct node_d * new_node = (struct node_d *) malloc(sizeof(struct node_d));

    inputNodeData(new_node);  /// get data for the newly created node from the user.


    while((index != idx) && (temp->next) != head)
    {
      index ++;
      temp = temp->next;      /// scroll to the required index
    }
    if((temp->next == head) && (index != idx))      /// We reached the end of the list without
    {                                               /// reaching the required index
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return(-1);
    }

    new_node->next = temp->next;    /// Setting up the pointers for insertion
    new_node->prev = temp;
    temp->next = new_node;
    new_node->next->prev =  new_node;
    return(0);                  /// Successfully inserted node at idx
}

/** This function deletes the last node from the list.
    As this is a doubly linked circular list, we can
    access the last node by using the head->prev pointer.
*/
void deleteNodeFromEnd(struct node_d * head)
{
    struct node_d * p1 = head, * p2 = head->prev;


    p1->prev = p2->prev;    /// 1st node's 'prev' points to prev of the current last node
    p2->prev->next = p1;    /// second last node's 'next' points to the first element

    free(p2);               /// free the current last node after pointer adjustment
}


int loadListFromFile(struct node_d ** head, FILE * fptr)
{
    struct employee  new_record;

    struct node_d * temp = *head;

    while(fread(& new_record, sizeof(struct employee), 1, fptr) )  /// read data from the file.
    {
         ///create a new node
        struct node_d * new_node = (struct node_d *) malloc(sizeof(struct node_d));

        new_node->data = new_record;


        if(*head == NULL)    /// The list will be empty the first time
        {
            *head = new_node;
            new_node->next = *head;
            new_node->prev = *head;

            temp = *head;
        }
        else
        {
            temp->next = new_node;
            (*head)->prev = new_node;
            new_node->prev = temp;
            new_node->next = *head;

            temp = temp->next;
        }

    }
    return(0);
}

/** Save the list to file such that only node data are saved in
    the file
*/
int saveListToFile(struct node_d * head, FILE * fptr)
{
    struct node_d * temp = head;
    if(head == NULL)
        return(-1);

    while(temp != NULL)
    {
        fwrite(&(temp->data), sizeof(struct employee), 1,  fptr);
        temp = temp->next;      /// scroll to the end of the list
    }
    return(0);
}


void insertNodeAtStart(struct node_d **head)
{
    struct node_d *newNode = (struct node_d *)malloc(sizeof(struct node_d));

    printf("Enter data for the new node: ");
    scanf("%d", &(newNode->data));

    newNode->next = *head;
    *head = newNode;
}


void deleteNodeFromStart(struct node_d **head)
{
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node_d *temp = *head;
    *head = (*head)->next;
    free(temp);
}


int deleteNodeAfter(struct node_d *head, int idx)
{
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. Nothing to delete.\n");
        return 0;
    }

    int count = 0;
    struct node_d *current = head;
    struct node_d *temp;

    while (current != NULL && count < idx) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Node at index %d doesn't exist or doesn't have a next node. Nothing to delete.\n", idx);
        return 0;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);

    return 1;
}

void printMemMap(struct node_d *head)
{
    int index =0;
    int i;
    printf("No.\t\t Head\t\t Next\t\t Previous\t Data");
    for (i=0; i<=100; i++);
    while (index < getListLength (head))
    {
    printf("\n%d\t\t", index);
    printf("%u\t\t", head);
    printf("%u\t\t", &(head->next));
    printf("%u\t\t", &(head->prev));
    printf("%s\t\t", ((head->data) .name));
    head=head->next;
    index++;
    }

}
