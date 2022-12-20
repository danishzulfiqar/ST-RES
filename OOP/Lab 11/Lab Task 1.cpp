#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream payfile;
    payfile.open("payroll.dat");

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

    cout << "Payrate Hours Gross Pay Net Pay" << endl << endl;

    while (!payfile.eof())
    {
        payfile >> payRate >> stateTax >> fedTax;
        gross = payRate * hours;
        net = gross - (gross * stateTax) - (gross * fedTax);
        cout << payRate << setw(12) << hours << setw(12) << gross << setw(12) << net << endl;
    }
    
    payfile.close();

    return 0;
}
