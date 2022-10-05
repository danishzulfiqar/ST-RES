#include <stdio.h>
#include <stdlib.h>

int mult_mat(int *q,int row,int col,int n);
int add_mat(int *q,int row,int col,int n);


int main()
{
    int i,j,k,num[3][3],n;

    printf("Enter the value of n\n");
    scanf("%d",&n);


    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter value of %d,%d\n",i,j);
            scanf("%d",&num[i][j]);
        }

    }

    printf("\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t", num[i][j]);

        }

    printf("\n");

    }

    printf("\n");
    printf("After multiplication\n");
    mult_mat(num,3,3,n);

    printf("\n");
    printf("After addition\n");
    add_mat(num,3,3,n);


    return 0;
}

int mult_mat(int *q,int row,int col,int n)
{
    int i,j;

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t", (*(q+i*col+j))*n);
        }

        printf("\n");
    }
}

int add_mat(int *q,int row,int col,int n)
{
    int i,j;

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t", (*(q+i*col+j))+n);
        }

        printf("\n");
    }
}


