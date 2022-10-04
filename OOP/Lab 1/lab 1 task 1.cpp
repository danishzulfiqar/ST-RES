#include <iostream>
#include <algorithm>
using namespace std;

struct books{
    int id;
    float price;
    int pages;
};

int main()
{
    int n;
    cout<<"Enter the number of books"<<endl;
    cin>>n;

    books arr[n];
    float max_price=0;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter id"<<endl;
        cin>>arr[i].id;

        cout<<"Enter price"<<endl;
        cin>>arr[i].price;

        cout<<"Enter pages"<<endl;
        cin>>arr[i].pages;

        max_price=max(arr[i].price,max_price);
    }

    cout<<"Th max priced book is"<<endl;

    for(int i=0;i<n;i++)
    {
        if(arr[i].price==max_price)
        {
            cout<<"Id: "<<arr[i].id<<endl;
            cout<<"Price: "<<arr[i].price<<endl;
            cout<<"Pages: "<<arr[i].pages<<endl;
        }
    }

    return 0;

} // Author: Danish Zulfiqar
