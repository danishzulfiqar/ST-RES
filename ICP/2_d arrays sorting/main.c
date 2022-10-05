#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,temp,k=0,arr[6],num[2][3];

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter value of %d,%d\n", i,j);
            scanf("%d", &num[i][j]);
        }
    }

    printf("\n\nThe Entered 2-d array is\n\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t", num[i][j]);
        }

        printf("\n");
    }

    printf("\n\n1D array\n\n");

     for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {

         arr[k] = num[i][j];

         k++;
        }

    }

    for(i=0;i<6;i++)
    {
        printf("%d ", arr[i]);
    }

    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    k=0;

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {

         num[i][j]= arr[k];

         k++;
        }

    }

    printf("\n\nAfter sorting\n\n");

      for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t", num[i][j]);
        }

        printf("\n");
    }






    return 0;
}
