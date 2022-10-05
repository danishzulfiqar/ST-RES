#include <stdio.h>
#include <stdlib.h>

int main()
{
char choice;
int  state=1;
while (choice != 'c')
{
printf("\n\tMENU Given below:");
printf("\n\t---------------");
printf("\n\n\t 1. Write a");
printf("\n\t 2. Write b");
printf("\n\n Enter Your Choice: ");
scanf("%ch",&choice);
switch(choice)
{
case 'a':
printf("You are in state 2",choice);
break;
case 'b':
printf("You are in state 1",choice);
break;
default:
printf("\nINVALID SELECTION...Please try again");
}
getchar();
}
}
