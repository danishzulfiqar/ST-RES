#include <bits/stdc++.h>
using namespace std;

class subtractor
{
private:
    int a, b, c;
    void getdata(int n1, int n2);
    void subtract();

public:
    void call();
};

void subtractor::getdata(int n1, int n2)
{
    a = n1;
    b = n2;
    c = n1 - n2;
}

void subtractor::subtract()
{
    c = a - b;
    cout << c;
}

void subtractor::call()
{
    int num1, num2;
    cout << "Enter two numbers" << endl;
    cin >> num1 >> num2;
    getdata(num1, num2);
    subtract();
}

int main()
{
    subtractor obj1;
    obj1.call();
    return 0;
}