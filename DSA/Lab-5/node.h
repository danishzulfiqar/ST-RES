struct element
{
    int d;      /// To store data
    char ch;    /// To store, brackets and operators
    int d_type; /// To tell whether an integer (0) or
                /// a charachter (1) is pushed onto
                /// the stack
};
struct node
{
    struct element data;

    struct node * next;
};

