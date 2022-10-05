#include <stdio.h>
#include <stdlib.h>


int main (void)
{


int range_min = 1;
int range_max = 20;
int n;
int output;
printf("For the range %d to %d,", range_min, range_max);
printf("The output of the function is: \n");
for (n=range_min; n<range_max; n++)
{


if (n < 3)
{

output = ( - n - 4);
}
else if ( (3<=n) && (n<=10) )
{

output = (n*n - 7);
}
else
{

output =((120/n) +n);
}
printf("%d", output) ;
}
printf("\n\n");

return 0;

}
