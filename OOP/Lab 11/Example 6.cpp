#include <fstream>
#include <iostream>
#include <cctype> // for toupper function
using namespace std;
const int NAMESIZE = 31;
struct Grades // declaring a structure
{
    char name[NAMESIZE];
    int test1;
    int test2;
    int final;
};

int main()
{
    fstream tests("score.dat", ios::out | ios::binary); // defines tests object referring to ‘score’dat’ file which will be opened as an output binary file
    Grades student;
    char more; // used to determine if there is more input
     do
    {
        cout << "Enter the following information" << endl;
        cout << "Student’s name: ";
        cin.getline(student.name, NAMESIZE);
        cout << "First test score :";
        cin >> student.test1;
        cin.ignore(); // ignore rest of line
        cout << "Second test score: ";
        cin >> student.test2;
        cin.ignore();
        cout << "Final test score: ";
        cin >> student.final;
        cin.ignore();
        tests.write((char *)&student, sizeof(student)); // write this record to  the file referred by tests object
                cout
            << "Enter a y if you would like to input more data\n ";
        cin >> more;
        cin.ignore();
    }
    while (toupper(more) == 'Y');
    tests.close();
    return 0;
}
