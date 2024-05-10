#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Node.h"
#include "SinglyLinkedList.h"

void flush();

int main()
{
    int choice;
    char load_choice;
    struct node * head = NULL; /// Pointer to the first node (head) of the list
    //struct node * last = NULL; /// Pointer to the last element of the list

    printf("Hello! This program lets you manage your Employees' Database:\n");

    printf("\nDo you want to load employee database from the file? (y/n): ");
    load_choice = getchar();

    if(load_choice == 'y')
    {
        FILE * fptr = NULL;
        if((fptr=fopen("EmpoyeeData.dat", "rb")) == NULL)
        {
            printf("\nCannot open file for loading Data!!\n\n");
            exit(1);
        }
        loadListFromFile(&head, fptr);
        fclose(fptr);
    }
    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node at the end of the list.");
        printf("\n2. Print the list.");
        printf("\n3. Delete the last item from the list.");
        printf("\n4. Insert a new node after index.");
        printf("\n5. Search the list by Data Field.");
        printf("\n6. Save the list to a file.");
        printf("\n7. Exit the menue.");
        printf("\n8. Add node at start.");
        printf("\n9. Add node at before.");
        printf("\n10.Delete Node From Start.");
        printf("\n11.Delete Node After");
        printf("\n12.Save File.\n");


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

            case    3:  /// Delete the last item from the list
            {
                deleteNodeFromEnd(head);
                printf("\nLast node deleted!!\n");
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

             case    5:  /// Search the list for a Data Field
            {
                int field_choice, idx=0;
                printf("\nEnter a Data Field to search by: (1 - 3)\n");
                printf("\n\t1. Name \n");
                printf("\n\t2. Age \n");
                printf("\n\t3. Basic Salary \n");
                scanf("%d", &field_choice);
                flush();

                idx = searchNodeByData(head, field_choice);

                break;
            }


            case    6:  /// Save list to file
            {
                FILE * fptr = NULL;
                if((fptr=fopen("EmpoyeeData.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(head, fptr);
                break;
            }

            case    7:  /// Exit the program.
            {
                printf("\nExiting on user request.\n\n");
                return(0);
            }
            case 8:
            {
                insertNodeAtStart(&head);
                break;
            }
            case 9:
            {
                int idx = 0;
                printf("\nEnter the index before which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(idx==0){
                printf("can not add data before index 0");
                break;
                }
                if(insertNodeBefore(head, idx) == 0)
                printf("\nNode inserted successfully!");
                else
                printf("\nIndex exceeds the list length!!\n");
                break;
            }
            case 10:
            {
                if(head!=NULL){
                deleteNodeFromStart(&head);
                printf("\nfirst node deleted\n");
                break;
                }
                else{
                printf("list already empty.\n");
                break;
            }
			case 11:
			{
				int idx = 0;
				printf("\nEnter the index after which you want to delete a node: ");
				scanf("%d",&idx);
				flush();
				if(deleteNodeAfter(head, idx) == 0)
				printf("\nNode deleted successfully!");
				else if(deleteNodeAfter(head, idx) == -1)
				printf("\nIndex exceeds the list length!!\n");
				else if(deleteNodeAfter(head, idx) == -2)
				printf("list empty. !!");
				break;
			}
			case 12:
            {
                FILE * fptr = NULL;
                if((fptr=fopen("EmployeeData.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }
                saveListToFile(head, fptr);
                fclose(fptr);
                printf("\nData saved to file successfully!\n");
                break;
            }
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
