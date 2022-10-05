#include <stdio.h>
#include <stdlib.h>

struct car
{
    char name[20];
    char model[20];
    int capacity;
    float weight;

} c[20];

int main()
{
    int n,i;

    printf("Enter the number of cars\n");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter name of %d car\n", i+1);
        fflush(stdin);
        gets(c[i].name);

        printf("Enter model of %d car\n", i+1);
        fflush(stdin);
        gets(c[i].model);

        printf("Enter capacity of %d car\n", i+1);
        scanf("%d", &c[i].capacity);

        printf("Enter weight of %d car\n", i+1);
        scanf("%f", &c[i].weight);
    }

    printf("\nName\tModel\tCapacity\tWeight\n\n");

    for(i=0;i<n;i++)
    {
        printf("%s\t%s\t   %d \t        %.2f\n",c[i].name,c[i].model,c[i].capacity,c[i].weight);
    }

    char namecheck[20];

    printf("\n\nEnter name of car you want\n");
    fflush(stdin);
    gets(namecheck);

    int modify;

    for(i=0;i<n;i++)
    {
        if(strcmpi(namecheck,c[i].name) == 0)
        {
            printf("\nWe have\n\nModel: %s \nCapacity: %d\tweight: %.2f\n",c[i].model,c[i].capacity,c[i].weight);

            printf("\nWhat do you want to modify\n1.Capacit\n2.Weight\n3.Both\n");
            scanf("%d", &modify);

            switch(modify)

            {
            case 1:
                printf("\nEnter capacity\n");
                scanf("%d", &c[i].capacity);
                break;

            case 2:
                printf("\nEnter weight changes\n");
                scanf("%f", &c[i].weight);
                break;

            case 3:
                printf("\nEnter capacity\n");
                scanf("%d", &c[i].capacity);

                printf("\nEnter weight changes\n");
                scanf("%f", &c[i].weight);
            }

           printf("\nThe changes are\n\nModel: %s\tCapacity: %d\tWeight: %.2f\n",c[i].model,c[i].capacity,c[i].weight);

        }
    }

    return 0;

} //Author: Danish Zulfiqar
