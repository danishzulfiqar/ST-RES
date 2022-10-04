#include <iostream>
using namespace std;

void sorting(int &n, int *ptr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

int main()
{
    cout << "Enter the number of Elements of array" << endl;
    int n;
    cin >> n;

    int arr[n];

    cout << "Enter the values of array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sorting(n, &arr[0]);

    cout << "\nThe sorted array is" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;

}// Author: Danish Zulfiqar