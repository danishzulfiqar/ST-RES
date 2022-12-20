#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// This program reads records from a file. The file contains the following: student’s name,
// two test grades and final exam grade. It then prints this information to the screen. 
const int NAMESIZE = 15;
const int MAXRECORDS = 50;

struct Grades // declares a structure to store information from file
{
    char name[NAMESIZE + 1];
    int test1;
    int test2;
    int final;
};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type that holds MAXRECORDS
// Fill in the code for the prototype of the function readit
// where the first argument is an input file, the second is the
// array of records, and the third will hold the number of
// records currently in the array.
int main()
{
    ifstream indata;
    indata.open("graderoll.dat");
    int numRecord; // number of records to read in
    gradeType studentRecord;
    if (!indata)
    {
        cout << "Error opening file. \n";
        cout << "It may not exist where indicated" << endl;
        return 1;
    }
    // fill in the code to call the function ReadIt.
    // output the information
    for (int count = 0; count < numRecord; count++)
    {
        cout << studentRecord[count].name << setw(10) << studentRecord[count].test1 << setw(10) << studentRecord[count].test2;
        cout << setw(10) << studentRecord[count].final << endl;
    }
    
    return 0;
}
