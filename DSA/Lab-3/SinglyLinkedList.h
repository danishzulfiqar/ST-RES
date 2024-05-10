#define EMP_NAME    1
#define EMP_AGE     2
#define EMP_BS      3

void inputEmployeeData(struct employee * emp);
void printEmployeeData(struct employee * emp);



void inputNodeData(struct node * node_x);
void printNodeData(struct node * node_x);
void printList(struct node * head);

bool isListEmpty(struct node * head);
int getListLength(struct node * head);
int searchNodeByData(struct node * head, int field_num);

void  insertNodeAtEnd(struct node ** head);
int  insertNodeAfter(struct node * head, int idx);
int  insertNodeBefore(struct node * head, int idx);     /// To be completed by the students
int  insertNodeAtStart(struct node ** head);            /// To be completed by the students

void deleteNodeFromEnd(struct node * head);
void deleteNodeFromStart(struct node ** head);          /// To be completed by the students
int  deleteNodeAfter(struct node * head, int idx);      /// To be completed by the students

int searchDataByAge(struct node * head, int age);
int searchDataByName(struct node * head, char * name);
int searchDataByBasicSalary(struct node * head, float basic_salary);

int saveListToFile(struct node * head, FILE * fptr);    /// To be completed by the students
int loadListFromFile(struct node ** head, FILE * fptr);
