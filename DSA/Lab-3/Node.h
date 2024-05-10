struct employee
{
   char name[50];
   int age;
   float bs;
};

struct node
{

    struct employee data;

    struct node * next;
};
