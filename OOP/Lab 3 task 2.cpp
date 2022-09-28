#include <iostream>
using namespace std;
class add
{
private:
    int iNum1, iNum2, iNum3;

    void input(int iVar1, int iVar2)
    {
        cout << "Functions to assign values to the member data "<<endl;
            iNum1 = iVar1;
        iNum2 = iVar2;
    }

    void sum(void)
    {
        cout << "Functions to find the sum of two numbers was called!"<<endl;
            iNum3 = iNum1 + iNum2;
    }

    void disp(void)
    {
        cout << "The sum of the two numbers is " << iNum3 << endl;
    }

public:
    void call()
    {
        cout << "Input Two Numbers " << endl;
        cin >> iNum1;
        cin >> iNum2;

        if(iNum1<0 || iNum2<0)
        {
            cout<<"You cannot enter negative number!"<<endl;;
            call();
            return;
        }
        
        input(iNum1, iNum2);
        sum();
        disp();
    }
};

int main()
{
    add A1;
    A1.call();
    return 0;
}