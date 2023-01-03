#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_RECORDS = 10;

struct Record
{
    string name;
    float income;
    float rent;
    float food;
    float utilities;
    float miscell;
    float net;
};

int main()
{
    Record records[MAX_RECORDS];
    int num_records = 0;
    char more_input = 'y';

    while (more_input == 'y')
    {
        cout << "Enter the following information" << endl;
        cout << "Person's Name: ";
        getline(cin, records[num_records].name);
        cout << "Income: ";
        cin >> records[num_records].income;
        cout << "Rent: ";
        cin >> records[num_records].rent;
        cout << "Food: ";
        cin >> records[num_records].food;
        cout << "Utilities: ";
        cin >> records[num_records].utilities;
        cout << "Miscellaneous: ";
        cin >> records[num_records].miscell;

        records[num_records].net = records[num_records].income - (records[num_records].rent + records[num_records].food + records[num_records].utilities + records[num_records].miscell);

        num_records++;

        cout << "Enter a Y if you would like to input more data" << endl;
        cin >> more_input;
        cin.ignore();
    }

    cout << "That's all the information" << endl;

    ofstream income_file("income.dat", ios::binary);
    if (income_file.is_open())
    {
        for (int i = 0; i < num_records; i++)
        {
            income_file.write((char *)&records[i], sizeof(records[i]));
        }
        income_file.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    ifstream income_file_in("income.dat", ios::binary);
    if (income_file_in.is_open())
    {
        for (int i = 0; i < num_records; i++)
        {
            income_file_in.read((char *)&records[i], sizeof(records[i]));

            cout << "Name: " << records[i].name << endl;
            cout << "Income: " << records[i].income << endl;
            cout << "Rent: " << records[i].rent << endl;
            cout << "Food: " << records[i].food << endl;
            cout << "Utilities: " << records[i].utilities << endl;
            cout << "Miscellaneous: " << endl;
        }
    }
    return 0;
}