#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hrs, min, sec;

public:
    void data(int hours, int minutes, int seconds)
    {
        hrs = hours;
        min = minutes;
        sec = seconds;
    }

    void military_hours()
    {
        cout << hrs << ":" << min << ":" << sec << endl;
    }

    void twelve_hours()
    {
        if(hrs==0)
        {
            cout<<12<< ":" << min << ":" << sec << endl;
        }
        
        
        else if(hrs>12)
        {
            int new_hrs=hrs-12;
            cout << new_hrs << ":" << min << ":" << sec << endl;
        }

        else{
            cout << hrs << ":" << min << ":" << sec << endl;
        }
    }
};

int main()
{

    Time a;

    int hrs,min,sec;
    cin>>hrs>>min>>sec;

    a.data(hrs, min, sec);

    cout<<"24 Hours Time:"<<endl;
    a.military_hours();

    cout<<"12 Hours Time:"<<endl;
    a.twelve_hours();

    return 0;

} // Author : Danish Zulfiqar