#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()

{

char L;

double a, b;

printf("Enter any operation from following + - * /:\n");
scanf("%c", &L);

printf("Enter two operands:\n");
scanf("%lf %lf", &a, &b);

switch (L) {
case '+':
printf("%.1lf + %.1lf = %.1lf", a, b, a + b);
break;
case '-':
printf("%.1lf - %.1lf = %.1lf", a, b, a - b);
break;
case '*':
printf("%.1lf * %.1lf = %.1lf", a, b, a * b);
break;
case '/':
printf("%.1lf / %.1lf = %.1lf", a, b, a / b);
break;

default:
printf("Error! operator is not correct");
}

  return 0;
}
