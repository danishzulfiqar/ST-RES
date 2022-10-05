#include <stdio.h>
#include <stdlib.h>


void test(void);

int m = 22, n = 44;
float a = 50.5, b = 8.79;

int main()
{
 int x, y=5, z = 5;

 printf("The address of x is %u\n", &x);
 printf("The address of y is %u\n", &y);
 printf("The address of z is %u\n", &z);
 printf("The address of m is %u\n", &m);
 printf("The address of n is %u\n", &n);
 printf("The address of a is %u\n", &a);
 printf("The address of b is %u\n", &b);

 test();
}

void test()
{
 char ch1 = 'F', ch2 = 69, ch3 = 100;
 int x = 5, y = 55, z = 8;
  printf("The address of ch1 is %u\n", &ch1);
  printf("The address of ch2 is %u\n", &ch2);
  printf("The address of ch3 is %u\n", &ch3);
  printf("The address of x is %u\n", &x);
  printf("The address of y is %u\n", &y);
  printf("The address of z is %u\n", &z);


}
