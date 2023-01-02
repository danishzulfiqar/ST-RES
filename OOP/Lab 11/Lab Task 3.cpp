#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAMESIZE = 15;
const int MAXRECORDS = 50;

struct Grades 
{
    char name[NAMESIZE + 1];
    int test1;
    int test2;
    int final;
};

typedef Grades gradeType[MAXRECORDS];

void readit(ifstream &data);

int main()
{
    ifstream indata;
    indata.open("graderoll.dat");

    int numRecord; 
    gradeType studentRecord;

    if (!indata)
    {
        cout << "Error opening file. \n";
        cout << "It may not exist where indicated" << endl;
        return 1;
    }

    readit(indata);

    return 0;
}

void readit(ifstream &data)
{
    string name;
    int t1,t2,final;
    while (!data.eof())
    {
        data>>name>>t1>>t2>>final;
        data.ignore(81, '\n');
        cout<<name<<" "<<t1<<" "<<t2<<" "<<final;
        cout<<endl;
    }
    
}