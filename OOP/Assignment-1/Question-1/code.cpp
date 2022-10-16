#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n; //  Declaring an unsigned int

    cout << "Enter the number" << endl;
    cin >> n;

    int reverse = 0;

    while (n > 0) // Using controlled structure with reverse number algorithm to reverse out input
    {
        int last_digit = n % 10;
        reverse = reverse * 10 + last_digit;

        n /= 10;
    }

    cout << "The reversed number is " << reverse << endl; // Output

    return 0;
}
/* The only differnce between C and C++ program for reversing was that in C language I was using statements(functions)
while in C++ I am actually passing Objects and obtaining my output as a Object */

// Author : Danish Zulfiqar