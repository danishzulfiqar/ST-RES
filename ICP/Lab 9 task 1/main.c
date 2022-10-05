#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n,val[20];

    for(i=0;i<=19;i++)
    {
        val[i]=rand() % 50 ;
    }

    for(j=0;j<=19;j++)
    {
        printf("The value of %d is %d\n", j, val[j]);
    }

    printf("\n\n\n");

    printf("The reversed order is:\n");

    for(k=19;k>=0;k--)
    {
        printf("The value of %d is %d\n", k, val[k]);
    }

    printf("\n\n\n");

    while(1)
    {
        printf("\nEnter the number of element\n");
        scanf("%d", &n);

        printf("The value of %d element is %d\n", n, val[n-1]);

    }

    return 0;
}
