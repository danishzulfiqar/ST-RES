#include <stdio.h>

int arr[10];
int stk[10];
int top = -1;

void push(int val)
{
    if(top >= 9)
    {
        printf("\nStack Overflow");
        return;
    }
    stk[++top] = val;
}

int pop()
{
    if(top < 0)
    {
        printf("\nStack Underflow");
        return -1;
    }
    return stk[top--];
}

int main()
{
    int n, i, val;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++)
    {
        push(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        val = pop();
        arr[i] = val;
    }
    printf("\n The reversed array is :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}