#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main()
{
fstream inFile("letterGrades.txt", ios::in);
long offset; // used to hold the offset of the read position from some point
char ch; // holds character read at some position in the file
char more; // used to indicate if more information is to be given

do
{
cout << "The read position is currently at byte "<< inFile.tellg() << endl;
// This prints the current read position (found by the tellg function)
cout << "Enter an offset from the beginning of the file: ";
cin >> offset;
inFile.seekg(offset, ios::beg);
// This moves the pointer upto offset length from the beginning of the file.
inFile.get(ch); // This gets one byte of information from the file
cout << "The character read is " << ch << endl;
cout << "If you would like to input another offset enter a Y" << endl;
cin >> more;
inFile.clear(); // This clears the file in case the EOF flag was set
}
while (toupper(more) == 'Y');

inFile.close();
return 0;
}