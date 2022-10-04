#include <iostream>
using namespace std;

void add10(int *a, int *b)
{
    *a += 10;
    *b += 10;
}

int main()
{
    int a,b;

    cout<<"Enter two numbers"<<endl;

    cin>>a>>b;

    add10(&a,&b);

    cout<<"\nThe new values are"<<endl;

    cout<<a <<" "<<b<<endl;

    return 0;

}// Author: Danish Zulfiqar
