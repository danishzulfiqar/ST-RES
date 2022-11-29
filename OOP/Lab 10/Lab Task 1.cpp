#include <iostream>
using namespace std;

class base
{
public:
    virtual void iam()
    {
        cout << "base\n";
    }
};
class DerivedClassA : public base
{
public:
    void iam()
    {
        cout << "Derived Class A" << endl;
    }
};
class DerivedClassB : public base
{
public:
    void iam()
    {
        cout << "Derived Class B" << endl;
    }
};
int main()
{
    base *ptrBase;
    DerivedClassA objA;
    DerivedClassB objB;
    objA.iam();
    objB.iam();
    ptrBase = &objA;
    ptrBase->iam();
    ptrBase = &objB;
    ptrBase->iam();
    return 0;
}