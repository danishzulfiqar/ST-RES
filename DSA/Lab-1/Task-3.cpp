#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    char name[48];
    int age;
    float bs;
};

int read_records_from_file(struct emp *sptr, int num_records, FILE *fptr);
void print_records(struct emp *sptr, int num_records);

int main(void)
{
    FILE *fp;
    char another = 'Y';
    struct emp *employees;
    int num_rec = 0;
    int i;

    printf("Enter the number of records to read: ");
    scanf("%d", &num_rec);

    employees = (struct emp *)malloc(num_rec * sizeof(struct emp));

    fp = fopen("employees_records2.dat", "rb");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    int num_read = read_records_from_file(employees, num_rec, fp);
    printf("\n%d records read from file.\n", num_read);
    print_records(employees, num_rec);

    fclose(fp);
    free(employees);

    return 0;
}

int read_records_from_file(struct emp *sptr, int num_records, FILE *fptr)
{
    char line[100];
    int num_read = 0;

    for (int i = 0; i < num_records; i++)
    {
        fgets(line, sizeof(line), fptr);
        strcpy(sptr[i].name, line);

        fgets(line, sizeof(line), fptr);
        int age = atoi(line);
        sptr[i].age = age;

        fgets(line, sizeof(line), fptr);
        float bs = atoi(line);
        sptr[i].bs = bs;

        num_read++;
    }

    return num_read;
}

void print_records(struct emp *sptr, int num_records)
{
    for (int i = 0; i < num_records; i++)
    {
        printf("\n%d. Name: %sAge: %d, Salary: %f\n", (i + 1), sptr[i].name, sptr[i].age, sptr[i].bs);
    }
}
