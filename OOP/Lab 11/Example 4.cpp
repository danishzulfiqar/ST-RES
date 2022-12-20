#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_NAME = 11;

int main()
{
ifstream infile; // object to manipulate input file
ofstream outfile; // object to manipulate outfile
infile.open("payroll.dat"); // This statement opens ‘payroll.dat’ as an input file.
while(!infile.fail())
outfile.open("payment.out"); // This statement opens ‘payment.out’ as an output file.
int hours; // The number of hours worked
float payRate; // The rate per hour paid
float net; // The net pay
char ch; // ch is used to hold the next value (read as character) from the file
char name[MAX_NAME]; // array of characters for the name of a student, with at most 10 //characters
if (!infile)
{
cout << "Error opening file.\n";
cout << "Perhaps the file is not where indicated.\n";
return 1;
}
outfile << fixed << setprecision(2);
outfile << "Name Hours Pay Rate Net Pay" << endl;
while ((ch = infile.peek()) != EOF) // reading until not finished
{
infile.get(name,MAX_NAME); // gets names with blanks
infile >> hours;
infile >> payRate;
infile.ignore(81,'\n'); // ignores the rest of the line and consumes end of line marker
net = hours * payRate;
outfile << name << setw(10) << hours << setw(10) << "$" << setw(6) <<
payRate << setw(5) << "$ " << setw(7)<< net << endl;
}
infile.close();
outfile.close();
return 0;
}