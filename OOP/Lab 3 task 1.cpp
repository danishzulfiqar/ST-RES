#include <iostream>
using namespace std;

class add 
{
private:
    int iNum1, iNum2, iNum3; 


public:
    void input(int iVar1, int iVar2) 
    {
        cout << "Functions to assign values to the member data" << endl;
        iNum1 = iVar1;
        iNum2 = iVar2;
    }


    void sum(void) 
    {
        cout << "Functions to find the sum of two numbers" << endl;
        iNum3 = iNum1 + iNum2;
    }


    void disp(void) 
    {
        cout << "The sum of the two numbers is " << iNum3 << endl;
    }
};

int main()
{
    add A1;
    int iX, iY;
    cout << "Input two numbers" << endl;
    cin >> iX;
    cin >> iY;
    A1.input(iX, iY);
    A1.sum();
    A1.disp();
    system("pause");
    // cout<<A1.iNum1<<endl;  Gives Error if called as private data member of the class 
}