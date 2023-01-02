#include <bits/stdc++.h>
using namespace std;
const int maxi = 10;

int main()
{
    int a0[maxi], a1[maxi], a2[maxi], a3[maxi], a4[maxi], a5[maxi], a6[maxi], a7[maxi], a8[maxi], a9[maxi];

    int *pa[maxi] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

    for (int i = 0; i < maxi * maxi; ++i)
    {
        pa[i / maxi][i % maxi] = i * 10;
    }

    for (int i = 0; i < maxi * maxi; ++i)
    {
        cout << pa[i / maxi][i % maxi] << " ";
    }

    cout << endl;

    return 0;
}