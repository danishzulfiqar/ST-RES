#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream infile;            // infile will refer to an input file
    ofstream outfile;           // output will refer to output file
    infile.open("payroll.dat"); // This statement opens ‘payroll.data’ as aninput file.
    // Whenever infile is used, data from the file payroll.dat will be read.
    outfile.open("payment.out"); // This statement opens ‘payment.out’ as an output file.
    // Whenever outfile is used, information will be sent to the file payment.out.
    int hours;     // The number of hours worked
    float payRate; // The rate per hour paid
    float net;     // The net pay
    if (!infile)
    {
        cout << "Error opening file.\n";
        cout << "Perhaps the file is not where indicated.\n";
        return 1;
    }
    outfile << fixed << setprecision(2);
    outfile << "Hours Pay Rate Net Pay" << endl;
    infile >> hours;
    while (infile)
    {
        infile >> payRate;
        net = hours * payRate;
        outfile << hours << setw(10) << "$ " << setw(6) << payRate << setw(5) << "$ " << setw(7) << net << endl;
        infile >> hours;
    }
    infile.close();
    outfile.close();
    return 0;
}
