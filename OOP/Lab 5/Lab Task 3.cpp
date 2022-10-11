#include <bits/stdc++.h>
using namespace std;

class Race
{
private:
    int carNo, driverID, carModel;

public:
    Race() : carNo(0), driverID(0), carModel(0)
    {
    }
    void setValues(int cn, int di, int cm)
    {
        carNo = cn;
        driverID = di;
        carModel = cm;
    }
    void InputValues()
    {
        cout << "Enter the car no,";
        cout << "Enter the driver id,";
        cout << "Enter the car model of the following"<<endl;;
    }
    void display()
    {
        cout << "The car number is = " << carNo;
        cout << "\n The driver id is = " << driverID;
        cout << "\n The car model is = " << carModel;
    }
};
int main()
{
    Race A, B;
    int cn, di, cm;
    A.InputValues();
    cin >> cn;
    cin >> di;
    cin >> cm;
    A.setValues(cn, di, cm);
    A.display();
    cout << "\n information of second person\n";
    B.InputValues();
    cin >> cn;
    cin >> di;
    cin >> cm;
    B.setValues(cn, di, cm);
    B.display();
    return 0;
};