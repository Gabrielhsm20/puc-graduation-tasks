/*
Neste problema sua tarefa será ler vários números e em seguida dizer quantas vezes cada número aparece na entrada de dados, ou seja, deve-se escrever cada um dos valores distintos que aparecem na entrada por ordem crescente de valor.

Entrada
    A entrada contém apenas 1 caso de teste. A primeira linha de entrada contem um único inteiro N, que indica a quantidade de valores que serão lidos para X (1 ≤ X ≤ 2000) logo em seguida. Com certeza cada número não aparecerá mais do que 20 vezes na entrada de dados.

Saída
    Imprima a saída de acordo com o exemplo fornecido abaixo, indicando quantas vezes cada um deles aparece na entrada por ordem crescente de valor.

Exemplos de Entrada
    7
    8   10  8   260 4   10  10

Exemplos de Saída
    4 aparece 1 vez(es)
    8 aparece 2 vez(es)
    10 aparece 3 vez(es)
    260 aparece 1 vez(es)
*/

#include <stdio.h>

// Defino um valor "grandao" para o vetor
#define N 2000

int main(void) {
    // Declaro as variaveis
    int qnt,
        num,
        vet[N];
    
    // Atribuo o valor do primeiro numero lido a variavel "qnt"
    scanf("%i", &qnt);

    // Atribuo o valor 0 a todas posicoes do vetor
    for(int i=0; i<N; i++)
        vet[i] = 0;

    // Loop para ler os proximos numeros e incrementar na sua posicao 
    for(int i=0; i<qnt; i++){
        scanf("%i", &num);
        vet[num]++;
    }

    // Loop para exibir o numero de aparicoes onde o valor for diferente de zero
    for(int i=0; i<N; i++)
        if(vet[i] > 0)
            printf("%i aparece %i vez(es)\n", i, vet[i]);
}