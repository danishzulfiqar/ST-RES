#include <stdio.h>
#include <stdlib.h>

  int main()
{
   char m1[]="Programming is great fun! ";
   char mr[]="Programming is great fun! ";

   puts(m1);

   printf("\n");

   char m2[20];

   printf("Enter m2 string\n");

   gets(m2);

   printf("\n");

   printf("%s\n", strcat(m1,m2));

   char temp[50];

   strncpy(temp,mr,15);

   strcat(temp,m2);

   //puts(temp);

   char *t;

   t = mr;

   strcat(temp," ");

   strcat(temp,t+15);

   printf("\n");

   puts(temp);

    return 0;
}
