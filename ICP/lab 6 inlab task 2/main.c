#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float f1(float x);
float f2(float x);

int main()

{
    float x, y;

    printf("Enter value of n\n");

    scanf("%f", &x);

    printf("\nThe value for function 1 is %f \n" , f1(x));
    printf("The value for function 2 is %f\n" , f2(x));

    y = f1(x) + f2(x);

    printf("The sum of the two function is %f\n",y);


    return(0);
}

float f1(float x)

{
    float y = 0;

    for (float i = 1 ; i <= 26 ; i++)
    {
        y = y + (5/((x+5)+3));
    }
    return y;
}

float f2(float x)
{
    float y = 0;

    for (float i =1 ; i <= 5 ; i++)
    {
        y = y + pow(-1,(x-1))*(2*x);
    }

    return y;
}
