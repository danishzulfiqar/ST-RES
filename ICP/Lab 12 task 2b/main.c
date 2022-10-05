#include <stdio.h>
#include <stdlib.h>
#define NO_OF_EMP	3


struct Employee
{
	int EmpCode;
	char Name[50];
	int JoiningDate;
	int JoiningMonth;
	int JoiningYear;
};


int main()
{

    int n;
	int day2,day1,mon1,mon2,year1,year2;
	struct Employee E[NO_OF_EMP];
	int day_diff, mon_diff, year_diff;

	printf("\nEnter Current Date  (1-31): "); scanf("%d",&day2);
	printf("\nEnter Current Month (1-12): "); scanf("%d",&mon2);
	printf("\nEnter Current Year  (YYYY): "); scanf("%d",&year2);
	for(n=0;n<NO_OF_EMP;n++)
	{
		printf("\nEnter Emp.-%d Information:",n+1);
		printf("\nEnter Emp. Code    : "); scanf("%d",&E[n].EmpCode);
		printf("\nEnter Emp. Name    : "); scanf("%s",&E[n].Name);
		printf("\nEnter Joining Date : "); scanf("%d",&E[n].JoiningDate);
		printf("\nEnter Joining Month: "); scanf("%d",&E[n].JoiningMonth);
		printf("\nEnter Joining Year : "); scanf("%d",&E[n].JoiningYear);
	}

	for(n=0;n<NO_OF_EMP;n++)
	{
	day1=E[n].JoiningDate;
	mon1=E[n].JoiningMonth;
	year1=E[n].JoiningYear;
    if(day2 < day1)
    {
        if (mon2 == 3)
        {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) day2 += 29;
            else                day2 += 28;
        }


        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)       day2 += 30;
        else           day2 += 31;
        mon2 = mon2 - 1;
    }


    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }


    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;
	if(year_diff>=3 && mon_diff>=0 && mon_diff>=0 &&day_diff>=0)
	{
		printf("\n\nEmployee with more than 3 years of service:");
		printf("\nEmp . ID  : %d",E[n].EmpCode);
		printf("\nEmp . Name: %s",E[n].Name);
	    printf("\n\nPeriod of Service: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);
	}

	}


    return 0;

}
