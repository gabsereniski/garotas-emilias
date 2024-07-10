#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char tab[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tab[i][j] == '.')
            {
                if (i - 1 >= 0 && tab[i - 1][j] == 'o')
                    tab[i][j] = 'o';
                if (j - 1 >= 0 && i + 1 < n &&
                    tab[i][j - 1] == 'o' && tab[i + 1][j - 1] == '#')
                    tab[i][j] = 'o';
                if (j + 1 < m && i + 1 < n &&
                    tab[i][j + 1] == 'o' && tab[i + 1][j + 1] == '#')
                    tab[i][j] = 'o';
            }
        }

        for (int j = m - 1; j >= 0; j--)
        {
            if (tab[i][j] == '.')
            {
                if (i - 1 >= 0 && tab[i - 1][j] == 'o')
                    tab[i][j] = 'o';
                if (j - 1 >= 0 && i + 1 < n &&
                    tab[i][j - 1] == 'o' && tab[i + 1][j - 1] == '#')
                    tab[i][j] = 'o';
                if (j + 1 < m && i + 1 < n &&
                    tab[i][j + 1] == 'o' && tab[i + 1][j + 1] == '#')
                    tab[i][j] = 'o';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << tab[i][j];
        cout << endl;
    }
}