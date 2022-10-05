#include <stdio.h>
#include <stdlib.h>

float f1(float); //Prototypes
float f2(float);

int main()
{
    float num,y;

    printf("Enter a number\n");
    scanf("%f", &num);

    printf("F1 is %0.2f\n", f1(num)); //Call

    printf("F2 is %0.2f\n", f2(num)); //call

    y=f1(num)+f2(num); //y adds values being returned  by functions

    printf("The value of Y is %0.2f\n", y);

    return 0;
}

float f1(float n) //Definition of F1
{
    float a,b,c,fact=1,f;

    a = pow(-1,n);


    for (int i=1; i<=n+1; i++)

    {
        fact=fact*i;
    }

    f= a/fact;

    return f; // Value of F1 being returned

}

float f2(float n) //Definition of F2
{
  float a,b,c,f=0;

  for (int i=0; i<=4 ; i++)
  {

    f=f+(2*n);
  }

  return f; //Value of F2 being returned

} // Author Danish Zulfiqar


