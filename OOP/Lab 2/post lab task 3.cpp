#include <bits/stdc++.h>
using namespace std;

class marks
{

private:
    float mrk1, mrk2, mrk3;

public:
    void set_marks(float m1, float m2, float m3)
    {
        mrk1 = m1;
        mrk2 = m2;
        mrk3 = m3;
    }

    void sum()
    {
        cout << fixed << setprecision(2) << "The sum is " << mrk1 + mrk2 + mrk3 << endl;
    }

    void avg()
    {
        cout << fixed << setprecision(2) << "The averege is " << (mrk1 + mrk2 + mrk3) / 3 << endl;
    }
};

int main()
{

    marks st1;

    float m1, m2, m3;
    cin >> m1 >> m2 >> m3;

    st1.set_marks(m1, m2, m3);

    st1.sum();

    st1.avg();

    return 0;

} // Author : Danish Zulfiqar