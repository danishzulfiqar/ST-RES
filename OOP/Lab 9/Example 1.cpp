#include <iostream>
#include <string>
using namespace std;

class studentRecord
{
private:
    string degree;

public:
    studentRecord()
    {
    }
    void getdata()
    {
        cout << "Enter Degree: ";
        cin >> degree;
    }
};
class employeeRecord
{
private:
    int emp_id;
    double salary;

public:
    employeeRecord()
    {
    }
    void getdata()
    {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
};
class manager
{
private:
    string title;
    double dues;
    employeeRecord emp;
    studentRecord stu;

public:
    void getdata()
    {
        emp.getdata();
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Dues: ";
        cin >> dues;
        stu.getdata();
    }
};
int main()
{
    manager m1;
    cout << "Enter data for manager 1: ";
    m1.getdata();

    return 0;
}
