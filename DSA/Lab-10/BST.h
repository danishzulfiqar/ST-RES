#ifndef BST_H
#define BST_H

#include <stdio.h>
#include "node.h"

bool bst_search(struct node* root, int key);
bool insert_node(struct node** root, int data);
bool delete_node(struct node* root, int data);

bool save_pre_order(struct node* root, FILE* fptr);
bool save_in_order(struct node* root, FILE* fptr);
bool save_post_order(struct node* root, FILE* fptr);
int load_tree(struct node* root, FILE* fptr);

int find_smallest_node(struct node* root);
struct node* find_successor(struct node* root);

void print_pre_order(struct node* root);
void print_post_order(struct node* root);
void print_in_order(struct node* root);

#endif  // BST_H
