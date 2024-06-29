# Resolvendo problemas

A maioria dos problemas de maratona seguem um padrão específico. Primeiro, você terá a descrição do problema. Com ela, você deverá estruturar a lógica básica da sua solução. Depois, você terá um trecho explicando como deve ser lida a entrada do problema, e como deve ser dada a resposta.

Na explicação da entrada, você deve se atentar à ordem em que os dados serão lidos pelo programa, e também aos limites de cada variável. Alguns limites também podem ser dados no meio da descrição do problema, então anote eles se for preciso. Quanto à saida, você deve prestar bastante atenção aos detalhes e limites, pois a resposta impressa pelo seu programa deve ser **exatamente** igual aos exemplos dados na especificação do problema, caso contrário, sua resposta será considerada errada.

Essa explicação toda pode parecer muito vaga, então, nada melhor do que analisar um problema.

## Exemplos de problemas

### Ciclismo [[MFP - 2024](https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/C)]

#### Limites básicos

Os primeiros dados apresentados são quanto aos limites de tempo de execução, limite de memória, e onde deve ser feita a entrada e a saída:

    tempo limite: 1 segundo
    limite de memória: 256 MB
    entrada: entrada padrão
    saída: saída padrão

- **Limite de tempo:** sua solução deve terminar de executar em no máximo 1 segundo.
- **Limite de memória:** você pode alocar variáveis e estruturas que ocupem no máximo 256 MB
- **Entrada e saída:** os dados devem ser lidos e impressos na saída padrão do terminal (`cin/cout` ou `scanf/printf`)

#### Descrição

Nas Olimpíadas, uma nova modalidade tem chamado atenção: o duelo de ciclismo. Na edição atual, Amy e Blaze vão disputar a final. Nesse duelo, há uma pista em formato de circunferência na qual as duas competidoras vão pedalar até que alguém complete um certo número de voltas. Você está assistindo à competição e quer saber qual o comprimento de uma volta, mas tudo que você sabe é que Amy acabou de concluir a última volta, percorrendo um total de $A$ metros, e que Blaze está em algum ponto da última volta, tendo percorrido um total de $B$ metros até então.

Porém, você percebeu que, como não sabe o número total de voltas, existem vários valores possíveis para o comprimento de uma volta. Por conta disso, sua tarefa é escrever um programa que imprima o menor valor inteiro possível para esse comprimento.

#### Entrada

A entrada consiste de uma única linha com dois inteiros A e B separados por espaço ( $0 ≤ B < A ≤ 10^5$ ), o comprimento que Amy e Blaze percorreram até o momento, respectivamente.

    Atente-se ao intervalo dado:
        0 <= B <= 10^5
        B < A <= 10^5
    B pode ter valores de 0 a 10^5, inclusive
    A é estritamente maior que B (então A != B), e pode chegar até 10^5

    Como A e B são inteiros positivos que valerão no máximo 10^5, você pode armazenar
    seus valores em uma variável do tipo int

#### Saída

Imprima uma única linha com um inteiro $X$, o menor comprimento inteiro possível de uma volta.

    Como A e B valem no máximo 10^5, X também deve valer no máximo 10^5 
    e pode ser armazenado em uma variável do tipo int

#### Exemplos

| Exemplo de entrada | Exemplo de saída  |
|--------------------|-------------------|
|  `36 32`           |  `4`              |

| Exemplo de entrada | Exemplo de saída  |
|--------------------|-------------------|
|  `49 46`           |  `7`              |

| Exemplo de entrada | Exemplo de saída  |
|--------------------|-------------------|
| `7 0`              |   `7`             |

#### Explicação

Voltando à descrição do problema, podemos retirar alguns dados que podem nos ajudar a chegar na solução:

- "Amy acabou de concluir a última volta, percorrendo um total de $A$ metros";
- "Blaze está em algum ponto da última volta, tendo percorrido um total de $B$ metros até então";
- "existem vários valores possíveis para o comprimento de uma volta";
- "escrever um programa que **imprima o menor valor inteiro ( $X$ ) possível** para esse comprimento";

Se Amy concluiu a última volta após percorer $A$ metros, e $X$ é o menor comprimento de uma volta, isso significa que $A$ deve ser divisível por $X$ (pense que $X \times N = A$, sendo $N$ o número de voltas percorridas por Amy).

Se Blaze está em algum ponto da última volta, quer dizer que após Blaze percorrer $A - B$ metros, ele terá completado o percurso.

Então, o menor valor de uma volta $X$ deve estar entre $A - B$ e $A$ ( $A - B$ ≤ $X$ ≤ $A$ ), e ser um divisor de $A$. Você pode testar os valores dentro de um *loop*. Quando encontrar um divisor de $A$, significa que encontrou a resposta. **Tente codar essa solução e envie no CodeForces!**

Textualmente, pode ser um pouco confuso de entender a lógica, então se encontrar dificuldade, sugiro que desenhe uma circunferência (ou linha) de comprimento $X$, e anote os valores de $A$ e $A - B$, de acordo com os exemplos de entrada e saída.

<details><summary><small>Spoiler</small></summary>

O código que resolve esse problema [está no repositório](/code-examples/solving-problems/ciclismo.cpp), mas sugiro fortemente que você tente resolver por conta própria antes de olhar a solução. Também sugiro que crie uma conta no CodeForces para enviar seu código e ter certeza de que sua solução está correta.

</details>