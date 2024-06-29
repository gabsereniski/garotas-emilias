#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s(10, 'a');
    cout << s << endl;

    for(int i = 0; i < s.size(); i++)
        if(i % 2) s[i] = 'b';
    
    cout << s << endl;

    string b = "aba";
    string c = b + 'c' + b;

    cout << c << '\n';

    string palavra;
    string frase;

    cout << "digite uma palavra: ";
    cin >> palavra;
    cin.ignore(); // precisamos disso para que o getline
                  // ignore a quebra de linha digitada depois da palavra
    cout << "digite uma frase (ou uma palavra mesmo): ";
    getline(cin, frase, '\n');

    cout << palavra << endl;
    cout << frase << endl;

    if(palavra == frase) cout << "a palavra e a frase são iguais.\n";
    else                 cout << "a palavra e a frase são diferentes.\n";

    if(palavra < frase) cout << "a palavra vem antes da frase, lexicamente.\n";
    if(palavra > frase) cout << "a palavra vem depois da frase, lexicamente.\n";
}