#include <stdio.h>
#include <stdlib.h>

int display(int arr[2][2]);

int main()
{
    int i,j,arr[2][2];

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter value of %d,%d\n",i,j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n\nThe 2D array is\n\n");

     for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }

    display(arr);

    return 0;
}

int display(int arr[2][2])
{
    int i,j;

    printf("\n\nThe function is\n\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }
}

