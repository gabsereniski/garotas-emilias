#include <bits/stdc++.h>
using namespace std;

int main()
{
    if(1)  cout << "if(1) sempre será executado\n";
    if(0)  cout << "if(0) nunca será executado\n";
    if(!0) cout << "if(!0) sempre será executado\n";
    if(!1) cout << "if(!1) nunca será executado\n";

    int x;
    cout << "Digite um número x: ";
    cin >> x;
    
    if(x == 0) cout << "x é 0\n";
    else       cout << "x não é 0\n";

    int y;
    cout << "Digite um número y: ";
    cin >> y;

    if (y > 0)       cout << "x é positivo\n";
    else if(y < 0)   cout << "x é negativo\n";
    else             cout << "x é 0\n";
}