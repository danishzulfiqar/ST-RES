#include <iostream>

using namespace std;

int main()
{
    int first, second;
    int *ptr;
    ptr = &first;

    *ptr = 10;
    ptr = &second;
    *ptr = 20;

    cout << "First value is " << first << endl;

    cout << "Second value is " << second << endl;
    return 0;
}