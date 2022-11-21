#include "iostream"
using namespace std;

const int LIMIT = 100;
class safearay

{

private:
    int arr[LIMIT], u_limit, l_limit;

public:
    safearay(int l, int u) : l_limit(l), u_limit(u) {}

    int &operator[](int n)
    {
        l_limit -= (l_limit - 0);
        u_limit -= (u_limit - 100);

        if (n < l_limit || n >= u_limit)

        {
            cout << "\nIndex out of bounds\n";
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    int low, up, j;
    cout << "Enter Lower & Upper Limits of an Array of 100 Elements Respectively: "<<endl;
    cin >> low >> up;
    safearay sa1(low, up);

    for (j = low; j < up; j++)
    {
        sa1[j - low] = (j - low) * 10;
    }

    for (j = low; j < up; j++)
    {
        int temp = sa1[j - low];
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}