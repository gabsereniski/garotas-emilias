#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    int soma = 0;
    cout << "Digite quantos numeros diferentes de 0 que quiser.\n";
    cout << "Digitar 0 encerra o programa.\n";
    while(true)
    {
        cin >> x;
        if(!x) // se op for igual a 0
            break;
        else
            soma += x;
    }
    cout  << "A soma dos numeros eh " << soma << "\n";
}