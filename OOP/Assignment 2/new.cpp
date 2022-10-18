
#include <iostream>
using namespace std;
class angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    void getdata()
    {
        cout << "\nenter degrees :";
        cin >> degrees;
        cout << "enter minutes :";
        cin >> minutes;
        cout << "enter direction (N,E,W,S) :";
        cin >> direction;
    }
    void display1()
    {
        cout << "\non latitude :" << degrees << "\xf8" << minutes << "'" << direction;
    }
    void display()
    {
        cout << "\non longitude :" << degrees << "\xf8" << minutes << "'" << direction;
        cout << "\n";
    }
};
class ship
{
private:
    angle latitude;
    angle longitude;
    int ship_number;
    static int count;

public:
    void getposition()
    {
        count++;
        ship_number = count;
        cout << "\nenter direction on latitude :\n";
        latitude.getdata();
        cout << "\nenter direction on longitude :\n";
        longitude.getdata();
    }
    void display()
    {
        cout << "\ndirection of ship number " << ship_number << " is:- \n";
        latitude.display1();
        longitude.display();
    }
};
int ship::count = 0;
int main()
{
    ship ship1, ship2;
    ship1.getposition();
    ship2.getposition();
    ship1.display();
    ship2.display();
    return 0;
}
