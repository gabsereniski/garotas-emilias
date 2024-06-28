#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v[] = {1, 2, 3, 4, 5}; // sim, dá pra inicializar vetores assim
    for(int i = 4; i >= 0; i--) // percorre vetor de trás pra frente
        cout << v[i] << " ";
    cout << "\n";

    int m[3][3] = {{1, 2, 3}, // e dá pra inicializar matrizes assim
                   {4, 5, 6}, // mas é preciso especificar o tamanho
                   {7, 8, 9}};

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("[%d]", m[i][j]);
        printf("\n");
    }
}