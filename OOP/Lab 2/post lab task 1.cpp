#include <bits/stdc++.h>
using namespace std;

int created=0,destroyed=0;

class Counter{

    public:

    Counter()
    {
        created++;
    }

    ~Counter()
    {
        destroyed++;
    }

    void data(){
        cout<<"Objects created are "<<created<<" and destroyed are "<<destroyed<<endl;
    }
    
};

int main()
{

    Counter *a= new Counter();
    Counter *b= new Counter();

    cout<<"Objects created are "<<created<<" and destroyed are "<<destroyed<<endl;

    system("pause");

    delete a;

    cout<<"Objects created are "<<created<<" and destroyed are "<<destroyed<<endl;
     
    return 0;

} // Author : Danish Zulfiqar