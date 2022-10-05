#include <stdio.h>
#include <stdlib.h>

int main()
{
    char num[]="1234";
    int n;

    printf("The string is\n");
    puts(num);

    n= atoi(num);

    printf("The number is %d\n", n);

    return 0;
}
