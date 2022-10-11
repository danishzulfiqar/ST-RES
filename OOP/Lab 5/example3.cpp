#include <iostream>
using namespace std;
class Time
{
private:
    int hour;   // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
    const int id;

public:
    Time(int h, int m, int s, int i) : id(i)
    {
        // id = i;
        setTime(h, m, s);
    }
    // set functions
    void setTime(int h, int m, int s)
    { // set time
        setHour(h);
        setMinute(m);
        setSecond(s);
    }
    void setHour(int h)
    { // set hour
        hour = (h >= 0 && h < 24) ? h : 0;
    }
    void setMinute(int m)
    { // set minute
        minute = (m >= 0 && m < 60) ? m : 0;
    }
    void setSecond(int s)
    { // set second
        second = (s >= 0 && s < 60) ? s : 0;
    }
    // get functions (normally declared const)
    int getHour() const
    { 
        // return hour
        return hour;
    }
    int getMinute() const
    { // return minute
        // minute = 10; // Error cannot assign value to data member in const function
        return minute;
    }
    int getSecond() const
    { // return seco
        return second;
    }
    // print functions (normally declared const)
    void printTime() const
    {
        cout << hour << " : " << minute << " : " << second << endl;
    }
};
int main()
{
    Time wakeUp(5, 30, 30, 1);    // non-constant object
    const Time noon(12, 0, 0, 2); // constant object
    // OBJECT MEMBER FUNCTION
    wakeUp.setHour(4); // non-const non-const
    // noon.setHour( 14 ); // const non-const --> Error
    wakeUp.printTime(); // non-const const
    noon.printTime();   // const const
    
    return 0;
}
