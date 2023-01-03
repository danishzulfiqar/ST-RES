#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Record {
    string name;
    float income;
    float rent;
    float food;
    float utilities;
    float miscell;
    float net;
};

int main() {
    Record record;

    // read the input from the keyboard
    cout << "Enter the following information" << endl;
    cout << "Person's Name: ";
    getline(cin, record.name);
    cout << "Income: ";
    cin >> record.income;
    cout << "Rent: ";
    cin >> record.rent;
    cout << "Food: ";
    cin >> record.food;
    cout << "Utilities: ";
    cin >> record.utilities;
    cout << "Miscellaneous: ";
    cin >> record.miscell;

    // calculate the net
    record.net = record.income - (record.rent + record.food + record.utilities + record.miscell);

    // open the binary file in write mode
    ofstream income_file("income.dat", ios::binary);
    if (income_file.is_open()) {
        // write the record to the binary file
        income_file.write((char*)&record, sizeof(record));
        income_file.close();
    } else {
        cout << "Error opening file" << endl;
    }

    // open the binary file in read mode
    ifstream income_file_in("income.dat", ios::binary);
    if (income_file_in.is_open()) {
        // read the record from the binary file
        income_file_in.read((char*)&record, sizeof(record));

        // print the record
        cout << "Name: " << record.name << endl;
        cout << "Income: " << record.income << endl;
        cout << "Rent: " << record.rent << endl;
        cout << "Food: " << record.food << endl;
        cout << "Utilities: " << record.utilities << endl;
        cout << "Miscellaneous: " << record.miscell << endl;
        cout << "Net: " << record.net << endl;
        income_file_in.close();
    } else {
        cout << "Error opening file" << endl;
    }

    return 0;
}
