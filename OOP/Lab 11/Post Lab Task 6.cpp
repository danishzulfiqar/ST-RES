#include <iostream>
#include <fstream>
#include <string>

const int MAX_RECORDS = 20;

struct Record
{
    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string city;
    std::string state;
    long zipCode;
};

int main()
{
    Record records[MAX_RECORDS];

    char input;
    int recordIndex = 0;
    do
    {
        std::cout << "Enter the following information" << std::endl;
        std::cout << "Person's First Name: ";
        std::cin >> records[recordIndex].firstName;
        std::cout << "Person's Last Name: ";
        std::cin >> records[recordIndex].lastName;
        std::cout << "Street: ";
        std::cin >> records[recordIndex].streetAddress;
        std::cout << "City: ";
        std::cin >> records[recordIndex].city;
        std::cout << "State: ";
        std::cin >> records[recordIndex].state;
        std::cout << "Zip: ";
        std::cin >> records[recordIndex].zipCode;
        recordIndex++;
        std::cout << "Enter a Y if you would like to input more data: ";
        std::cin >> input;
    } while (input == 'Y' && recordIndex < MAX_RECORDS);

    std::ofstream binaryFile("records.bin", std::ios::binary);
    binaryFile.write((char *)records, sizeof(Record) * recordIndex);
    binaryFile.close();

    std::ifstream binaryFileIn("records.bin", std::ios::binary);
    binaryFileIn.read((char *)records, sizeof(Record) * recordIndex);
    binaryFileIn.close();

    std::ofstream textFile("records.txt");
    textFile << "First Name"
             << " "
             << "Last Name"
             << " "
             << "Street"
             << " "
             << "City"
             << " "
             << "State"
             << " "
             << "Zip Code" << std::endl;
    for (int i = 0; i < recordIndex; i++)
    {
        textFile.width(15);
        textFile << std::left << records[i].firstName << " ";
        textFile.width(15);
        textFile << std::left << records[i].lastName << " ";
        textFile.width(30);
        textFile << std::left << records[i].streetAddress << " ";
        textFile.width(20);
        textFile << std::left << records[i].city << " ";
        textFile.width(5);
        textFile << std::left << records[i].state << " ";
        textFile.width(10);
        textFile << std::left << records[i].zipCode << std::endl;
    }
    textFile.close();

    return 0;
}