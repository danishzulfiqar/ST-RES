#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "BST.h"


void print_in_order(struct node* ptr)
{
    if (ptr == NULL)
        return;

    if (ptr->left != NULL)
    {
        print_in_order(ptr->left);
    }

    printf("%d\t", ptr->data);

    if (ptr->right != NULL)
    {
        print_in_order(ptr->right);
    }
}

bool bst_search(struct node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return bst_search(root->left, key);
    else
        return bst_search(root->right, key);
}

bool insert_node(struct node** ptr, int insert_data)
{
    if (*ptr == NULL)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = insert_data;
        temp->left = NULL;
        temp->right = NULL;
        *ptr = temp;
        printf("\n%d as Root node inserted!", insert_data);
        return true;
    }

    if ((*ptr)->data > insert_data)
    {
        if ((*ptr)->left != NULL)
            return insert_node(&(*ptr)->left, insert_data);
        else
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->left = temp;
            printf("\n%d inserted to the left of %d!", insert_data, (*ptr)->data);
            return true;
        }
    }
    else
    {
        if ((*ptr)->right != NULL)
            return insert_node(&(*ptr)->right, insert_data);
        else
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->right = temp;
            printf("\n%d inserted to the right of %d!", insert_data, (*ptr)->data);
            return true;
        }
    }

    return true;
}

bool delete_node(struct node* root, int data)
{
    if (root == NULL)
        return false;

    // Searching for the node to be deleted
    struct node* current = root;
    struct node* parent = NULL;
    bool is_left_child = false;

    while (current != NULL && current->data != data)
    {
        parent = current;

        if (data < current->data)
        {
            current = current->left;
            is_left_child = true;
        }
        else
        {
            current = current->right;
            is_left_child = false;
        }
    }

    if (current == NULL)
        return false;  // Node not found

    // Case 1: Node to be deleted is a leaf node
    if (current->left == NULL && current->right == NULL)
    {
        if (parent == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (is_left_child)
        {
            free(parent->left);
            parent->left = NULL;
        }
        else
        {
            free(parent->right);
            parent->right = NULL;
        }
    }
    // Case 2: Node to be deleted has only one child
    else if (current->left == NULL)
    {
        if (parent == NULL)
        {
            root = current->right;
            free(current);
        }
        else if (is_left_child)
        {
            parent->left = current->right;
            free(current);
        }
        else
        {
            parent->right = current->right;
            free(current);
        }
    }
    // Case 3: Node to be deleted has only one child (continued)
    else if (current->right == NULL)
    {
        if (parent == NULL)
        {
            root = current->left;
            free(current);
        }
        else if (is_left_child)
        {
            parent->left = current->left;
            free(current);
        }
        else
        {
            parent->right = current->left;
            free(current);
        }
    }
    // Case 4: Node to be deleted has two children
    else
    {
        struct node* successor = find_successor(current->right);
        int successor_data = successor->data;
        delete_node(root, successor_data);
        current->data = successor_data;
    }

    return true;
}

struct node* find_successor(struct node* root)
{
    struct node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

bool save_in_order(struct node* root, FILE* fptr)
{
    if (root == NULL)
        return false;

    save_in_order(root->left, fptr);
    fprintf(fptr, "%d ", root->data);
    save_in_order(root->right, fptr);

    return true;
}

bool save_pre_order(struct node* root, FILE* fptr)
{
    if (root == NULL)
        return false;

    fprintf(fptr, "%d ", root->data);
    save_pre_order(root->left, fptr);
    save_pre_order(root->right, fptr);

    return true;
}

bool save_post_order(struct node* root, FILE* fptr)
{
    if (root == NULL)
        return false;

    save_post_order(root->left, fptr);
    save_post_order(root->right, fptr);
    fprintf(fptr, "%d ", root->data);

    return true;
}

int load_tree(struct node* root, FILE* fptr)
{
    if (root == NULL)
        return 0;

    int count = 0;
    while (fscanf(fptr, "%d", &(root->data)) == 1)
    {
        count++;
        root->left = NULL;
        root->right = NULL;
        root = root->right;
    }

    return count;
}

int find_smallest_node(struct node* root)
{
    if (root == NULL)
        return 0;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

void print_pre_order(struct node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void print_post_order(struct node* root)
{
    if (root == NULL)
        return;

    print_post_order(root->left);
    print_post_order(root->right);
    printf("%d ", root->data);
}
