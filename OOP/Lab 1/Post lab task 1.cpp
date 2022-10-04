#include <iostream>
using namespace std;

struct employee
{
    int code;
    string name;
    int day;
    int month;
    int year;
};

int main()
{
    int n;
    cout << "Enter the number of employees" << endl;
    cin >> n;

    employee em[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter id" << endl;
        cin >> em[i].code;

        cout << "Enter Name" << endl;
        cin >> em[i].name;

        cout << "Enter date of joining" << endl;
        cin >> em[i].day >> em[i].month >> em[i].year;
    }

    int cd, cm, cy;

    cout << "Enter current date" << endl;
    cin >> cd >> cm >> cy;

    cout << "Employees with more than 3 years are" << endl;

    for (int i = 0; i < n; i++)
    {
        if ((cy - em[i].year) >= 3)
        {
            cout << "id: " << em[i].code << endl;
            cout << "name: " << em[i].name << endl;
            cout << "join Date: " << em[i].day << "/" << em[i].month << "/" << em[i].year << endl;
        }

        else if (((cy - em[i].year) * 365) + (abs(cm - em[i].month) * 30) + (abs(cd - em[i].day) * 1) >= (365 * 3))
        {
            cout << "id: " << em[i].code << endl;
            cout << "name: " << em[i].name << endl;
            cout << "join Date: " << em[i].day << "/" << em[i].month << "/" << em[i].year << endl;
        }
    }

    return 0;

}// Author: Danish Zulfiqar