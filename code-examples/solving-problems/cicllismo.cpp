#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    for(int x = a - b; x <= a; x++)
    {
        if(a % x == 0)
        {
            cout << x;
            return 0;
        }
    }
}