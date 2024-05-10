#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "AVL.h"

void flush(void);

int main()
{
    int choice;
    struct node * root = NULL; /// Pointer to the first node (root) of the tree

    int my_array[10] = {45, 12, 16, 32, 75, 46, 15, 10, 80, 49};

    printf("Hello! This program lets you manage you an integer AVL Tree:\n");


    for(int i=0; i<10; i++) /// Building the tree with data in my_array
    {
        insert_node(&root, my_array[i]);    /// Note that this function takes the address of a pointer as input.
    }
    printf("\n\n");

    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node in the AVL Tree.");
        printf("\n2. Delete an item from the AVL Tree.");
        printf("\n3. Search the AVL Tree by Data Field.");
        printf("\n4. Print the AVL Tree.");
        printf("\n5. Print structure of the AVL Tree.");
        printf("\n6. Exit the menue.\n");

        printf("\n");
        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new data to the AVL Tree
            {
                int add_data;
                printf("\nEnter data to be added: ");
                scanf("%d", &add_data);
                insert_node(&root, add_data);
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

                if(avl_search(root, search_key))
                    printf("\nSearch key found in the tree!");
                else
                    printf("\nSearch key not found!");

                break;
            }

            case    4:  /// Print the tree.
            {
                print_in_order(root);
                printf("\n\n");
                break;
            }

            case    5:  /// Print Memory Map.
            {
                print_tree_wrapper(root);
                break;
            }

            case    6:  /// Exit the program.
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
