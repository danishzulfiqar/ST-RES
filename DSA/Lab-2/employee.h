struct employee
{
   char name[50];
   int age;
   float bs;

   struct employee * next;
};

void inputNodeData(struct employee * emp);
void printNodeData(struct employee * emp);
void printList(struct employee * head);
void  insertNodeAtEnd(struct employee ** head);
bool isListEmpty(struct employee * head);
int getListLength(struct employee * head);
int searchNodeByName(struct employee * head, char * name);
int searchNodeByAge(struct employee * head, int age);
int  insertNodeAfter(struct employee * head, int idx);
void deleteLastNode(struct employee ** head);

