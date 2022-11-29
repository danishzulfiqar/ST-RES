#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class person // person class
{
protected:
    string name;

public:
    void getName()
    {
        cout << " Enter name: ";
        cin >> name;
    }
    void putName()
    {
        cout << "Name is: " << name << endl;
    }

    virtual void getData() = 0;       // pure virtual func
    virtual bool isOutstanding() = 0; // pure virtual func
};
class student : public person // student class
{
private:
    float gpa; // grade point average
public:
    void getData() // get student data from user
    {
        person::getName();
        cout << " Enter student's GPA: ";
        cin >> gpa;
    }
    bool isOutstanding()
    {
        return (gpa > 3.5) ? true : false;
    }
};
class professor : public person // professor class
{
private:
    int numPubs; // number of papers published
public:
    void getData() // get professor data from user
    {
        person::getName();
        cout << " Enter number of professor's publications: ";
        cin >> numPubs;
    }
    bool isOutstanding()
    {
        return (numPubs > 100) ? true : false;
    }
};
int main()
{
    person *persPtr[100]; // array of pointers to persons
    int n = 0;            // number of persons on list
    char choice;
    do
    {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;
        if (choice == 's') // put new student
            persPtr[n] = new student;
        else // put new professor
            persPtr[n] = new professor;
        persPtr[n++]->getData(); // get data for person
        cout << " Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');    // cycle until not 'y'
    for (int j = 0; j < n; j++) // print names of all persons
    {
        persPtr[j]->putName();
        if (persPtr[j]->isOutstanding())
            cout << " This person is outstanding\n";
    }
    system("pause");
    return 0;
} // end main()