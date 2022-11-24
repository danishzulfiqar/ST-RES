#include <iostream>

using namespace std;

class LocPhone
{
private:
    string phone;

public:
    void input()
    {
        cin >> phone;
    }
    void display()
    {
        cout << phone;
    }
};

class NatPhone : public LocPhone
{
private:
    string cityCode;

public:
    void input()
    {
        cin >> cityCode;
    }
    void display()
    {
        cout << cityCode;
    }
};

class IntPhone : public NatPhone
{
private:
    string countryCode;

public:
    void input()
    {
        cin >> countryCode;
    }
    void display()
    {
        cout << countryCode;
    }
};

int main()
{
    LocPhone *localPhone = new LocPhone();
    cout << "Enter phone: ";
    localPhone->input();

    cout << "Local phone: ";
    localPhone->display();
    cout << endl
         << endl;

    LocPhone *nationalPhone = new NatPhone();
    cout << "Enter city code: ";
    nationalPhone->input();

    cout << "City code: ";
    nationalPhone->display();
    cout << endl
         << endl;

    LocPhone *internationalPhone = new IntPhone();
    cout << "Enter country code: ";
    internationalPhone->input();

    cout << "Country code: ";
    internationalPhone->display();
    cout << endl
         << endl;

    delete localPhone;
    delete nationalPhone;
    delete internationalPhone;

    return 0;
}