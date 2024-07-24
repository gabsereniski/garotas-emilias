#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, p, f;
    cin >> c >> p >> f;

    if(c * f <= p) cout << "S\n";
    else           cout << "N\n";
}