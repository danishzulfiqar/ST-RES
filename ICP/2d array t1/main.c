#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[3][2];
    int i,j;

    for(i=0;i<3;i++)
    {
        printf("Enter roll number of student %d\n", i+1);
        scanf("%d", &num[i][0]);

        printf("Enter marks of student %d\n", i+1);
        scanf("%d", &num[i][1]);
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t", num[i][j]);
        }

        printf("\n");
    }

    return 0;
}
