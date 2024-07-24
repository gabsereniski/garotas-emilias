#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int resp;
    int acertos = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> resp;
        if(resp == t)
            acertos++;
    }

    cout << acertos << endl;
}