#include <bits/stdc++.h>
using namespace std;

int i = 0; // essa é uma variável global
           // qualquer função pode alterá-la (isso pode facilitar alguamas coisas)

// recebe os valores de a e b
int soma_1(int a, double b)
{
    // parâmetros agem como variáveis locais
    a = a + b; // altera o valor de a localmente
    int c = a + b; // declara variável local
                   // o valor de b será truncado 
    i += 1; // incrementa i em 1
    return c;
}

// recebe os mesmos valores, mas a é passado por referência
int soma_2(int &a, double b)
{
    a = a + b; // altera a
    int c = a + b;
    i += 1;
    return c; 
}

int main()
{
    int a = 10;
    double b = 20.123456;

    printf("a = %d, b = %.2lf, i = %d\n\n", a, b, i);
    printf("soma_1(a, b) = %d\n", soma_1(a, b));
    printf("a = %d, b = %.2lf, i = %d\n\n", a, b, i);
    printf("soma_2(a, b) = %d\n", soma_2(a, b));
    printf("a = %d, b = %.2lf, i = %d\n", a, b, i);
}