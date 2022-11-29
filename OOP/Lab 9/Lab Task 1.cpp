#include <iostream>
#include <string>
using namespace std;
class studentRecord
{
private:
    string degree;

public:
    studentRecord() { cout << "Constructor is called for student record" << endl; }
    ~studentRecord() { cout << "Destructor is called for student record" << endl; }
    void getdata()
    {
        cout << "Enter Degree: ";
        cin >> degree;
    }
    void display_data()
    {
        cout << "Degree:" << degree << endl;
    }
};
class employeeRecord
{
private:
    int emp_id;
    double salary;

public:
    employeeRecord() { cout << "Constructor is called for employee record" << endl; }
    ~employeeRecord() { cout << "destructor is called for employee record" << endl; }
    void getdata()
    {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void display_data()
    {
        cout << "Employee ID:" << emp_id << endl;
        cout << "Salary:" << salary << endl;
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
    void display_data()
    {
        emp.getdata();
        cout << "\nTitle:" << title << endl;
        cout << "Dues:" << dues << endl;
        stu.display_data();
    }
};
int main()
{
    manager m1;
    cout << "\nEnter data for manager 1: " << endl;
    m1.getdata();
    return 0;
}
