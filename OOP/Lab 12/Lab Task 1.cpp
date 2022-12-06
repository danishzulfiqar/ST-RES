#include <iostream>
using namespace std;
class Counter
{
private:
    int number;

public:

    Counter():number(0){}
    Counter(int n)
    {
        number = n;
    }
    Counter operator++();
    Counter operator++(int);
    Counter operator--();
    Counter operator--(int);
    void display();
};
Counter Counter::operator++()
{
    return Counter(++number);
}
Counter Counter::operator++(int)
{
    return Counter(number++);
}
Counter Counter::operator--()
{
    return Counter(--number);
}
Counter Counter::operator--(int)
{
    return Counter(number--);
}
void Counter::display()
{
    cout << "number:" << number << endl;
}

int main()
{
    Counter c1, c2(10), c3, c4;
    cout << "Before pre increment for c1:" << endl;
    c1.display();
    ++c1;
    cout << "After pre increment for c1:" << endl;
    c1.display();
    cout << "Before post increment for c1:" << endl;
    c1.display();
    c3 = c1++;
    cout << "After post increment for c1:" << endl;
    c1.display();
    cout << "Value of c3:" << endl;
    c3.display();
    cout << "Before pre decrement for c2:" << endl;
    c2.display();
    --c2;
    cout << "After pre decrement for c2:" << endl;
    c2.display();
    cout << "Before post decrement for c2:" << endl;
    c2.display();
    c4 = c2--;
    cout << "After post decrement for c2:" << endl;
    c2.display();
    cout << "Vaue of c4:" << endl;
    c4.display();
    return 0;
}



