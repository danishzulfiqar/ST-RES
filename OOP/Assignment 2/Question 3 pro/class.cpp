#include <bits/stdc++.h>
#include "class.hpp"
using namespace std;


// Defination Of Angle Class Funtions

void Angle::getdata()
{
    cout << "Enter degrees :";
    cin >> degrees;
    cout << "Enter minutes :";
    cin >> minutes;
    cout << "Enter direction (N,E,W,S) :";
    cin >> direction;
}
void Angle::display_lat()
{
    cout << "On latitude :" << degrees << "." << minutes << "'" << direction << endl;
}
void Angle::display_long()
{
    cout << "On longitude :" << degrees << "." << minutes << "'" << direction << endl;
}

// Defination of Ship Class Functions

Ship ::Ship()
{
    counter++;
    srl_num = counter;
}

void Ship::get_location()
{
    cout << "\nEnter direction on latitude" << endl;
    latitude.getdata();
    cout << "\nEnter direction on longitude" << endl;
    longitude.getdata();
    cout << endl;
}

void Ship::display_location()
{
    cout << "\nSerial Number: " << srl_num << endl;
    latitude.display_lat();
    longitude.display_long();
}