#include <iostream>
#include <cstring>
using namespace std;
class Address
{
private:
    char street[100];
    char house[100];
    char city[100];
    char code[100];

public:
    void get_data()
    {
        cout << "\nEnter code for house:";
        cin.getline(code, 100);
        cout << "Enter house no:";
        cin.getline(house, 100);
        cout << "Enter street name:";
        cin.getline(street, 100);
        cout << "Enter city name:";
        cin.getline(city, 100);
    }
    void set_data(char a[], char b[], char c[], char d[])
    {
        strcpy(street, a);
        strcpy(house, b);
        strcpy(city, c);
        strcpy(code, d);
    }
    void display_data()
    {
        cout << "\nAddress:" << code << ",house no." << house << ",street." << street << ", " << city << ", " << endl;
    }
};

class Person
{
private:
    Address add;

public:
    void get_data()
    {
        add.get_data();
    }

    void display_data()
    {
        add.display_data();
    }

};

 int main()
{
    Address a1, a2;
    a1.get_data();
    cout << "Address a1:";
    a1.display_data();
    cout << "\nAddress a2:";
    a2.set_data("comsats", "32", "Islamabad", "engineering");
    a2.display_data();

    Person p1;
    p1.get_data();
    p1.display_data();

    return 0;
}
