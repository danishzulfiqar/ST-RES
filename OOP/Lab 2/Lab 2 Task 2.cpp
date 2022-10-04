#include <bits/stdc++.h>
using namespace std;

class Int
{
private:
    int n;

public:
    void initialize_to_zero()
    {
        n = 0;
    }
    void initialize_to_integer(int num)
    {
        n = num;
    }

    void display_integer()
    {
        cout << "The value of integer in Int class is " << n << endl;
    }
     
};

int main()
{ 

    Int obj1;

    obj1.initialize_to_zero();
    obj1.display_integer();

    system("pause");
    int m;
    cout << "Enter a number to initialize the class" << endl;
    cin >> m;
    obj1.initialize_to_integer(m);
    obj1.display_integer();

    return 0;
}