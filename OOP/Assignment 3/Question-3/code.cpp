#include <bits/stdc++.h>
using namespace std;

class sterling{
    private:
    long pounds;
    int shillings,pence;

    public:
    sterling(){}
    sterling(double n){}
    sterling(long p,int s,int pen){}
    void get_sterling();
    void put_sterling();

    sterling operator+(sterling ob1)
    {
        double n= pounds + ob1.pounds;

        return sterling(n);
    }

    sterling operator-(sterling ob1)
    {
        double n = pounds - ob1.pounds;

        return sterling(n);
    }

    sterling operator*(sterling ob1)
    {
        double n= pounds * ob1.pounds;

        return sterling(n);
    }

    sterling operator/(sterling ob1)
    {
        double n= pounds / ob1.pounds;

        return sterling(n);
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}