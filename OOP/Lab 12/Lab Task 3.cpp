#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance()
    {
        feet=0;
        inches=0;
    }
    Distance(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    int getFeet()
    {
        return feet;
    }
    int getInches()
    {
        return inches;
    }
    void operator%(int x)
    {
        inches += (feet*12);
        inches %= x;

        feet = 0;

        while(inches >=  12)
        {
            feet+=1;

            inches -= 12;
        }
    }
};
int main()
{
    Distance Dist_1(10, 5);
    cout << Dist_1.getFeet() << " feet " << Dist_1.getInches() << " inches";
    Dist_1 % 2;
    cout << endl;
    cout << Dist_1.getFeet() << " feet " << Dist_1.getInches() << " inches";
    return 0;
}
