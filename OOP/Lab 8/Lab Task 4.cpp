#include <bits/stdc++.h>
using namespace std;

class Teacher
{
private:
    string Name;
    int age;
    string Address;

public:
    void input()
    {
        cout << "\nEnter teacher Name " << endl;
        getline(cin,Name);
        cout << "Enter age " << endl;
        cin >> age;
        cout << "Enter Address " << endl;
        fflush(stdin);
        getline(cin,Address);
    }
    void display()
    {
        cout << "\nYour Name is " << Name << endl;
        cout << "Your Age is " << age << endl;
        cout << "Your Address is " << Address << endl;
    }
};
class Auther
{
private:
    string W_name;
    string W_address;
    int No_Books;

public:
    void input()
    {
        cout << "\nEnter Writer Name " << endl;
        fflush(stdin);
        getline(cin,W_name);
        cout << "Enter Writer Address " << endl;
        fflush(stdin);
        getline(cin,W_address);
        cout << "Enter No of Books written by Writer " << endl;
        cin >> No_Books;
    }
    void display()
    {
        cout << "\nWriter Name :" << W_name << endl;
        cout << "Writer Address :" << W_address << endl;
        cout << "No of Books " << No_Books << endl;
    }
};
class Scholar : public Teacher, public Auther
{
private:
public:
    void input()
    {
        Teacher::input();
        Auther::input();
    }
    void display()
    {
        Teacher::display();
        Auther::display();
    }
};
int main()
{
    Scholar o1;
    o1.input();
    o1.display();
    return 0;
}
