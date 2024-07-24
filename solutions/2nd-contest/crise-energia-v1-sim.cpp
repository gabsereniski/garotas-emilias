#include <bits/stdc++.h>
using namespace std;

void print_cities(int n, bool *v, int next, int m, int off, int step)
{
    system("clear");
    printf("m = %d, off = %d, step = %d\n", m, off, step);
    for(int i = 0; i < n; i++)
    {
        if(i == 12)
        {
            if(v[i]) printf("{xxx}");
            else     printf("{%3d}", i+1);
        }

        else
        {
            if(v[i]) printf("[xxx]");
            else     printf("[%3d]", i+1);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        if(i == next) printf("  ^  ");
        else          printf("     ");
    }
    printf("\n");
}

int main()
{
    int n;
    while((cin >> n) && n)
    {
        int m = 1;

        while(true)
        {
            int next = 0; // proximo a ser desligado
            // cidades desligadas ate agr
            int off_num = 0;
            // lista de cidades desligadas
            bool off_cities[n];
            for(int i = 0; i < n; i++)
                off_cities[i] = false;

            int step = 0;
            
            print_cities(n, off_cities, next, m, off_num, step);
            getchar();

            // cidade 0 eh a primeira a ser desligada
            off_cities[next] = true;
            off_num++;

            print_cities(n, off_cities, next, m, off_num, step);
            getchar();

            // enquanto nem todas as cidades estiverem sem energia
            while(off_num < n)
            {
                // quantas cidades validas ja andou
                step = 0;
                // enquanto nao andou m cidades ligadas
                while(step < m)
                {
                    // incrementa 1 de forma circular
                    next = (next + 1) % n;
                    // se a cidade atual ja esta desligada, continua
                    print_cities(n, off_cities, next, m, off_num, step);
                    getchar();
                    if(off_cities[next]) continue;
                    // se nao, considera que andou uma cidade ligada
                    else step++;
                }
                print_cities(n, off_cities, next, m, off_num, step);
                getchar();
                // desliga a cidade dps de m passos
                off_cities[next] = true;

                print_cities(n, off_cities, next, m, off_num, step);
                getchar();

                // incrementa o numero de cidades desligadas
                off_num++;

                // se a cidade atual eh a 12 mas tem outras cidades ligadas ainda, a 12 nao eh a ultima
                // entao, o m atual nao eh valido
                if(next == 12 && off_num < n) 
                {
                    next++; // isso aqui eh gambiarra, next vai pra 13
                    break;
                }
            }

            // se for 12, significa que o m eh valido e termina o laço
            if(next == 12) break;
            // senao, repete com o proximo m
            m++;
        }

        // printa o m 
        cout << m << endl;
    }
}