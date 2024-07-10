#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m[n+1][n+1];

    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < n+1; j++)
            cin >> m[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(m[i][j] +   m[i][j+1] +
               m[i+1][j] + m[i+1][j+1] < 2) cout << 'U';
            else cout << 'S';
        }
        cout << endl;
    }
}