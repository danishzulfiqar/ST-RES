#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "AVL.h"

bool avl_search(struct node * root, int key)
{
    /** Complete this function */

    return(false);
}

/** This function creates a new node, fills it with supplied data
    and return its address.
*/
struct node * make_new_node(int insert_data)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = insert_data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return(temp);  /// return address of the newly created node
}
/** This is a recursive function. It takes as input a pointer to pointer
    of the root node (needed for inserting the first node only.
    It also takes as input the key to be inserted.
*/
void insert_node(struct node ** ptr, int insert_data)
{
    int BalFac;

    if(*ptr == NULL) /// We have to insert a new node in the tree now
    {
        *ptr = make_new_node(insert_data);
        printf("\n%d as Root node inserted!", insert_data);
        return;
    }

    if((insert_data < (*ptr)->data)) /// data to be inserted to left sub tree
    {
        if((*ptr)->left != NULL)    /// Case when a left node or sub-tree is present
        {
            insert_node(&(*ptr)->left, insert_data);  /// insert node and update the
                                                      /// Balance Factor of the current node
        }
        else    /// Case when inserting a new leaf node
        {
            (*ptr)->left = make_new_node(insert_data);
            printf("\n%d inserted to the left of %d!", insert_data, (*ptr)->data);
        }
    }
    else    /// Data to be inserted on the right
    {
        if((*ptr)->right != NULL) /// Case when a right node or sub-tree is present
        {
            insert_node(&(*ptr)->right, insert_data);/// insert node and update the
                                                     /// Balance Factor of the current node
        }
        else/// Case when inserting a new leaf node
        {
            (*ptr)->right = make_new_node(insert_data);
            printf("\n%d inserted to the right of %d!", insert_data, (*ptr)->data);
        }
    }

    ///***************** Compute the Height and Balance Factor for the current node **********************/

    if(((*ptr)->left == NULL)&&((*ptr)->right == NULL))  /// when both sub-trees are null
    {
        (*ptr)->height = 0;
        BalFac = 0;
    }

    if(((*ptr)->left == NULL)&&((*ptr)->right != NULL)) /// when only left sub-tree is NULL
    {
        (*ptr)->height = (*ptr)->right->height + 1;
        BalFac = 0 - (*ptr)->right->height;
    }

    if(((*ptr)->left != NULL)&&((*ptr)->right == NULL)) /// when only right sub-tree is NULL
    {
        (*ptr)->height = (*ptr)->left->height + 1;
        BalFac = (*ptr)->left->height;
    }

    if(((*ptr)->left != NULL)&&((*ptr)->right != NULL)&&((*ptr)->left->height > (*ptr)->right->height)) /// when both sub-trees are not NULL
    {
        (*ptr)->height = (*ptr)->left->height + 1;                                                     /// AND (left->height > right>height)
        BalFac = (*ptr)->left->height - (*ptr)->right->height;
    }
    if(((*ptr)->left != NULL)&&((*ptr)->right != NULL)&&((*ptr)->left->height <= (*ptr)->right->height))/// when both sub-trees are not NULL
    {
        (*ptr)->height = (*ptr)->right->height + 1;                                                     /// AND (right->height >= right>height)
        BalFac = (*ptr)->left->height - (*ptr)->right->height;
    }

    /********** Here handle all the cases when a rotation is necessary ***********/
    /** Complete this function here */

    return;
}

bool delete_node(struct node * root, int data)
{

    /** Complete this function */
    return(false);
}

void print_in_order(struct node * ptr)
{
    if(ptr->left == NULL)   /// Now data of this node will be printed
        printf("%d\t", ptr->data);

    if(ptr->left != NULL)
    {
        print_in_order(ptr->left);
        printf("%d\t", ptr->data);
    }

    if(ptr->right != NULL)
    {
        print_in_order(ptr->right);
    }
    return;
}
void print_tree_wrapper(struct node * ptr)
{
    int level = 0;
    printf("Node Data\tNode Level    Height\tBalance\t  Left Child\tRight Child\t\n");
    printf("-------------------------------------------------------------------------------\n");
    print_tree_details(ptr, level);
}
void print_tree_details(struct node * ptr, int level)
{
    if((ptr->left == NULL) && (ptr->right == NULL)) /// Now data of this node will be printed
    {
        printf("    %d\t\t   %d\t\t%d\t   0\t     NULL\t  NULL\n", ptr->data, level, ptr->height);
        printf("-------------------------------------------------------------------------------\n");
    }

    if((ptr->left == NULL) && (ptr->right != NULL)) /// Now data of this node will be printed
    {
        printf("    %d\t\t   %d\t\t%d\t   %d\t     NULL\t    %d\n", ptr->data, level, ptr->height, 0-ptr->height, ptr->right->data);
        printf("-------------------------------------------------------------------------------\n");
    }

    if(ptr->left != NULL)
    {
        print_tree_details(ptr->left, level+1);
        if(ptr->right != NULL)
        {
            printf("    %d\t\t   %d\t\t%d\t   %d\t\t%d\t    %d\n", ptr->data, level,ptr->height, (ptr->left->height - ptr->right->height), ptr->left->data, ptr->right->data);
            printf("-------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("    %d\t\t   %d\t\t%d\t   %d\t\t%d\tNULL\n", ptr->data, level, ptr->height, ptr->height, ptr->left->data);
            printf("-------------------------------------------------------------------------------\n");
        }
    }

    if(ptr->right != NULL)
    {
        print_tree_details(ptr->right, level+1);
    }
    return;
}

struct node * rotateLeft(struct node * ptr)
{
        ///** Complete this function **/
}

struct node * rotateRight(struct node * ptr)
{
        ///** Complete this function **/
}
