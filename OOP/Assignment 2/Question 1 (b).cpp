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

    int getcrow(); // Function declared inside the calss
};

int leverage::getcrow() // Defination of class public member function
{
    return crowbar; // returns value of crowbar i.e. data of object of leverage calss
}

int main()
{
    leverage lever1; // An object made of class leverage, constructor initializes its members to zero

    lever1.pry(); // statement to call prey funtion

    cout << lever1.getcrow() << endl;

    return 0;
}