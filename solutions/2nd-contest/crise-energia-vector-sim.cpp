#include <bits/stdc++.h>
using namespace std;

void print_cities(vector<int> v, int next, int m)
{
    system("clear");
    printf("m = %d, next = %d\n", m, next);
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 13) printf("{%3d}", v[i]);
        else           printf("[%3d]", v[i]);
        
    }
    printf("\n");
    for(int i = 0; i < v.size(); i++)
    {
        if(i == next) printf("  ^  ");
        else          printf("     ");
    }
    printf("\n");
    getchar();
}

int main()
{
    int n;
    while((cin >> n) && n)
    {
        getchar();
        int m = 1;

        while(true)
        {
            int next = 0; // proximo a ser desligado

            // lista de cidades ainda ligadas
            vector<int> cities;

            for(int i = 0; i < n; i++)
                cities.push_back(i+1);

            
            print_cities(cities, next, m);
            

            // cidade 0 eh a primeira a ser desligada
            cities.erase(cities.begin());

            print_cities(cities, next, m);
            

            // enquanto nem todas as cidades estiverem sem energia
            while(cities.size() > 0)
            {   
                // incrementa m de forma circular
                next = (next + (m - 1)) % cities.size();
                // se a cidade atual ja esta desligada, continua
                print_cities(cities, next, m);
                
    
                if(cities[next] != 13) cities.erase(cities.begin() + next);
                else break;
                // desliga a cidade dps de m passos
                

                print_cities(cities, next, m);
            }

            // se for 12, significa que o m eh valido e termina o laço
            if(cities.size() == 1) break;
            // senao, repete com o proximo m
            m++;
        }

        // printa o m 
        cout << m << endl;
    }
}