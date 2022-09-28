#include <iostream>
using namespace std;

class add
{
private:
    int iNum1, iNum2, iNum3;

public:
    add()
    {
        cout<<"Constructor is called"<<endl;
    }
};
    
int main()
{
    add A1;

    return 0;
}
