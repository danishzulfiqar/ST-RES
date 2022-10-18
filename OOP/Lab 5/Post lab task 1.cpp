#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) // Parametrized constructor
    {
        if (d > 0 && d <= 31)
        {
            day = d;
        }
        if (m > 0 && m <= 12)
        {
            month = m;
        }
        if (y >= 1900)
        {
            year = y;
        }
    }

    void setDate(int m, int d, int y)
    {
        if (d > 0 && d <= 31)
        {
            day = d;
        }
        if (m > 0 && m <= 12)
        {
            month = m;
        }
        if (y >= 1900)
        {
            year = y;
        }
    }

    Date() // Default constructor
    {
        month = 1;
        year = 1900;
        day = 1;
    }
    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }

    void setDay(int day)
    {
        if (day > 0 && day <= 31)
            this->day = day;
    }
    void setMonth(int month)
    {
        if (month > 0 && month <= 31)
            this->month = month;
    }
    void setYear(int year)
    {
        if (year > 1900)
            this->year = year;
    }
    void printDate()
    {
        cout << year << "/";
        if (month > 9)
        {
            cout << month << "/";
        }
        else
        {
            cout << "0" << month << "/";
        }
        if (day > 9)
        {
            cout << day;
        }
        else
        {
            cout << "0" << day;
        }
    }
};

int main()
{
    Date dateDefault; // Assignes default values due to default constructor
    cout << "Default date print : ";
    dateDefault.printDate(); // Default date is prited

    cout << "\nParameter date print : ";
    Date date(12, 25, 2020); // Parametrized constructor is used
    date.printDate();

    // values taken by user
    int m, y, d;
    cout << "\nEnter month : ";
    cin >> m;

    cout << "Enter day : ";
    cin >> d;

    cout << "Enter year : ";
    cin >> y;

    dateDefault.setDate(m, d, y); // Set function used to assign values
    cout << "Entered date is : ";
    dateDefault.printDate(); // Desired values printed
};
