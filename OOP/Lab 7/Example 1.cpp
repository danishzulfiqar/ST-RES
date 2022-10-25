#include <iostream>
#include <conio.h>
using namespace std;
class BaseClass
{ // start of base class
    int num1;

public:                 // public section of class
    void setInt(int n); // function prototype
    int getInt();       // function prototype
};                      // end of base class
class DerivedClass : public BaseClass
{ // start of derived class
    int num2;

public:
    void setJ(int n);         // function prototype
    int mul();                // function prototype
};                            // end of derived class
void BaseClass::setInt(int n) // function declaration
{
    num1 = n;
}
int BaseClass::getInt() // function declaration
{
    return num1;
}
void DerivedClass::setJ(int n) // function declaration
{
    num2 = n;
}
int DerivedClass::mul() // function declaration
{
    cout << "Result=";
    return (num2 * getInt());
}
int main()
{
    DerivedClass ob;          // derived class object
    ob.setInt(10);            // load num1 in BaseClass
    ob.setJ(4);               // load num2 in DerivedClass
    cout << ob.mul() << endl; // displays 40

    return 0;
}