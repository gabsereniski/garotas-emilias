#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;

        int h[t];

        for(int i = 0; i < t; i++)
            cin >> h[i];
        
        string mov;
        cin >> mov;

        int hits = 0;

        for(int i = 0; i < t; i++)
        {
            if((mov[i] == 'S' && h[i] <= 2) || 
               (mov[i] == 'J' && h[i] > 2))
                hits++;
        }
        
        cout << hits << endl;
    }
}