#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "employee.h"

void flush();

int main()
{
    int choice;

    struct employee * head = NULL; /// Pointer to the first element (head) of the list


    printf("Hello! This program lets you manage your Employees' Database:\n");

    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node at the end of the list.");
        printf("\n2. Print the list.");
        printf("\n3. Delete the last item from the list.");
        printf("\n4. Insert a new node after index.");
        printf("\n5. Print the length of the list.");
        printf("\n6. Search the list for a record.");
        printf("\n7. Save the list to a file.");
        printf("\n8. Exit the menue.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new node to the list at the end. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                insertNodeAtEnd(&head);
                break;
            }

            case    2:  /// Print the list.
            {
                printList(head);
                break;
            }

            case 3:  /// Delete the last item from the list
            {
                deleteLastNode(&head);
                break;
            }
            case    4:  /// Insert a new node after index.
            {
                int idx = 0;
                printf("\nEnter the index after which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeAfter(head, idx) == 0)
                    printf("\nNode inserted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");

                break;
            }
            case    5:  /// Print list length
            {
                printf("\nLength of the list is: %d\n", getListLength(head));
                break;
            }

             case    6:  /// Search the list for a name
            {
                int opt;
                printf("Search a record by:\n\t1. Name\n\t2. Age\n");
                scanf("%d", &opt);

                if(opt == 1)
                {
                    char searchName[50];
                    int idx = 0;

                    printf("\nEnter a name to search: ");
                    fflush(stdin);
                    fgets(searchName, 50, stdin);

                    idx = searchNodeByName(head, searchName);
                    if(idx == -1)
                        printf("\nName searched for is not found!!\n");
                    else
                        printf("\nThe name exists at index %d", idx);
                }
                else if(opt == 2)
                {
                    int search_age;
                    printf("Enter an age to search: ");
                    scanf("%d", &search_age);

                    int idx =0;

                    idx = searchNodeByAge(head, search_age);

                    if(idx == -1)
                        printf("\nRecord searched for is not found!!\n");
                    else
                        printf("\nThe record exists at index %d", idx);
                }
                else
                    printf("Ooops! Wrong choice!!\n");

                break;
            }


            case    7:  /// Save list to file
            {
                printf("\nThis function is not yet implemented\n");
                break;
            }

            case    8:  /// Exit the program.
            {
                printf("\nExiting on user request.\n\n");
                return(0);
            }
        }
    }
    return 0;
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
