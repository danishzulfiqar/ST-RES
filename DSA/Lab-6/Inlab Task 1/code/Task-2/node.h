struct element
{
    int x_index;
    int y_index;
    int cell_cost;
};
struct node
{
    struct element data;

    struct node * next;
};
