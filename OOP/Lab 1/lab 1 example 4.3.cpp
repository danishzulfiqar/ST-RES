#include <iostream>

using namespace std;

void duplicate(int &var1, int &var2, int &var3)
{
    var1 *= 2;
    var2 *= 2;
    var3 *= 2;
}
int main()
{
    int x = 1, y = 3, z = 7;
    duplicate(x, y, z);
    cout << "x=" << x << ", y=" << y << ", z=" << z;
    return 0;
}
