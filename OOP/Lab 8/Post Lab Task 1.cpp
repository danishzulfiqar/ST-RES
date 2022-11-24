#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int empid;

public:
    Employee()
    {
    }
    virtual float salary()
    {
        return 0;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setEmpid(int empid)
    {
        this->empid = empid;
    }

    ~Employee()
    {
        cout << "Employee Destroyeed" << endl;
    }
};

class Regular : public Employee
{

private:
    float basic;

public:
    Regular(float basic)
    {
        this->basic = basic;
    }
    float salary()
    {
        float DA = basic * 0.1;
        float HRA = basic * 0.3;
        return basic + DA + HRA;
    }

    ~Regular()
    {
        cout << "Regular Destroyed" << endl;
    }
};

class Adhoc : public Employee
{

private:
    int number;
    float wagesAmount;

public:
    Adhoc(float wagesAmount)
    {
        this->wagesAmount = wagesAmount;
    }
    float salary()
    {
        return number * wagesAmount;
    }
    void days(int n)
    {
        this->number = n;
    }

    ~Adhoc()
    {
        cout << "Adhoc Destroyed" << endl;
    }
};

int main()
{
    Regular regularEmployee(5000);
    regularEmployee.setName("Peter");
    regularEmployee.setEmpid(15452);
    cout << "The salary of Regular employee: " << regularEmployee.salary() << "\n";
    Adhoc adhocEmployee(40);
    adhocEmployee.setName("Mary");
    adhocEmployee.setEmpid(2565);
    adhocEmployee.days(12);
    cout << "The salary of Adhoc employee: " << adhocEmployee.salary() << "\n";
    return 0;
}