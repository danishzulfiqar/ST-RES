#define EMP_NAME    1
#define EMP_AGE     2
#define EMP_BS      3

void inputEmployeeData(struct employee * emp);
void printEmployeeData(struct employee * emp);

void inputNodeData(struct node_d * node_x);
void printNodeData(struct node_d * node_x);
void printList(struct node_d * head);
void printMemMap(struct node_d * head);			  /// To be completed by the students

bool isListEmpty(struct node_d * head);
int getListLength(struct node_d * head);
int searchNodeByData(struct node_d * head, int field_num);

void  insertNodeAtEnd(struct node_d ** head);
int  insertNodeAfter(struct node_d * head, int idx);
void  insertNodeAtStart(struct node_d ** head);           /// To be completed by the students

void deleteNodeFromEnd(struct node_d * head);
void deleteNodeFromStart(struct node_d ** head);		  /// To be completed by the students
int deleteNodeAfter(struct node_d * head, int idx);	  /// To be completed by the students

int searchDataByAge(struct node_d * head, int age);
int searchDataByName(struct node_d * head, char * name);
int searchDataByBasicSalary(struct node_d * head, float basic_salary);

int saveListToFile(struct node_d * head, FILE * fptr);
int loadListFromFile(struct node_d ** head, FILE * fptr);
