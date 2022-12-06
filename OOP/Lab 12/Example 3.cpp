#include <iostream>
using namespace std;
class Date
{
    int mo, da, yr; // Variable Declaration
public:
    // Constructor
    Date(int m, int d, int y)
    {
        mo = m;
        da = d;
        yr = y;
    }
    friend ostream &operator<<(ostream &os, const Date &dt);
};
ostream &operator<<(ostream &os, const Date &dt)
{
    // os as cout
    os << dt.mo << "/" << dt.da << "/" << dt.yr;
    return os;
}
/////////////main function//////////
int main()
{
    Date dt(5, 6, 92);
    cout << dt;
    
    return 0;
}

