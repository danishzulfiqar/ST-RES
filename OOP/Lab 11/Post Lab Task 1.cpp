#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream gradesFile;
    ofstream letterGradesFile;
    string name;
    float test1, test2, final;
    char letterGrade;

    gradesFile.open("grades.dat");
    letterGradesFile.open("letterGrades.dat");

    if (!gradesFile || !letterGradesFile)
    {
        cout << "Error opening one of the files. \n";
        cout << "It may not exist where indicated" << endl;
        return 1;
    }

    cout << "Name Test1 Test2 Final Letter Grade" << endl;
    letterGradesFile << "Name Test1 Test2 Final Letter Grade" << endl;

    gradesFile >> name >> test1 >> test2 >> final;
    while (gradesFile)
    {
        float average = (test1 * 0.3) + (test2 * 0.3) + (final * 0.4);
        if (average >= 90)
            letterGrade = 'A';
        else if (average >= 80)
            letterGrade = 'B';
        else if (average >= 70)
            letterGrade = 'C';
        else if (average >= 60)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        cout << name << setw(5) << test1 << setw(5) << test2 << setw(5) << final << setw(5) << letterGrade << endl;
        letterGradesFile << name << setw(5) << test1 << setw(5) << test2 << setw(5) << final << setw(5) << letterGrade << endl;

        gradesFile >> name >> test1 >> test2 >> final;
    }

    gradesFile.close();
    letterGradesFile.close();
    return 0;
}