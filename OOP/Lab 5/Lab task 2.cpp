#include <iostream>
using namespace std;
class Counter
{
private:
    int count;

public:
    Counter()
    {
        count = 0;
    }
    Counter(int i)
    {
        count = i;
        cout << "Counter is initialized with count of " << count << endl;
    }

    void inc_count()
    {
        ++count;
    }
    int get_count()
    {
        return count;
    }
};
int main()
{
    Counter c1(3), c2(4);
    c1.get_count();
    cout << "Counter of first object is " << c1.get_count() << endl;
    c2.get_count();
    cout << "Counter of second object is " << c2.get_count() << endl;
    return 0;
}