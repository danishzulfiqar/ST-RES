#include <stdio.h>
#include <stdlib.h>

int maxvalue(int *,int);

int minvalue(int *,int);


void selectionSort(int *A, int n, int order);

int main()
{
    int i,j,k,n,order,num[5];

    for(i=0;i<5;i++)
    {
       num[i]=rand()%100;
    }

    printf("\n\n");

    for(j=0;j<5;j++)
    {
        printf("The value of %d is %d\n", j+1,num[j]);
    }

     printf("\n\n");

      printf("\nThe minimum value is %d\n", minvalue(&num[0],5));

      printf("\nThe maximum value is %d\n", maxvalue(&num[0],5));


    printf("\nEnter the order you want 0 for ascending 1 for descending\n");
    scanf("%d",&order);

    selectionSort(&num[0], 5, order);


    printf("\n\n");


    for(k=0;k<5;k++)
    {
        printf("%d\n", num[k]);
    }

      printf("\nThe minimum value is %d\n", minvalue(&num[0],5));

      printf("\nThe maximum value is %d\n", maxvalue(&num[0],5));

    return 0;
}

int maxvalue(int *p,int n)
{
 int i,maxv=*p;

 for(i=0;i<n;i++)
 {
     if(maxv < *(p+i))
        maxv = *(p+i);
 }

 return maxv;

}

int minvalue(int *p,int n)
{
  int i,minv=*p;

 for(i=0;i<n;i++)
 {
     if(minv > *(p+i))
        minv = *(p+i);
 }

 return minv;

}

 void selectionSort(int *A, int n,int order)

 {

    int indexOfMin,indexOfMax, temp;

    printf("Sorted array is\n");

    if (order == 0)

    {

    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;

        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }

        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }

    }

     else if (order == 1)

    {

    for (int i = 0; i < n-1; i++)
    {
        indexOfMax = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] > A[indexOfMax]){
                indexOfMax = j;
            }
        }

        temp = A[i];
        A[i] = A[indexOfMax];
        A[indexOfMax] = temp;
    }

    }

  } // Author: Danish Zulfiqar
