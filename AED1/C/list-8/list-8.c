/*

Recursividade – Parte 1
1) Escreva uma função recursiva divide(A,B) para calcular a divisão inteira de A por B utilizando apenas subtrações.

2) Escreva uma função recursiva que recebe um número inteiro e retorne o número de dígitos.
    Exemplo. N = 50 – saída deverá ser 2.

3) Escreva uma função recursiva que recebe um número inteiro e retorne a soma dos seus dígitos.
    Exemplo = N = 45. Saída deverá ser 9.

4) Escreva uma função recursiva que retorne o resultado da multiplicação dos dois parâmetros utilizando apenas o operador somas.

5) Escreva uma função recursiva que calcule o n-ésimo termo de uma progressão geométrica onde o primeiro termo e a razão são informados pelo usuário.

Vetores – Parte 2
6) Faça um programa que lê 10 números informados pelo usuário e armazena em um vetor.
    Imprima os elementos em ordem reversa da leitura.

7) Faça um programa que lê 10 números informados pelo usuário e armazena em um vetor.
    Imprima os elementos do vetor cujo valor seja igual ao índice da posição.

8) Faça um programa que preenche um vetor de 15 posições com números aleatórios. Use a função rand da biblitoeca <stdlib.h> preencher o vetor com números inteiros gerados aleatoriamente entre 0 e 10.

9) Construa um algoritmo que gere 15 temperaturas aleatórias entre 18 e 40 C e armazene em um vetor. Imprima a maior, a menor e a temperatura média. Mostre também o número de vezes que a temperatura foi abaixo da média.

10) Faça um algoritmo que preenche e imprime um vetor de tamanho 10 usando a seguinte regra: - Se a posição do vetor é múltipla de 2, deve-se armazenar 1. Caso contrário, armazene 0.

11) Construa um algoritmo que leia N números entre 0 e 9 informados pelo usuário e depois armazene em cada posição i de um vetor de 10 posições o número de vez que o número i apareceu.

12) Faça um algoritmo que preenche um vetor com os primeiros 100 elementos da série de Fibonacci. Após preencher o vetor, imprima seu conteúdo.

13) Construa um algoritmo que preenche um vetor com o resultado da função f(x) = 3x³ + 2x² + 1x -5, onde X é o índice da posição do vetor. Após preencher vetor, imprima seu conteúdo.

14) Faça um algoritmo que armazena em um vetor n números digitados pelo usuário. Posteriormente, mostre o segundo menor valor do vetor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

#define N6 10
#define N7 10
#define N8 15
#define N9 15
#define N10 10
#define N11 10
#define N12 100
#define N13 10
#define N14 10

int main() {
    int exercise;

    printf("Escolha o exercicio que deseja executar:");
    printf("\n1 | Divisao recursiva");
    printf("\n2 | Quantidade de digitos");
    printf("\n3 | Soma dos digitos");
    printf("\n4 | Multiplicacao recursiva");
    printf("\n5 | N-esimo termo da progressao");
    printf("\n6 | Preenchimento e exibicao inversa de vetor");
    printf("\n7 | Exibicao do numero caso igual ao indice");
    printf("\n8 | Preenchimento de vetor c/ num. aleatorios");
    printf("\n9 | Resultado de temperaturas geradas");
    printf("\n10 | Vetor com indice multiplo de 2");
    printf("\n11 | Numero de aparicoes do indice");
    printf("\n12 | Cem primeiros numeros da serie de fibonacci");
    printf("\n13 | Funcao do indice");
    printf("\n14 | Segundo menor valor digitado");
    printf("\n0 | Para sair");
    printf("\n: ");
    scanf("%i", &exercise);
    fflush(stdin);

    if(exercise >= 0 && exercise <= 14) {
        if(exercise == 0) {
            
            printf("Até logo!");

        }else if(exercise == 1) {

            int num1, num2;

            // Comando que solicita que o usuário insira dois números para serem calculados
            printf("Digite dois numero para efetuar a divisao (Ex: 100 10): ");
            scanf("%i %i", &num1, &num2);
            fflush(stdin);

            // Exibe o resultado da operação
            printf("O resultado da divisao inteira de %i por %i e igual a %i", num1, num2, division(num1, num2, 0));

        }else if(exercise == 2) {

            int num;

            // Comando que solicita que o usuário insira dois números para serem calculados
            printf("Digite um numero para saber a quantidade de algarismos (Ex: 10): ");
            scanf("%i", &num);
            fflush(stdin);

            // Exibe a quantidade de algarismos que o número possui
            printf("O numero %i possui %i algarismos", num, countLength(num, 1));

        }else if(exercise == 3) {

            int num;

            // Comando que solicita que o usuário insira dois números para serem calculados
            printf("Digite um numero para saber a soma de seus algarismos (Ex: 10): ");
            scanf("%i", &num);
            fflush(stdin);

            // Exibe a quantidade de algarismos que o número possui chamando a função com o módulo do número inserido
            printf("\n\nA soma dos algarismos do numero %i e %i", num, sunNumbers(fabs(num), 0));

        }else if(exercise == 4) {

            int num1, num2;

            // Comando que solicita que o usuário insira dois números para serem calculados
            printf("Digite dois numero para efetuar a multiplicacao (Ex: 10 10): ");
            scanf("%i %i", &num1, &num2);
            fflush(stdin);

            // Exibe o resultado da operação
            printf("O resultado da multiplicacao de %i por %i e igual a %i", num1, num2, multiplication(num1, num2));

        }else if(exercise == 5) {

            int num, reason, position;

            // Comando que solicita que o usuário insira dois números para serem calculados
            printf("Digite o PRIMEIRO TERMO da progressao geometrica, a RAZAO e o N-ESIMO TERMO (Ex: 1 10 5): ");
            scanf("%i %i %i", &num, &reason, &position);
            fflush(stdin);

            // Exibe o resultado
            printf("O termo de posicao %i e %i", position, pg(num, reason, position, 1));

        }else if(exercise == 6) {

            // Declarando o vetor
            int num[N6];

            // Loop que solicita a inserção de N números
            for (int i = 0; i < N6; i++) {
                // Comando que solicita que o usuário insira um número
                printf("Digite o %i numero (Ex: 10): ", i+1);
                scanf("%i", &num[i]);
                fflush(stdin);
            }
            
            // Loop para exibir os números inseridos na ordem inversa
            for (int i = N6-1; i >= 0; i--) {
                printf("%i ", num[i]);
            }

        }else if(exercise == 7) {

            int num[N7];

            // Loop que solicita a inserção de N números
            for (int i = 0; i < N7; i++) {
                // Comando que solicita que o usuário insira um número
                printf("Digite o %i numero (Ex: 10): ", i+1);
                scanf("%i", &num[i]);
                fflush(stdin);
            }
            
            // Loop para exibir os números caso este seja igual sua posição no vetor
            for (int i = N7-1; i >= 0; i--) {
                // Condição que verifica se o número é igual sua posição no vetor
                if(num[i] == i){
                    printf("%i ", num[i]);
                }
            }

        }else if(exercise == 8) {

            int num[N8];

            // Loop para gerar e atribuir valores ao vetor
            for (int i = 0; i < N8; i++) {
                // Gerando e atribuindo valor ao vetor
                num[i] = rand() % 10;

                // Exibindo o número gerado
                printf("%i ", num[i]);
            }

        }else if(exercise == 9) {

            int num[N9],
                average = 0,
                belowAverage = 0,
                bigger,
                smaller;
            
            // Loop para gerar e atribuir valores ao vetor
            for (int i = 0; i < N9; i++) {
                num[i] = 18 + rand() % (40 - 18); // Gerando e atribuindo valor ao vetor
                average += num[i];
            }

            // Calculando a média de temperaturas
            average /= N9;

            // Exibindo as temperaturas geradas (juntamente com o loop abaixo)
            printf("Temperaturas geradas: ");

            // Loop para exibir as temperaturas geradas, calcular a maior e menor e contabilizar quantas foram abaixo da média
            for (int i = 0; i < N9; i++) {
                printf("%i ", num[i]);
                if(i==0 || num[i] > bigger) { bigger = num[i]; } // Condição que verifica se a temperatura é a maior
                if(i==0 || num[i] < smaller) { smaller = num[i]; } // Condição que verifica se a temperatura é a menor
                if(num[i] < average){ belowAverage++; } // Condição que verifica se a temperatura está abaixo da média
            }

            // Exibindo os resultados
            printf("\n%i foi a maior temperatura", bigger);
            printf("\n%i foi a menor temperatura", smaller);
            printf("\n%i foi a media de temperatura", average);
            printf("\n%i temperaturas abaixo da media", belowAverage);

        }else if(exercise == 10) {

            int num[N10];

            // Loop atribuir valores ao vetor
            for (int i = 0; i < N10; i++) {
                // Atribuindo valor ao vetor: se a posição for múltipla de dois atribui 1, caso cotrátio, 0.
                num[i] = i % 2 == 0 ? 1 : 0 ;

                // Exibindo o valor atribuído ao vetor
                printf("%i ", num[i]);
            }

        }else if(exercise == 11) {

            // Declarando o vetor
            int num[N11];

            // Loop que solicita a inserção de N números
            for (int i = 0; i < N11; i++) {
                do {
                    // Comando que solicita que o usuário insira um número
                    printf("Digite o %i numero (Ex: 10): ", i+1);
                    scanf("%i", &num[i]);
                    fflush(stdin);
                } while(num[i] < 0 || num[i] > 9);
            }

            // Vetor para contagem das posições
            int count[N11] = {0,0,0,0,0,0,0,0,0,0};
            
            // Loop que contabiliza a quantidade de vezes que a posição apareceu
            for(int i = 0; i < N11; i++) {
                count[num[i]]++;
            }

            // Loop que exibe os resultados
            for(int i = 0; i < N11; i++) {
                printf("\nPosicao %i apareceu %i vezes", i, count[i]);
            }

        }else if(exercise == 12) {

            int vect[N12],
                pre2 = 0,
                pre1 = 0,
                num;

            // Loop para exibir a quantidade requerida pelo usuário
            for (int i = 0; i < N12; i++) {
                // Atribui valor 0 para a primeira exibição e 1 para a segunda, após isso começa somar os dois anteriores
                num = i == 0 ? 0 : pre2 < 1 ? 1 : pre2 + pre1;

                pre2 = pre1;  // Atribui o valor do último à variável do pnultimo
                pre1 = num;  // Atribui o valor do número atual à variável do último

                // Atribui o valor de num ao vetor
                vect[i] = num;

                // Exibe o termo desta posição do vetor
                printf("%i ", num);
            }

        }else if(exercise == 13) {

            int vect[N13];
    
            // Loop para preencher o vetor de acordo com a expressão do enunciado
            for(int i = 0; i < N13; i++) {
                // Atribuindo o resultado à possição do vetor
                vect[i] = 3 * pow(i, 3) + 2 * pow(i, 2) + i - 5;

                // Exibindo o resultado
                printf("\nIndice: %i - Resultado: %i", i, vect[i]);
            }

        }else if(exercise == 14) {

            // Declarando o vetor e variáveis auxiliares
            int num[N14],
                firstSmallest,
                secondSmallest;

            // Loop que solicita a inserção de N números
            for (int i = 0; i < N14; i++) {
                // Comando que solicita que o usuário insira um número
                printf("Digite o %i numero (Ex: 10): ", i+1);
                scanf("%i", &num[i]);
                fflush(stdin);
            }
            
            // Loop para comparar e definir o menor e segundo menor número
            for (int i = 0; i < N14; i++) {
                if(i==0 || num[i] < firstSmallest) { firstSmallest = num[i]; }
                if(i==0 || (num[i] > firstSmallest && num[i] < secondSmallest)) { secondSmallest = num[i]; }

                printf("%i ", num[i]);
            }

            printf("\nO segundo menor numero digitado foi %i", secondSmallest);

        }
    }

    return 0;
}