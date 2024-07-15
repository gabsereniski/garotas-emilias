#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(1)
    {
        cin >> n;
        if(n == 0) break;

        string comandos;
        cin >> comandos;

        string direcoes = "NLSO";
        int atual = 0;

        for(int i = 0; i < n; i++)
        {
            if(comandos[i] == 'D')
            {
                atual = (atual + 1) % 4;
            }
            else
            {
                atual = (atual - 1) % 4;
                if(atual < 0) atual = 3;
            }
        }

        cout << direcoes[atual] << endl;
    }
}