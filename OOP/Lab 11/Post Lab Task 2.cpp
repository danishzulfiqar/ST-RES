#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const int NAMESIZE = 15;

struct budget
{
    char name[NAMESIZE + 1];
    float income;
    float rent;
    float food;
    float utilities;
    float miscell;
    float net;
};

int main()
{
    fstream indata;
    ofstream outdata;
    indata.open("income.dat", ios::out | ios::binary);
    outdata.open("student.out");
    outdata << left << fixed << setprecision(2);
    budget person;
    cout << "Enter the following information" << endl;
    cout << "Person's name: ";
    cin.getline(person.name, NAMESIZE);
    cout << "Income :";
    cin >> person.income;
    cout << "Rent: ";
    cin >> person.rent;
    cout << "Food: ";
    cin >> person.food;
    cout << "Utilities: ";
    cin >> person.utilities;
    cout << "Miscellaneous: ";
    cin >> person.miscell;
    person.net = person.income - person.rent - person.food - person.utilities - person.miscell;

    indata.write(reinterpret_cast<char *>(&person), sizeof(budget));
    indata.close();

    indata.open("income.dat", ios::in | ios::binary);

    indata.read(reinterpret_cast<char *>(&person), sizeof(budget));

    outdata << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent" << setw(10) << "Food" << setw(15) << "Utilities" << setw(15) << "Miscellaneous" << setw(10) << "Net Money" << endl
            << endl;

    outdata << setw(20) << person.name << setw(10) << person.income<< setw(10) << person.rent<< setw(10) << person.food<< setw(15) << person.utilities<< setw(15) << person.miscell<< setw(10) << person.net;

    return 0;
}