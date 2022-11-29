#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    virtual void salary() = 0;
    virtual void display() = 0;
};
class salariedemployee : public Employee
{
private:
    long emp_num;
    string name;
    double sal;

public:
    void salary()
    {
        cout << "Enter employee number" << endl;
        cin >> emp_num;
        cout << "Enter employee name" << endl;
        cin >> name;
        cout << "Enter employee salary" << endl;
        cin >> sal;
    }
    void display()
    {
        cout << "Employee Number is " << emp_num << endl;
        cout << "Employee Name is " << name << endl;
        cout << "Employee Salary is " << sal << endl;
    }
};
class hourlyemployee : public Employee
{
private:
    string name;
    double result;
    double hours;
    double rate;

public:
    void salary()
    {
        cout << "Enter employee name " << endl;
        cin >> name;
        cout << "Enter hourly rate of " << name << endl;
        cin >> rate;
        cout << "Enter hours " << name << " worked " << endl;
        cin >> hours;
    }
    void display()
    {
        result = hours * rate;
        cout << name << "'s Hourly salary is " << result << endl;
    }
};
class commisonedemployee : public Employee
{
private:
    string name;
    double result;
    int overtime;
    double sal;

public:
    void salary()
    {
        cout << "Enter employee name " << endl;
        cin >> name;
        cout << "Enter " << name << "'s salary " << endl;
        cin >> sal;
        cout << "Enter " << name << "'s overtime " << endl;
        cin >> overtime;
    }
    void display()
    {
        result = overtime * 2500;
        cout << name << "'s salary is " << result + sal << endl;
    }
};
int main()
{
    Employee *e[2];
    salariedemployee s;
    hourlyemployee h;
    commisonedemployee c;
    cout << " DATA FOR MONTHLY EMPLOYEE " << endl;
    e[0] = &s;
    e[0]->salary();
    e[0]->display();
    cout << "\n DATA FOR HOURLY EMPLOYEE " << endl;
    e[1] = &h;
    e[1]->salary();
    e[1]->display();
    cout << " DATA FOR COMMISIONED EMPLOYEE " << endl;
    e[2] = &c;
    e[2]->salary();
    e[2]->display();
    system("pause");
    return 0;
}