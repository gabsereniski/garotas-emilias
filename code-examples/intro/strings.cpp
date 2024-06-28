#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s(10, 'a');
    cout << s << endl;

    for(int i = 0; i < s.size(); i++)
        if(i % 2) s[i] = 'b';
    
    cout << s << endl;

    string palavra;
    string frase;

    cout << "digite uma palavra: ";
    cin >> palavra;
    cin.ignore(); // precisamos disso para que o getline
                  // ignore a quebra de linha digitada depois da palavra
    cout << "digite uma frase: ";
    getline(cin, frase, '\n');

    cout << palavra << endl;
    cout << frase << endl;
}