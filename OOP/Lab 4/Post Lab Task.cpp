#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0)
    {
    }
    Distance(int ft, float in) : feet(ft), inches(in)
    {
    }
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    inline void showdist();
    void add_dist(Distance, Distance);
    void sub_dist(Distance, Distance);
    void mul_dist(Distance, Distance);
};

int main()
{
    Distance dist1, dist3, dist4, dist5;
    Distance dist2(11, 6.25);

    dist1.getdist();
    dist3.add_dist(dist1, dist2);
    dist4.sub_dist(dist1, dist2);
    dist5.mul_dist(dist1, dist2);

    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();
    cout << "\ndist3 = ";
    dist3.showdist();
    cout << "\ndist4 = ";
    dist4.showdist();
    cout << "\ndist5 = ";
    dist5.showdist();
    cout << endl;

    return 0;
}

inline void Distance::showdist()
{
    while (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }

    cout << feet << "\"" << inches << "\'";
}
void Distance::add_dist(Distance d2, Distance d3)
{
    inches = d2.inches + d3.inches;
    feet = 0;
    while (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet + d3.feet;
}

void Distance::sub_dist(Distance d2, Distance d3)
{
    inches = d2.inches - d3.inches;
    feet = 0;
    while (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet - d3.feet;
    feet = abs(feet);
    inches = abs(inches);
}

void Distance::mul_dist(Distance d2, Distance d3)
{
    inches = d2.inches * d3.inches;
    feet = feet/12;
    while (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet * d3.feet;
}
