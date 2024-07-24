#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while ((cin >> n) && n)
    {
        int m = 1;

        while (true)
        {
            int next = 0; // posicao do proximo a ser desligado

            // lista de cidades ainda ligadas
            vector<int> cities;

            for (int i = 0; i < n; i++)
                cities.push_back(i + 1);

            // cidade 1 eh a primeira a ser desligada
            cities.erase(cities.begin()); // begin retorna um ponteiro p a primeira posicao

            // enquanto houver cidades ligadas
            while (cities.size() > 0)
            {
                // calcula o proximo circularmente, de acordo com o tamanho da lista de cidades
                next = (next + (m - 1)) % cities.size();

                // se o proximo nao for 13, retira da lista
                if (cities[next] != 13) cities.erase(cities.begin() + next);
                // senao, quebra o loop
                else break;
            }

            // se so sobrou uma cidade, eh a 13, entao termina
            if (cities.size() == 1) break;
            // senao, repete com o proximo m
            m++;
        }

        // printa o m
        cout << m << endl;
    }
}