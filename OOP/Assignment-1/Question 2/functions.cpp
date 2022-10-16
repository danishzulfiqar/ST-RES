#include "functions.h"
#include <iostream>
using namespace std;

int n;
int arr[100] = {0};

void accept()
{
    int num;
    cout << "Enter number of elements you want to insert ";
    cin >> num;
    n = num;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " :";
        cin >> arr[i];
    }
}

void display()
{
    cout<<"The elemnts of the array are:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void insertion()
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }

    cout << "The sorted elements are" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
