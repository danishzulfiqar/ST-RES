#include <bits/stdc++.h>
using namespace std;

void passbyvalue(int a,int b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;

    cout<<"Pass by value prints in the function"<<endl;
    cout<<a<<" "<<b<<endl;

}void passbyref(int &a,int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}

int main()
{
    int num1,num2;
    cin>>num1>>num2;

    passbyvalue(num1,num2); //original values dont change

    passbyref(num1,num2);

    cout<<"\nPass by Reference Changes Original Values"<<endl;
    cout<<num1<<" "<<num2<<endl;

    return 0;

}// Author: Danish Zulfiqar
