#include <bits/stdc++.h>
using namespace std;

class Areas
{
public:
    
    void Area(double radius)
    {
        cout<<fixed<<setprecision(2)<<"Area of circle "<<3.14*radius<<endl;
    }

    void Area(int b,int h)
    {
        cout<<1/2*(b*h)<<"Area of triangle "<<endl;
    }
    void Area(double w,double h)
    {
        cout<<fixed<<setprecision(2)<<"Area of rectangle "<<w*h<<endl;

    }
    void Area(int a)
    {
        cout<<"Area of Square "<<pow(a,2)<<endl;
    }

};

int main()
{
    Areas a1;
    
    a1.Area(1.3);
    a1.Area(2,3);
    a1.Area(2.4,3.8);
    a1.Area(6);
    
    return 0;
}