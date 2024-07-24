#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int main()
{
    vector<vector<bool>> mar(MAXN, vector<bool>(MAXN, false));

    int n;
    cin >> n;

    while(n--)
    {
        int xi, xf, yi, yf;

        cin >> xi >> xf >> yi >> yf;

        for(int i = yi; i < yf; i++)
            for(int j = xi; j < xf; j++)
                mar[i][j] = true;
    }

    int apr = 0;

    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            apr += mar[i][j];
    
    cout << apr << endl;
}