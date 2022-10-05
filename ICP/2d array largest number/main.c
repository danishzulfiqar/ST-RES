
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,maxval,num[5][5];

    for (i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("Enter value of %d,%d\n", i,j);
            scanf("%d", &num[i][j]);
        }
    }

    printf("\n");

    printf("The matrix is\n");

    printf("\n");

    for (i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d\t", num[i][j]);

        }

        printf("\n");
    }

    maxval=num[0][0];

    for (i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
           if(maxval<num[i][j])
            maxval=num[i][j];

        }
    }

    printf("\n");

    printf("The largest value is %d\n", maxval);


    return 0;
}


