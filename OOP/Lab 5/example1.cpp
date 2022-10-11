#include <iostream>
using namespace std;
/* function prototype */
void display(int);
void display(int, int);
void display(double, double);
/* main function */
int main()
{
    display(100);            // call to display (int);
    display(50, 60);         // call to display(int, int);
    display(200.45, 205.75); // call to display(float, float);
    
    return 0;
}
void display(int x)
{
    cout << "display with single int argument" << endl;
    cout << "value = " << x << endl;
}
void display(int x, int y)
{
    cout << "display with double int argument" << endl;
    cout << "value 1 = " << x << ", value 2 = " << y << endl;
}
void display(double x, double y)
{
    cout << "display with double float argument" << endl;
    cout << "value 1 = " << x << ", value 2 = " << y << endl;
}