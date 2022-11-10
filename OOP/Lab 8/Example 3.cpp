#include <iostream>
using namespace std;
class base1
{
protected:
    int number1;

public:
    void showA()
    {
        cout << "enter a value for first number:" << endl;
        cin >> number1;
    }
};
class base2 : public base1
{
protected:
    int number2;

public:
    void showB()
    {
        cout << "enter value for second number:";
        cin >> number2;
    }
};
class derive : public base2
{
public:
    void showC()
    {
        showA(); // accessing base1's function
        showB(); // accessing base2's function
        cout << "number1*number2 =" << number1 * number2;
    }
};
int main()
{
    derive ob1;
    ob1.showC();
    cout << endl;
    system("pause");
}
