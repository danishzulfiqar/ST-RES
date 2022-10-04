#include <iostream>
#include <algorithm>
using namespace std;

void sorting(int n,int arr[])
{
    sort(arr,arr+n);

    cout<<"The sorted array is"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    cout << "Enter the number of elements of an array" << endl;
    int n;
    cin >> n;

    int arr[n];

    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sorting(n,arr);

    return 0;

}// Author: Danish Zulfiqar