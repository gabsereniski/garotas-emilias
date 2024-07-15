#include <bits/stdc++.h>
using namespace std;

int main()
{
    float N;

    cin >> N;

    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};

    int n = N * 100;

    printf("NOTAS:\n");
    for(int i = 0; i < 6; i++)
    {
        int qtd = n / notas[i];
        printf("%d nota(s) de R$ %d.00\n", qtd, notas[i] / 100);
        n %= notas[i];
    }

    printf("MOEDAS:\n");
    for(int i = 0; i < 6; i++)
    {
        int qtd = n / moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, moedas[i] / 100.0);
        n %= moedas[i];
    }
}