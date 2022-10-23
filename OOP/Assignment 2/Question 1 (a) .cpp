#include <bits/stdc++.h>
using namespace std;

class leverage
{
private:
    int crowbar;

public:
    leverage() : crowbar(0) {} // Constructor That initializes the crowbar to 0

    void pry() // pry function that is public in the class
    {
    }

    int getcrow() // public function defined to return the value of crowbar
    {
        return crowbar;
    }

};

int main()
{
    leverage lever1; // An object made of class leverage, constructor initializes its members to zero

    lever1.pry(); // statement to call prey funtion

    cout << lever1.getcrow() << endl; // Prints value of crowbar that is zero due to constructor

    return 0;
}