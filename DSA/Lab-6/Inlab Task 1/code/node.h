#ifndef NODE_H
#define NODE_H

struct element
{
    char value;
};

struct node
{
    struct element data;
    int node_priority;
    struct node *next;
};

#endif
