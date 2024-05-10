#include <stdio.h>
#include <stdlib.h>

struct emp
{
    char name[48];
    int age;
    float bs;
};

int write_records_to_file(struct emp *sptr, int num_records, FILE *fptr);

int main(void)
{
    FILE *fp;
    struct emp *employees;
    int num_rec = 0;
    int i;

    printf("Enter the number of records to write: ");
    scanf("%d", &num_rec);

    employees = (struct emp *)malloc(num_rec * sizeof(struct emp));

    fp = fopen("employees_records2.dat", "wb");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    for (i = 0; i < num_rec; i++)
    {
        printf("\nEnter the name of the Employee: ");

        fflush(stdin);
        fgets(employees[i].name, 48, stdin);

        printf("Enter the age of the Employee: ");
        scanf("%d", &employees[i].age);

        printf("Enter the Basic Salary of the Employee: ");
        scanf("%f", &employees[i].bs);
    }

    int num_written = write_records_to_file(employees, num_rec, fp);
    printf("\n%d records written to file.\n", num_written);

    fclose(fp);
    free(employees);

    return 0;
}

int write_records_to_file(struct emp *sptr, int num_records, FILE *fptr)
{
    int num_written = 0;
    int i;
    for (i = 0; i < num_records; i++)
    {
        fprintf(fptr, "%s", sptr[i].name);
        fprintf(fptr, "%d\n", sptr[i].age);
        fprintf(fptr, "%0.2f\n", sptr[i].bs);
        num_written++;
    }
    return num_written;
}
