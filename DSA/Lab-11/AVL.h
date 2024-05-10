bool avl_search(struct node * root, int key);       /// Not implemented yet
struct node * make_new_node(int insert_data);       /// Helper function. Already implemented
void insert_node(struct node ** root, int data);    /// Need to complete (partially implemented
bool delete_node(struct node * root, int data);     /// Post Lab Task
void print_in_order(struct node * root);            /// Already implemented

void print_tree_wrapper(struct node * ptr);             /// Helper function. Already implemented
void print_tree_details(struct node * ptr, int level);  /// Already implemented

struct node * rotateLeft(struct node *);            /// Complete this function In-Lab Task1
struct node * rotateRight(struct node *);           /// Complete this function In-Lab Task1

