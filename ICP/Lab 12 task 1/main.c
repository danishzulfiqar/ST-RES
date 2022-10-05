#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct car
    {
        char make[20];
        char model[20];
        int capacity;
        float weight;
    };
    struct car c1,c2,c3;
    char n[20];


     printf("Enter Make of car 1\n");
     scanf("%s", c1.make);

     printf("Enter Model of car 1\n");
     scanf("%s",c1.model);


     printf("Enter capacity of car 1\n");
     scanf("%d", &c1.capacity);

     printf("Enter weight of car 1\n");
     scanf("%f", &c1.weight);

     printf("Enter Make of car 2\n");
     scanf("%s",c2.make);

     printf("Enter Model of car 2\n");
     scanf("%s",c2.model);


     printf("Enter capacity of car 2\n");
     scanf("%d", &c2.capacity);

     printf("Enter weight of car 2\n");
     scanf("%f", &c2.weight);

      printf("Enter Make of car 3\n");
     scanf("%s",c3.make);


     printf("Enter Model of car 3\n");
     scanf("%s",c3.model);

     printf("Enter capacity of car 3\n");
     scanf("%d", &c3.capacity);

     printf("Enter weight of car 3\n");
     scanf("%f", &c3.weight);

     printf("\nMake: %s Model: %s Capacity: %d Weight: %.2f\n\n",c1.make,c1.model,c1.capacity,c1.weight);
     printf("\nMake: %s Model: %s Capacity: %d Weight: %.2f\n\n",c2.make,c2.model,c2.capacity,c2.weight);
     printf("\nMake: %s Model: %s Capacity: %d Weight: %.2f\n",c3.make,c3.model,c3.capacity,c3.weight);

     getchar();


    return 0;
}
