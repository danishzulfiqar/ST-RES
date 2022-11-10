#include <bits/stdc++.h>
using namespace std;

class Date
{
protected:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0)
    {
        cout << "\nDay:" << day << endl
             << "Month:" << month << endl
             << "Year:" << year << endl;
    }
    void display()
    {
        cout << "\nDay:" << day << endl
             << "Month:" << month << endl
             << "Year:" << year << endl;
    } 
    void get()
    {
        Date ::set();
        Date ::display();
    } 
    void set()
    {
        cout << "\nEnter the day, month, year: " << endl;
        cin >> day >> month >> year;
    } 
};
class Time
{
protected:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0)
    {
        cout << "\nHour:" << hour << endl
             << "Minute:" << minute << endl
             << "Second:" << second << endl;
    }
    void display()
    {
        cout << "\nHour:" << hour << endl
             << "Minute:" << minute << endl
             << "Second:" << second << endl;
    } 
    void get()
    {
        Time ::set();
        Time ::display();
    } 
    void set()
    {
        cout << "\nEnter the hours, minutes, seconds: " << endl;
        cin >> hour >> minute >> second;
    } 
};
class DateAndTime : public Date, public Time
{
    int digital;

public:
    void display()
    {
        Date::get();
        Time::get();
    } 
};
int main()
{
    DateAndTime Watch;
    Watch.display();
    return 0;
}