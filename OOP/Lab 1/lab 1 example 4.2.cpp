#include <iostream>

using namespace std;

int addition(int numA, int numB)
{
    int numC;
    numC = numA + numB;
    return (numC);
}

int main()
{
    int sum;
    sum = addition(5, 3);
    cout << "Answer is " << sum;
}