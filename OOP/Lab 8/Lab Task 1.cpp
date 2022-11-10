#include <bits/stdc++.h>
using namespace std;

class base
{
protected:
    int m1, m2;

public:
    void get()
    {
        cout << "Enter the first integer :";
        cin >> m1;
        cout << "Enter the second integer :";
        cin >> m2;
    }
};

class derive1 : public base
{
protected:
    int sm;

public:
    void getsm()
    {
        cout << "Enter the third integer :";
        cin >> sm;
    }
};

class derive2 : public derive1
{
    int tot;

public:
    void display()
    {
        tot = (m1 + m2 + sm);
        cout << "\nTotal:" <<tot<<endl;
    }
};

int main()
{
    derive2 obj;
    obj.get();
    obj.getsm();
    obj.display();   
    return 0;
}
