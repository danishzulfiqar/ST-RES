#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int S, M;

public:
    Distance() : S(0), M(0) {}

    void const add_distance(const int id)
    {
        S = id + M;
    }

    void const get_distance()
    {
        cout << "Distance 1(constant)" << endl;
        cout << "Distance 2: ";
        cin >> M;
        cout << endl;
    }
    void const disp()
    {
        cout << "The sum of two distances is: " << S << endl;
    }
};

int main()
{
    Distance  A1;
    Distance const A2;
    A1.get_distance();
    A1.add_distance(12);
    A1.disp();
    cout << "\n\n";
    A2.get_distance();
    A2.add_distance(10);
    A2.disp();
    return 0;
}
