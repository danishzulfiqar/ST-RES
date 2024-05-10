#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "BST.h"

void flush(void);

int main()
{
    int choice;
    char load_choice;
    struct node * root = NULL; /// Pointer to the first node (root) of the tree

    int my_array[10] = {45, 12, 16, 32, 75, 46, 15, 10, 80, 49};

    printf("Hello! This program lets you manage you an integer BST:\n");

    printf("\nDo you want to load a tree from the file? (y/n): ");
    load_choice = getchar();

    if(load_choice == 'y')
    {
        FILE * fptr = NULL;
        if((fptr=fopen("TreeData.dat", "rb")) == NULL)
        {
            printf("\nCannot open file for loading Data!!\n\n");
            exit(1);
        }
        load_tree(root, fptr);
        fclose(fptr);
    }

    for(int i=0; i<10; i++) /// Building the tree with data in my_array
    {
        insert_node(&root, my_array[i]);    /// Note that this function takes the address of a pointer as input.
    }
    printf("\n\n");

    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node in the BST.");
        printf("\n2. Delete an item from the BST.");
        printf("\n3. Search the BST by Data Field.");
        printf("\n4. Print the BST..");
        printf("\n5. Save the BST to a file.");
        printf("\n6. Print structure of the tree.");
        printf("\n7. Exit the menue.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new data to the BST
            {
                int add_data;
                printf("\nEnter data to be added: ");

                scanf("%d", &add_data);

                if(insert_node(&root, add_data) == true)
                    printf("\nData added successfully!");
                else
                    printf("\nData insertion failed!");
                break;
            }

            case    2:  /// Delete node with given data
            {
                int delete_data;

                printf("\nEnter data to be deleted: ");

                scanf("%d", &delete_data);
                if(delete_node(root, delete_data))
                    printf("\nNode deleted Successfully!!\n");
                else
                    printf("\nNode not found!!");

                break;
            }

            case    3:  /// Search the tree for a a given node
            {
                int search_key;
                printf("\nEnter data to search: ");

                scanf("%d", &search_key);

                if(bst_search(root, search_key))
                    printf("\nSearch key found in the tree!");
                else
                    printf("\nSearch key not found!");

                break;
            }

            case    4:  /// Print the tree.
            {
                int print_choice;
                printf("\nChoose the order of printing:");
                printf("\n1. Pre Order ");
                printf("\n2. Post Order ");
                printf("\n3. in Order \n");

                scanf("%d", &print_choice);

                    switch (print_choice)
                    {
                        case    1:
                        {
                            print_pre_order(root);
                        }
                        case    2:
                        {
                            print_post_order(root);
                        }
                        case    3:
                        {
                            print_in_order(root);
                        }
                    }

                break;
            }

            case    5:  /// Save the tree data to a file
            {
                FILE * fptr = NULL;
                if((fptr=fopen("TreeData.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

               int save_choice;
                printf("\nChoose the order of saving:");
                printf("\n1. Pre Order");
                printf("\n2. Post Order");
                printf("\n3. In Order \n");

                scanf("%d", &save_choice);

                    switch (save_choice)
                    {
                        case    1:
                        {
                            save_pre_order(root, fptr);
                        }
                        case    2:
                        {
                            save_post_order(root, fptr);
                        }
                        case    3:
                        {
                            save_in_order(root, fptr);
                        }
                    }
                break;
            }

            case    6:  /// Print Memory Map.
            {
                break;
            }

            case    7:  /// Exit the program.
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
