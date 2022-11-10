#include <iostream>
using namespace std;

class base
{
private:
    int pridataA; // private data member
protected:
    int prodataA; // protected data member
public:
    int pubdataA; // public data member
};
class derived1 : public base // publically - derived class
{
public:
    void funct()
    {
        int a;
        a = pridataA; // error: not accessible
        a = prodataA; // ok
        a = pubdataA; // ok
    }
};
class derived2 : public base // privately - derived class
{
public:
    void funct()
    {
        int a;
        a = pridataA; // error: not accessible
        a = prodataA; // ok
        a = pubdataA; // ok
    }
};
int main()
{
    int a;
    derived1 objd1;
    a = objd1.pridataA; // error: not accessible
    a = objd1.prodataA; // error: not accessible
    a = objd1.pubdataA; // ok (base public to derived1)
    derived2 objd2;
    a = objd2.pridataA; // error: not accessible
    a = objd2.prodataA; // error: not accessible
    a = objd2.pubdataA; // error: not accessible (base private to derived2)
    return 0;
}