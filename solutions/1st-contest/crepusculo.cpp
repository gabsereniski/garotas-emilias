#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mapa[n+1][n+1];

    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < n+1; j++)
            cin >> mapa[i][j];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int atual = mapa[i][j];
            int emb = mapa[i+1][j];
            int lado = mapa[i][j+1];
            int dig = mapa[i+1][j+1];

            if(atual + emb + lado + dig < 2) cout << 'U';
            else cout << 'S';
        }
        
        cout << endl;
    }
}