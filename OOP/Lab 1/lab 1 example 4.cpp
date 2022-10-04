#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

int main()
{
    Date birthdate;
    cout<<"Enter day"<<endl;
    cin>>birthdate.day;
    cout<<"Enter Month"<<endl;
    cin>>birthdate.month;
    cout<<"Enter day"<<endl;
    cin>>birthdate.year;

    cout<<birthdate.day<<"/"<<birthdate.month<<"/"<<birthdate.year<<endl;

    return 0;
}