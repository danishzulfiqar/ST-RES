#include <iostream>
using namespace std;
class Date
{
public:
    int day, month, year;
    void enter_data()
    {
        cout << "Enter the day:";
        cin >> day;
        cout << "Enter the month:";
        cin >> month;
        cout << "Enter the year:";
        cin >> year;
    }
    void display_data()
    {
        cout << "Date<day/month/year>:" << day << "/" << month << "/" << year << endl;
    }
};
class Employee
{
public:
    string name;
    int current_year;
    Date date_of_birth, date_of_joining;
    void enter_data()
    {
        cout << "Current year:2012" << endl;
        cout << "Enter name of employee:";
        getline(cin, name);
        cout << "Date of birth:" << endl;
        date_of_birth.enter_data();
        cout << "\nDate of joining the organization:" << endl;
        date_of_joining.enter_data();
    }
    void employee_service()
    {
        int temp;
        temp = 2022 - (date_of_joining.year);
        if (temp > 5)
        {
            cout << "\nEmployee has service greater than 5 years." << endl;
            cout << "Total service with organization:" << temp << endl;
        }
        else if (temp == 5)
        {
            cout << "\nEmployee has service equal to 5 years." << endl;
            cout << "Total service with organization:" << temp << endl;
        }
        else if (temp < 5 && temp > 0)
        {
            cout << "\nEmployee has service less than 5 years." << endl;
            cout << "Total service with organization:" << temp << endl;
        }
        else
        {
            cout << "Has no service with organization" << endl;
        }
        cout << "Joining ";
        date_of_joining.display_data();
    }
    void employee_age()
    {
        int temp_age;
        temp_age = 2022 - (date_of_birth.year);
        if (temp_age > 40)
        {
            cout << "\nEmployee age is grater than 40 years" << endl;
            cout << "Age:" << temp_age << endl;
        }
        else if (temp_age == 40)
        {
            cout << "\nEmployee age is equal to 40 years" << endl;
            cout << "Age:" << temp_age << endl;
        }
        else if (temp_age < 40 && temp_age > 0)
        {
            cout << "\nEmployee age is less than 40 years" << endl;
            cout << "Age:" << temp_age << endl;
        }
        cout << "Birth ";
        date_of_birth.display_data();
    }
};
int main()
{
    Employee e1;
    e1.enter_data();
    e1.employee_service();
    e1.employee_age();
    return 0;
}
