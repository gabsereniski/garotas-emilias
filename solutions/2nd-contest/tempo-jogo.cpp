#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hi, mi, hf, mf;
    cin >> hi >> mi >> hf >> mf;

    int total_min = ((hf * 60) + mf) - ((hi * 60) + mi);
    if(total_min <= 0) total_min += 24 * 60;

    int h = total_min / 60;
    int min = total_min % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, min);
}