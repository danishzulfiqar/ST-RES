#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float avrg(float,float);
float factorial(float,float);
float function(float,float);

int main()
{
  float n1,n2;

  printf("Enter first number\n");
  scanf("%f", &n1);

  printf("Enter second number\n");
  scanf("%f", &n2);

  avrg(n1,n2);
  factorial(n1,n2);
  function(n1,n2);

  return 0;
}

float avrg(float a, float b)

{
    float c;

    c=(a+b)/2;

    printf("The averege is %0.2f\n", c);
}

float factorial(float a, float b)

{
    float fact1=1,fact2=1;

    for (int i=1; i<=a; i++)
    {
        fact1=fact1*i;
    }

    printf("The factorial of first number is %0.2f\n", fact1);

     for (int j=1; j<=b; j++)
    {
        fact2=fact2*j;
    }

    printf("The factorial of second number is %0.2f\n", fact2);

}

float function(float a, float b)
{
  float f1,f2,f3,f;

  f1=pow(a,2);
  f2=pow(b,2);

  f3=f1+f2;

  f=sqrt(f3);

  printf("The function result is %0.2f", f);

} //Author Danish Zulfiqar



