#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string address;

public:
    Person(int n, string nam, string ad)
    {
        id = n;
        name = nam;
        address = ad;
    }

    void display()
    {
        cout << "id: " << id << "\nName: " << name << "\nAddress: " << address << endl;
    }
};

class Students : public Person
{
    int roll_num;
    double marks;

public:
    Students(int n, string nam, string ad, int roll, double mrk) : Person(n, nam, ad)
    {
        roll_num = roll;
        marks = mrk;
    }

    void display(void)
    {
        Person::display();
        cout << "Roll Number: " << roll_num << "\nMarks: " << marks;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Person p1(1, "Danish", "Rawalpindi");
    p1.display();

    Students s1(1, "Danish", "Rawalpindi", 42, 97.5);
    s1.display();

    return 0;
}