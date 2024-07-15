#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char c[n+2][m+2];

    memset(c, '@', sizeof(c));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '.')
            {
                if((c[i-1][j] == 'o')
                || (c[i][j-1] == 'o' && c[i+1][j-1] == '#')
                || (c[i][j+1] == 'o' && c[i+1][j+1] == '#'))
                    c[i][j] = 'o';
            }
        }

        for(int j = m-1; j >= 0; j--)
        {
            if(c[i][j] == '.')
            {
                if((c[i-1][j] == 'o')
                || (c[i][j-1] == 'o' && c[i+1][j-1] == '#')
                || (c[i][j+1] == 'o' && c[i+1][j+1] == '#'))
                    c[i][j] = 'o';
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << c[i][j];
        cout << endl;
    }
}