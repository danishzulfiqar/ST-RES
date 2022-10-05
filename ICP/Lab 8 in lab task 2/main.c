#include <stdio.h>
#include <stdlib.h>

float rgb(float,float,float,float *, float *, float *);

float red=0.299,green=0.587,blue=0.114,umax=0.436,vmax=0.615;

int main()
{
    float redvalue,greenvalue,bluevalue,yprime,uvalue,vvalue;

    printf("Enter value of red color\n");
    scanf("%f", &redvalue);

    printf("Enter value of green color\n");
    scanf("%f", &greenvalue);

    printf("Enter value of blue color\n");
    scanf("%f", &bluevalue);

    rgb(redvalue,greenvalue,bluevalue,&yprime,&uvalue,&vvalue);

    printf("The value of y prime is %f\n", yprime);

    printf("The value of u is %f\n", uvalue);

    printf("The value of v prime is %f\n", vvalue);

    return 0;
}

 float rgb(float r,float g,float b,float *y ,float*u ,float*v)
{
    *y = (red*r) + (green*g) + (blue*b) ;
    *u = umax*(b - *y)/(1 - blue) ;
    *v = vmax * (r - *y)/(1 - red);
}
