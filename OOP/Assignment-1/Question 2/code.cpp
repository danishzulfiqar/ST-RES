#include <bits/stdc++.h>
#include "functions.cpp"
using namespace std;

int main()
{
    int ext = 0;

    while (!ext)
    {

        cout << "MENU" << endl;
        cout << "1. Accept elements of array\n2. Display elements of array\n3. Sort the array using insertion sort method\n4. Exit" << endl;

        int choice, n;
        cout << "Enter your choice 1-4 : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            accept();
            break;

        case 2:
            display();
            break;

        case 3:
            insertion();
            break;

        case 4:
            ext=1;
            break;

        default:
            cout << "Undefigned Option!" << endl;
            break;
        }
    }

    return 0;
    
} // Author : Danish Zulfiqar
