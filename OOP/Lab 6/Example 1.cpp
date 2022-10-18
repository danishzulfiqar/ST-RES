#include <iostream>
using namespace std;

class gamma
{
private:
    static int total;
    int id;

public:
    gamma()
    {
        total++;
        id = total;
    }

    ~gamma()
    {
        total--;
        cout << "Destroying ID number : " << id << endl;
    }
    static void showtotal()
    {
        cout << "Total is " << total << endl;
        // cout<<id<<endl; // cannot access non static data member
    }
    void showid()
    {
        cout << "ID number is " << id << endl;
    }
};

// Static data initialization
int gamma::total = 0;
int main()
{
    gamma g1;
    gamma::showtotal(); // Static Type Function is called using class name
    
    gamma g2, g3;
    gamma::showtotal(); // Static Type Function is called using class name

    g1.showid();
    g2.showid();
    g3.showid();

    return 0;
}
