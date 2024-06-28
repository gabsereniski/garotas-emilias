#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 0; i < 10; i++)
    {
        if(i % 2) continue; // se o resto de i/2 é diferente de 0
        cout << i << " ";
    }
    cout << "\n";
}