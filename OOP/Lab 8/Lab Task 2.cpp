#include <bits/stdc++.h>
using namespace std;

class person
{
    char name[100], gender[10];
    int age;

public:
    void getdata()
    {
        cout << "Name: ";
        fflush(stdin); 
        gets(name);
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
    }
    void display()
    {
        cout << "Name: "<<name<< " Age: "<<age<< " Gender: " <<gender<<endl;
    }
};
class employee : public person
{
    char company[100];
    float salary;

public:
    void getdata()
    {
        person::getdata();
        cout << "Name of Company: ";
        fflush(stdin);
        gets(company);
        cout << "Salary: Rs.";
        cin >> salary;
    }
    void display()
    {
        person::display();
        cout << "Name of Company: " <<company << " Salary: Rs." <<salary<<endl;
    }
};
class teacher : public employee
{
    int number;

public:
    void getdata()
    {
        employee::getdata();
        cout << "grade of teacher : ";
        cin >> number;
    }
    void display()
    {
        employee::display();
        cout << "grade of teacher: " <<number<<endl;
    }
};

int main()
{
    teacher p;
    cout << "Enter data"<<endl;
    p.getdata();
    p.display();
    return 0;
}
