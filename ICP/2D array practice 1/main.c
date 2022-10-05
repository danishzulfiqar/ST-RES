#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,marks[4][2];

    for (i=0;i<4;i++)
    {
        printf("Enter the  Roll NO. of student %d and %d Marks\n", i+1,i+1);
        scanf("%d%d", &marks[i][0],&marks[i][1]);
    }

    for(j=0;j<4;j++)
    {
        printf("THe marks of %d Roll number are %d\n", marks[j][0],marks[j][1]);
    }

    return 0;
}
