#include <stdio.h>
#include <stdlib.h>

int main()
{
int i,j;
for(i=1;i<=12;i++)
{
for(j=1;j<=19;j++)
{
 if(i%2 != 0)
 {
    if((((i+1)/2)+j) >= 21)
        printf(" ");
    else if((((i+1)/2)-j)>=1)
        printf(" ");
    else
        printf("*");
 }
else
{
    if(((i/2)+j)<=6)
        printf(" ");
    else if ((j-(i/2)) >= 14)
        printf(" ");
    else
    printf("*");
}
        }
printf("\n");
}
}
