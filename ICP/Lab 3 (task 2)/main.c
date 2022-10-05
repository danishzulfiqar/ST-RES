#include <stdio.h>
#include <stdlib.h>

int main()
{
int i,j;
for(i=1;i<=12;i++)
{
    if(i<=6)
    {
        for(j=1;j<=19;j++)
    {
         if(i+j >= 21)
            printf(" ");
         else if(i-j>=1)
            printf(" ");
         else
         printf("*");
    }
}
else
{
    for(j=1;j<=19;j++)
    {
        if (i+j <= 12)
            printf(" ");
        else if(j-i >= 8)
            printf(" ");
        else
            printf("*");
    }




}
printf("\n");
    }
}
