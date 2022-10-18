#include <bits/stdc++.h>
using namespace std;

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    void getdata();
    void display_lat();
    void display_long();
};

class Ship
{
private:
    Angle latitude;
    Angle longitude;
    static int counter;
    int srl_num;

public:
    Ship();
    void get_location();
    void display_location();
};

int Ship::counter = 0;

int main()
{
    Ship S1, S2, S3;
    S1.get_location();
    S1.display_location();

    S2.get_location();
    S2.display_location();

    S3.get_location();
    S3.display_location();

    return 0;
}

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