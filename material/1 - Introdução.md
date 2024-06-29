# Primeiros Passos

Pra resolver problemas de programação competitiva, vamos usar C++. Os compiladores de C++ geram programas super rápidos, e a linguagem tem uma biblioteca padrão que pode facilitar muito nossa vida. Você pode ver como configurar sua máquina para programar em C++ [aqui](/material/2%20-%20Configurando%20seu%20ambiente%20de%20desenvolvimento.md).

## Sumário

- [Primeiros Passos](#primeiros-passos)
  - [Sumário](#sumário)
  - [1 - Conceitos básicos do C++](#1---conceitos-básicos-do-c)
    - [1.1 - Tipos primitivos](#11---tipos-primitivos)
    - [1.2 - Entrada e Saída](#12---entrada-e-saída)
  - [2 - Funções](#2---funções)
    - [3 - Controle de fluxo](#3---controle-de-fluxo)
      - [3.1 - `if/else`](#31---ifelse)
      - [3.2 - Laços de repetição](#32---laços-de-repetição)
      - [3.3 - Escopo](#33---escopo)
  - [4 - Strings](#4---strings)
  - [5 - Conclusão](#5---conclusão)
    - [5.1 - Exercícios recomendados](#51---exercícios-recomendados)

## 1 - Conceitos básicos do C++

### 1.1 - Tipos primitivos

O C++ é uma linguagem tipada, então quando você declara uma variável, ela terá aquele tipo até o fim do programa, e tentar fazer operações entre variáveis de tipos diferentes pode não funcionar. A seguir você pode ver como declarar variáveis e alguns dos seus principais tipos:

```c++
int a, b, c;    // declara 3 variáveis do tipo inteiro
                // variáveis do tipo int (32 bits) suportam valores de até 10 dígitos (+/-2 x 10⁹)

long long ll;   // declara um inteiro de 64 bits, que suporta valores de até 20 dígitos (+/-9 x 10¹⁹)
                // variáveis long long podem ser úteis qunado você tem que somar vários inteiros

float real32;   // declara um ponto flutuante de 32 bits

double real64;  // declara um ponto flutuante de 64 bits
                // se você precisa fazer várias contas com números reais, opte pelo double 

char c = 'a';   // armazena um caracter ou um valor inteiro de 8 bits (-128 a 127)

string s = "tchau mundo!" // armazena uma cadeia de caracteres

bool mentira = false; // armazena um valor verdadeiro ou falso
```

Também tem a variação sem sinal de cada tipo, que você consegue colocando ``unsigned`` na frente da declaração (ex: ``unsigned int``). Isso desloca toda a faixa de valores negativos pro positivo, permitindo a representação de valores positivos ainda maiores (um ``unsigned char`` pode variar de 0 a 255, por exemplo), mas raramente precisamos nos preocupar com isso.

Você também pode declarar variáveis de diversas dimensões:

```c++
// declara arrays de várias dimensões
int vetor[100];
double matriz[100][100];
...
// atribui uma posição do array à outra variável
int v0 = vetor[0];
double m4_10 = matriz[4][10];
```

Na seção [Controle de fluxo](#3---controle-de-fluxo) falarei mais de vetores e matrizes.

### 1.2 - Entrada e Saída

Para ler a entrada do usuário, podemos usar a função ``cin``, a sintaxe dela é meio estranha, mas com o tempo fica fácil de usar:

```c++
int x, y;
std:cin >> x >> y;
```

Quando isso for executado, é preciso digitar dois números no teclado e pressionar enter. O que for digitado será armazenado em ``x`` e ``y``, respectivamente.

Para mostrar valores no terminal, podemos usar a função ``cout``, com as flechinhas na direção contrária do ``cin``:

```c++
int a = 10, b = 20;
std:cout << a << " " << b << '\n';  // o \n é uma quebra de linha

double pi = 3.141592653589793;
std:cout << std:setprecision(2) << pi << '\n';  // o setprecision define quantas casas decimais imprimir. 
                                                // nesse caso, apenas "3.14" será impresso
```

## 2 - Funções

Seu programa sempre deverá ter uma função principal, que indica onde ele deve começar a executar. No caso do C++, essa é a função ``main``. Por padrão, a função ``main`` é to dipo inteiro e retorna 0, a não ser que algo de errado tenha acontecido no seu programa. Resolvendo problemas em competições, o retorno deve sempre ser 0 (por padrão, o compilador adiciona o retorno de 0 pra você, então você não precisa escrever).

Lembra que comentei que o C++ tem uma biblioteca padrão que facilita muita coisa? Então... Não é uma boa prática de programação, mas vamos usar a biblioteca ``bits/stdc++.h``, por simplicidade. Essa biblioteca inclui todas as estruturas e funções utilitárias da biblioteca padrão, que podem ser consultadas [**aqui**](https://cplusplus.com/reference/) (esse link pode ser muito útil).

Percebeu que pra usar ``cin`` e ``cout`` foi preciso colocar um ``std:`` na frente? Isso serve pra definir que as funções ``cin`` e ``cout`` vem do espaço de nomenclatura padrão (*standard* -> *std*). Não vou explicar aqui os detalhes sobre espaços de nomenclatura (em algum momento você vai aprender), mas pro nosso propósito, queremos sempre usar o espaço padrão, então podemos dizer isso pro nosso programa no início dele, e podemos omitir o ``std:`` dali pra frente:

```c++
#include <bits/stdc++.h> // inclui todas as bibliotecas padrão
using namespace std;     // configura o espaço de nomenclatura como std

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
```

Além da função main, você pode querer declarar outras funções, pra deixar seu código mais bem organizado. A declaração de uma função no C++ deve especificar um tipo de retorno (que pode ser qualquer tipo primitivo, ou ``void``, caso ela não precise retornar nada), e os tipos e nomes de cada parâmetro.

Aproveitando a deixa, é interessante falar sobre escopo de variáveis. Uma variável global é declarada fora de qualquer função. Variáveis globais são acessíveis por qualquer função que aparece depois dela, desde que na função não haja uma variável com mesmo nome.

Quando um valor é passado como parâmetro de uma função, o valor daquela variável na função que fez a chamada não vai ser alterado, a não ser que a variável seja passada por referência. No código e com os comentários isso pode ficar mais claro:

```c++
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
    int a = 10, b = 20.123456;
    // aqui usei printf por ser mais fácil de formatar
    // vou deixar um link explicando os parâmetros
    printf("a = %d, b = %.2lf, i = %d\n\n", a, b, i);
    printf("soma_1(a, b) = %d\n", soma_1(a, b));
    printf("a = %d, b = %.2lf, i = %d\n\n", a, b, i);
    printf("soma_2(a, b) = %d\n", soma_2(a, b));
    printf("a = %d, b = %.2lf, i = %d\n", a, b, i);
    // se eu tivesse usado cout, teria que escrever esse monstro aqui:
    // cout << "a = " << a << ", b = " << b << ", i = " << i << "\n\n";
}
```

[Aqui](https://cplusplus.com/reference/cstdio/printf/) você encontra as especificações do ``printf``

A saída esperada desse programa é a seguinte:

```none
a = 10, b = 20.12, i = 0

soma_1(a, b) = 50
a = 10, b = 20.12, i = 1

soma_2(a, b) = 50
a = 30, b = 20.12, i = 2
```

### 3 - Controle de fluxo

#### 3.1 - `if/else`

O `if` é usado pra executar um bloco de código apenas se uma condição for cumprida. Caso essa condição não seja cumprida, podemos definir o que acontece com o `else`. Uma condição é uma expressão lógica, que pode ser verdadeira ou falsa.

Os operadores lógicos são:

- `&&`, `||`, `!`: e, ou, não, respectivamente
- `==`, `!=`: igual, diferente
- `>`, `>=`: maior, maior ou igual
- `<`, `<=`: menor, menor ou igual

```c++
if(x == 0) cout << "x é 0\n";
else       cout << "x não é 0\n";
```

Você pode concatenar vários `if`s usando `else if`:

```c++
if (x > 0)
    cout << "x é positivo\n";
else if(x < 0)
    cout << "x é negativo\n";
else
    cout << "x é 0\n;"
```

Perceba que espaços em branco no C++ não fazem diferença. Além disso, nesses exemplos, como há apenas uma instrução para ser executada dependendo da condição (`cout << "x é ...";`), você pode omitir o abre e fecha chaves, mas quando a condicional deve executar mais de uma instrução, é preciso usar chaves:

```c++
if(x == 0)
{
    cout << "x é ";
    cout << x << '\n';
}

```

É interessante saber que no C++ qualquer valor diferente de 0 é considerado positivo:

```c++
if(1)  cout << "1 - Isso sempre será executado\n";
if(0)  cout << "1 - Isso nunca será executado\n";
if(!0) cout << "2 - Isso sempre será executado\n";
if(!1) cout << "2 - Isso nunca será executado\n";
// if(1) e if(0) é o mesmo que escrever if(true) e if(false)
```

#### 3.2 - Laços de repetição

Laços de repetição, ou *loops* repetem um bloco de código enquanto uma condição for verdadeira. Podemos usar `while`, `for` e `do` (mas esse último é meio ignorado então não vou explicar ele [é bem parecido com o `while`]).

O `while` faz exatamente o que a definição de *loop* diz: repete um bloco de código enquanto sua condição for verdadeira. Quando a condição deixar de ser verdadeira, o *loop* para:

```c++
int n = 5;
while(n > 0)
{
    cout << n << " ";
    n--; // decrementa n de um em um
}
cout << "\n";

// a saída desse código é:
// 5 4 3 2 1
```

O *loop* `for` repete um bloco de código determinado número de vezes, a sintaxe é `for(inicialização; condição; incremento){};`. Assim como o `while`, ele repetirá o código enquanto a condição for verdadeira, mas define posições especificas para você inicializar e incrementar a variável de controle, sendo muito boa para usar com contadores e iterar vetores e matrizes:

```c++
for(int i = 1; i <= 5; i++)
    cout << i << " ";
cout << "\n";

// esse código imprime:
// 1 2 3 4 5
```

```c++
int v[] = {1, 2, 3, 4, 5}; // sim, dá pra inicializar vetores assim
for(int i = 4; i >= 0; i--) // percorre vetor de trás pra frente
    cout << v[i] << " ";
cout << "\n";

// esse código imprime:
// 5 4 3 2 1
```

Pra iterar em matrizes, geralmente usamos um `for` dentro do outro:

```c++
int m[3][3] = {{1, 2, 3}, // e dá pra inicializar matrizes assim
               {4, 5, 6}, // mas é preciso especificar o tamanho
               {7, 8, 9}};

for(int i = 0; i < 3; i++)
{
    for(int j = 0; j < 3; j++)
        printf("[%d]", m[i][j]);
    printf("\n");
}

/* <- isso inicia um comentário de várias linhas
esse código imprime:
[1][2][3]
[4][5][6]
[7][8][9]
isso termina um comentário de várias linhas -> */
```

Lembre-se que, se a condição de parada nunca acontecer, o código ficará repetindo pra sempre, e na maioria das vezes isso é um problema.

As vezes você quer que seu *loop* pare de executar antes do previsto, pra isso pode usar o `break`:

```c++
for(int i = 0; i < 100; i++)
{
    cout << i << ", ";
    if(i > 10)
    {
        cout << "STOP THE COUNT!!\n";
        break;
    }
}

// esse código imprime:
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, STOP THE COUNT!!
```

```c++
int x;
int soma = 0;
while(true)
{
    cin >> x;
    if(!x) // se op for igual a 0
        break;
    else
        soma += x;
}
cout << soma << "\n";

// digamos que você executou esse programa e digitou:
// 10 5 2 2 1 0
// ele vai acumular os valores 10, 5, 2, 2 e 1 à soma 
// e parar de executar o loop quando ler 0
// aí vai imprimir 20
```

Você também pode querer pular algumas iterações, mas continuar o *loop* normalmente depois disso, usando o `continue`:

```c++
for(int i = 0; i < 10; i++)
{
    if(i % 2) continue; // se o resto de i/2 é diferente de 0
    cout << i << " ";
}
cout << "\n";

// esse código imprime:
// 0 2 4 6 8
```

#### 3.3 - Escopo

Assim como uma variável declarada dentro de uma função não é acessível para outra, variáveis declaradas dentro de um bloco condicional ou *loop* não são acessíveis fora dele:

```c++
int x;
cin >> x;

if(x < 10)
{
    int a, b;               // a e b são apenas acessíveis dentro do if
    cin >> a >> b;
    cout << a + b << '\n';
}

else
{
    int c;                  // c é apenas acessível dentro do else
    cin >> c;
    cout << x / c << '\n';  // x, por ter sido declarada fora do bloco, pode ser usado aqui
}
// tentar usar a, b ou c fora desses blocos, causará erros de compilação
// dizendo que as variáveis não foram declaradas

for(int i = 0; i < x; i++)
{
    // o i só é reconhecido dentro do loop
}

int i;
for(i = 0; i < x; i++)
{
    // se declarar ele antes, pode usar ele tanto aqui
}
// quanto aqui
```

Pense no escopo como um conjunto de pilhas: sua base é o escopo global para todas elas. Quando criamos uma função, colocamos ela na pilha, assim como quando declaramos blocos de controle de fluxo. Ao fim dos blocos, tiramos ele da pilha. Se temos um bloco e depois outro, podemos visualizar isso como uma pilha ao lado da outra. Tudo o que está no escopo atual e abaixo dele é acessível, mas não o que está ao seu lado:

```c++
#include <bits/stdc++.h>
using namespace std;

int x, y;

int fun(int a, int b)
{
    if(a > b)
    {
        int c = a - b;
        return c;
    }
    else
    {
        int c = 0;
        for(int i = a; i <= c; i++)
            c += i;
        return c;
    }
}

int main()
{
    cin >> x >> y;
    int z = soma(x, y);
    cout << z << '\n';
}
```

![alt text](images/intro/scope-stack-dark.png#gh-dark-mode-only)
![alt text](images/intro/scope-stack-light.png#gh-light-mode-only)

## 4 - Strings

Uma *string* nada mais é do que uma *array* do tipo `char`. é comum que você veja códigos com *strings* declaradas assim:

```c++
char str[200];
char hello[] = "Olá mundo!";
```

Entretanto, esse tipo de declaração é muito comum no C. No C++, há um container que engloba uma série de funções para tornar a manipulação de strings mais fácil, e você pode declarar strings com a própria palavra `string`:

```c++
string str;
string hello = "Olá mundo!";
```

o tipo string é dinâmico, então não é necessário definir um tamanho específico antes de usar a estrutura, a não ser que você deseje acessar uma posição específica ou uma posição que vai além do que já está na string. Quando você declara uma string, ela é vazia:

```c++
string s;    // o tamanho da string é 0
s[9] = 'a'; // isso causará falha de segmentação

string t;
t = "abcdefghij" // o tamanho da string é 10
s[9] = 'k';      // isso não causa erro, pois você estará
                 // alterando a ultima posição da string
```

Mas você também pode inicializar a string com um tamanho específico, ou até mesmo com uma repetição de caractere específico:

```c++
string s(10, 'a');
cout << s << '\n';
// aaaaaaaaaa
```

Você pode percorrer e alterar strings como se fosse um vetor:

```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s(10, 'a');
    cout << s << endl;

    for(int i = 0; i < s.size(); i++)
        if(i % 2) s[i] = 'b';
    
    cout << s << endl;
}

// esse código imprime:
// aaaaaaaaaa
// ababababab
```

O `cin` separa a entrada por caracteres em branco, isso pode ser um espaço, uma quebra de linha ou um tab. Então, lembre-se que, quando for ler uma entrada, estará lendo uma palavra de cada vez, e se digitar mais palavras do que o esperado, as demais serão ignoradas. Caso precise ler a linha toda, você pode usar a função `getline(cin, variável, token)`. O token indica para a função quando ela deve parar de ler, no caso de ler uma linha, o token é a quebra de linha `'\n'`:

```c++
string palavra;
string frase;

cin >> palavra;
cin.ignore(); // precisamos disso para que o getline
              // ignore a quebra de linha digitada depois da palavra
getline(cin, frase, '\n');
```

## 5 - Conclusão

Acho que isso já é uma carga considerável de coisas para absorver de uma vez, principalmente se você for iniciante. Recomendo que abra os códigos disponíveis [aqui](/code-examples/intro/), leia, compile e execute os exemplos, faça alterações e testes, até se sentir confortável.

### 5.1 - Exercícios recomendados

Lembre-se, a melhor forma de aprender a programar é programando, então deixo aqui uma lista de exercícios recomendados para que você treine a sintaxe básica da linguagem:

- [1001 - Extremamente Básico](https://judge.beecrowd.com/pt/problems/view/1001)
- [1002 - Área do Círculo](https://judge.beecrowd.com/pt/problems/view/1002)
- [1013 - O maior](https://judge.beecrowd.com/pt/problems/view/1013)
- [1017 - Gasto de Combustível](https://judge.beecrowd.com/pt/problems/view/1017)
- [1037 - Intervalo](https://judge.beecrowd.com/pt/problems/view/1037)
- [1052 - Mês](https://judge.beecrowd.com/pt/problems/view/1052)
- [1059 - Números pares](https://judge.beecrowd.com/pt/problems/view/1059)
- [1060 - Números positivos](https://judge.beecrowd.com/pt/problems/view/1060)
- [1435 - Matriz Quadrada I](https://judge.beecrowd.com/pt/problems/view/1435)
- [1914 - De quem é a vez](https://judge.beecrowd.com/pt/problems/view/1914)
