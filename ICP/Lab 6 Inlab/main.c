#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float n1=3, n2=6, n3=4, n4=2, n;

float sum_of_prod();

int main()
{

 sum_of_prod();

 return(0);
}
//This function returns the sum of products as follows result = [n1 n2] * [n3 n4]

float sum_of_prod()
{

 n= n1*n3+n1*n4+n2*n3+n2*n4+n3*n4 ;

 printf("%f",n);

}
