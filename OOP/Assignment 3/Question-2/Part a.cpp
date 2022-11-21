#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hrs, mins, secs;

public:
    Time() : hrs(0), mins(0), secs(0)
    {
    }
    Time(int h, int m, int s) : hrs(h), mins(m), secs(s)
    {
    }
    void display()
    {
        cout << "Added Time is: " << hrs << ":" << mins << ":" << secs << endl;
    }

    Time operator ++()
    {

        ++secs;

        while (secs > 59)

        {
            secs -= 60;
            mins++;
        }

        while (mins > 59)

        {
            mins -= 60;
            hrs++;
        }

        return Time(hrs, mins, secs);
    }

    Time operator ++ (int)

    {

        secs++;

        while (secs > 59)

        {
            secs -= 60;
            mins++;
        }

        while (mins > 59)

        {
            mins -= 60;
            hrs++;
        }

        return Time(hrs, mins, secs);
    }

    Time operator+(Time t2)
    {
        int hr = hrs + t2.hrs;
        int m = mins + t2.mins;
        int s = secs + t2.secs;
        while (s > 59)
        {
            s -= 60;
            m++;
        }
        while (m > 59)
        {
            m -= 60;
            hr++;
        }

        Time temp(hr, m, s);

        return temp;
    }
};

int main()
{

    Time t1(2, 45, 34), t2(2, 44, 54);
    Time t3 = t1 + t2;
    t3.display();
    cout << endl;
    t3++;
    Time t4 = t3++;
    t4.display();
    return 0;
}
