#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    int n;
    cin >> n;

    ll total = 0;

    int carneiros[n];

    for(int i = 0; i < n; i++)
    {
        cin >> carneiros[i];
        total += carneiros[i];
    }

    ll roubados = 0;
    int cur = 0, next;
    vector<bool> atacada(n, false);

    while(true)
    {
        if((carneiros[cur] % 2) == 1) next = cur + 1;
        else                          next = cur - 1;

        if(carneiros[cur] > 0)
        {
            carneiros[cur]--;
            roubados++;
            atacada[cur] = true;

            if(roubados == total) break;
        }
        cur = next;
        if(next < 0 || next >= n) break;
    }

    int atacadas = 0;

    for(int i = 0; i < n; i++)
        if(atacada[i]) atacadas++;

    cout << atacadas << " " << total - roubados << endl;
}