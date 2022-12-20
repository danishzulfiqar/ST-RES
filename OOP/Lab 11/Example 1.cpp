#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream infile;
    infile.open("payroll.dat");
    
    if (!infile)
    {
        cout << "Error opening file.It may not exist were indicated.\n";
        return 1;
    }

    return 0;
}