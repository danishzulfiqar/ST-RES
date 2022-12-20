#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream payfile;
    ofstream outfile;

    payfile.open("data.txt");
    outfile.open("pay.out");

    float gross;
    float net;
    float hours = 5;
    float payRate;
    float stateTax;
    float fedTax;

    cout << fixed << setprecision(2) << showpoint;

    if (!payfile)
    {
        cout << "Error opening file. \n";
        cout << "It may not exist where indicated" << endl;
        return 1;
    }

    char ch;

    while ((ch = payfile.peek()) != EOF) // reading until not finished
    {
        payfile >> hours >> payRate >> stateTax >> fedTax;
        payfile.ignore(81, '\n'); // ignores the rest of the line and consumes end of line marker
        net = hours * payRate;
        outfile << hours << setw(10) << "$" << setw(6) << payRate << setw(5) << "$ " << setw(7) << net << endl;
    }

    payfile.close();
    outfile.close();

    return 0;
}
