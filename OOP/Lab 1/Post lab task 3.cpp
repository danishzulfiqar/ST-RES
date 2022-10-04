#include <iostream>
#include <string>
using namespace std;

void reverse_string(int *n, char *ptr)
{
    cout << "The reversed string is" << endl;
    for (int i = *n; i >= 0; i--)
    {
        cout << *(ptr + i);
    }
}

int main()
{
    string str;
    cout << "Enter a string" << endl;
    cin >> str;

    int n = str.size()-1;

    reverse_string(&n, &str[0]);

    return 0;

}// Author: Danish Zulfiqar
