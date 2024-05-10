struct employee
{
   char name[50];
   int age;
   float bs;
};

struct node_d
{

    struct employee data;

    struct node_d * next;
    struct node_d * prev;
};
