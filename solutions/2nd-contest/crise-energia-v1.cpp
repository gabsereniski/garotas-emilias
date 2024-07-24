#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while((cin >> n) && n != 0)
    {
        int m = 1;

        while(true)
        {
            int next = 0; // proximo a ser desligado

            // lista de cidades desligadas
            bool off_cities[n];
            for(int i = 0; i < n; i++)
                off_cities[i] = false;

            // cidade 0 eh a primeira a ser desligada
            off_cities[next] = true;
            
            // uma cidade desligada ate agr
            int off_num = 1;

            // enquanto nem todas as cidades estiverem sem energia
            while(off_num < n)
            {
                // quantas cidades validas ja andou
                int step = 0;
                // enquanto nao andou m cidades ligadas
                while(step < m)
                {
                    // incrementa 1 de forma circular
                    next = (next + 1) % n;
                    // se a cidade atual ja esta desligada, continua
                    if(off_cities[next]) continue;
                    // se nao, considera que andou uma cidade ligada
                    else step++;
                }
                
                // desliga a cidade dps de m passos
                off_cities[next] = true;

                // incrementa o numero de cidades desligadas
                off_num++;

                // se a cidade atual eh a 12 mas tem outras cidades ligadas ainda, a 12 nao eh a ultima
                // entao, o m atual nao eh valido
                if(next == 12 && off_num < n) 
                {
                    next++; // isso aqui eh gambiarra, next vai pra 13
                    break; // quebra o loop, ou seja, pula pra linha 58
                }
            }

            // se for 12, significa que o m eh valido e termina o laço
            if(next == 12) break; // vai pra linha 64
            // senao, volta pro inicio com o proximo m
            m++;
        }

        // printa o m 
        cout << m << endl;
    }
}