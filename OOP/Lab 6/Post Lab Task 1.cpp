#include <bits/stdc++.h>
using namespace std;

class Counter
{

private:
    static int created, destroyed;

public:
    Counter()
    {
        created++;
    }

    ~Counter()
    {
        destroyed++;
    }

    static void data();
};

int Counter::created = 0;
int Counter::destroyed = 0;

void Counter ::data()
{
    cout << "Objects created are " << created << " and destroyed are " << destroyed << endl;
}

int main()
{

    Counter *a = new Counter();
    Counter *b = new Counter();

    Counter::data();

    delete a;

    Counter::data();

    return 0;
}