#include<stdio.h>
#include<math.h>
#define pi 3.14159

//double sin(double x);
//double cos(double x);

double f1(double theta)
{

return pow(cos(theta / 2) , 2);

}

double f2(double theta)
{

return -1 * pow(sin(theta / 2) , 2);

}


int main()

{

double theta;

double y;


printf("Enter the value of theta in degrees: ");

scanf("%lf" , &theta);


theta = theta * pi / 180;


y = f1(theta) + f2(theta);


printf("The value of y is %0.3f \n" , y);

return 0;

}


