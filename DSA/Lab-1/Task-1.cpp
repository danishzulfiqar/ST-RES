#include <stdio.h>
#include <stdlib.h>

struct emp
{
    char name[48]; 
    int age;
    float bs; 
};

// void flush(void);
int write_records_to_file(struct emp *sptr, int num_records, FILE *fptr);
int read_records_from_file(struct emp *sptr, int num_records, FILE *fptr);
void print_records(struct emp *sptr, int num_records);

int main(void)
{
    FILE *fp;
    char another = 'Y';
    struct emp employee;
    int i = 0;
    int num_rec = 0;

    fp = fopen("employees_records.dat", "wb");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    while (another == 'Y')
    {
        printf("\nEnter the name of the Employee: ");
        fgets(employee.name, 48, stdin);
        printf("\nEnter the age of the Employee: ");
        scanf("%d", &employee.age);
        printf("\nEnter the Basic Salary of the Employee: ");
        scanf("%f", &employee.bs);
       
        fwrite(&employee, sizeof(struct emp), 1, fp);
        // flush();
        fflush(stdin);
        printf("Add another record (Y/N) ");
        another = getchar();
        // flush();
        fflush(stdin);
        i++;
    }

    fclose(fp);
    return (0);
}
