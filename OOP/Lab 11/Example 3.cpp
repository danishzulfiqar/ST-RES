#include <fstream>
using namespace std;

int main()
{
fstream test ("grade.dat", ios::out);
/* test will refer to ‘grade.dat’ which will be opened as output file, ios::out is
the file access flag*/
// code of the program goes here. The code will put values in the file
test.close(); // close the file
test.open("grade.dat", ios::in);
// the same file is reopened now as an input file ios::in is the
//file access flag
test.close();
}