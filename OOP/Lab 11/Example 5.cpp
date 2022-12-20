#include <fstream>
#include <iostream>
using namespace std;
const int ARRAYSIZE = 5;

int main()
{
    fstream test("grade.dat", ios::out | ios::binary);
    // note the use of | to separate file access flags
    int grade[ARRAYSIZE] = {98, 88, 78, 77, 67};
    int count;                                // loop counter
    test.write((char *)grade, sizeof(grade)); // write values of grade array to file
    test.close();                             // close file
    // now add 10 to each grade
    cout << "The values of grades with 10 points added\n";
    for (count = 0; count < ARRAYSIZE; count++)
    {
        grade[count] = grade[count] + 10; // this adds 10 to each elemnt of the array
        cout << grade[count] << endl;     // write the new values to the screen
    }
    test.open("grade.dat", ios::in); // reopen the file but now as an input file
    test.read((char *)grade, sizeof(grade));

    cout << "The grades as they were read into the file" << endl;
    for (count = 0; count < ARRAYSIZE; count++)
    {
        cout << grade[count] << endl; // write the original values to the screen
    }
    test.close();
    return 0;
}