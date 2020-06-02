/*

1. Construa um algoritmo que copie o conteúdo da matriz preenchida para uma segunda de mesmo tamanho, e imprima o seu conteúdo.

2. Construa um algoritmo que cria uma segunda matriz de números reais de tamanho N x M e  solicita ao usuário o preenchimento dessa segunda matriz. Verifique se o conteúdo dessa segunda matriz é igual ao conteúdo da primeira.

3. Construa um algoritmo que solicite ao usuário que digite um número real k, calcule o mostre quantas vezes o número k ocorre dentro da matriz.

4. Construa um algoritmo que mostre o número da primeira linha da matriz em que está localizado o maior valor nela presente.

5. Construa um algoritmo que calcule e exiba quantos números são maiores que o valor médio da matriz.

6. Construa um algoritmo que calcule e mostre o maior valor acima da diagonal principal de uma matriz de reais (não considerar a própria diagonal). Trate as situações que impeçam a execução dessa verificação.

7. Construa um algoritmo que calcule e retorne a diferença entre o maior valor presente acima da diagonal principal e o maior valor presente abaixo da diagonal principal de uma matriz de reais. Trate as situações que impeçam a execução dessa verificação.

8. Construa um método que calcule e retorne a soma dos valores de uma determinada coluna de da matriz. O usuário deverá informar a coluna desejada.

9. Construa um algoritmo que determina e imprime a transposta da matriz.

Parte II – Registros e Matrizes
10. O problema das 8 Rainha consiste em colocar 8 Rainhas em tabuleiro de xadrez de forma que nenhuma rainha ataque a outra.
    (https://2.bp.blogspot.com/-adYZZMF68Ck/T8uJu9SeCUI/AAAAAAAAA5c/6tbEs3JEHSM/s1600/oitorainhas.png)

    Faça um algoritmo que verifique se as posições de rainhas informadas pelo usuário são válidas.
    O seu algoritmo deverá ter as seguintes opções:
    
    a) Digitar a posição de uma rainha (linha e colunas – valores entre 1 e 8). Os dados deverão ser guardados em um vetor do tipo Jogada (tamanho máximo de 8 Jogadas).
    struct Jogada {
        int ordem; // Cada jogada deve ter um id incremental
        int x;
        int y;
    }

    b) Imprimir sequencialmente o conteúdo do vetor (para cada jogada: ordem, x, y).
    c) Marcar em uma matriz (8x8) as posições armazenadas no vetor na opção anterior (a).
    d) Verificar na matriz se as posições são válidas.
    e) Imprimir a matriz

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

// Variáveis referente à matriz principal do programa
#define L 4
#define C 4

// Variável referente à lateral do tabuleiro de xadrez
#define X 8

// Struct que grava as posições solicitada no enunciado (comentado pois não tem utilidade no programa)
// struct Positions {
//     int id;
//     int x;
//     int y;
// };

// struct Positions Position[X];
int Board[X][X];

// Include das funções do programa
#include "functions.h"

int main() {
    // Preparando o rand para gerar um número tendo como referência o time
    srand(time(NULL));

    // Declarando a matriz principal do programa
    int mat[L][C];

    char option;
    printf("Voce deseja preencher a matriz? (S/N): ");
    scanf("%c", &option);
    fflush(stdin);

    // Condição que verifica se o usuário quer preencher a matriz principal
    if(toupper(option) == toupper('N')) {

        for(int i = 0; i < L; i++) {
            for(int j = 0; j < C; j++) {
                mat[i][j] = rand() % 10;
            }
        }

    } else {

        for(int i = 0; i < L; i++) {
            for(int j = 0; j < C; j++) {
                printf("Digite o numero correspondente a posicao %ix%i (Ex: 10): ", i, j);
                scanf("%i", &mat[i][j]);
                fflush(stdin);
            }
        }

    }

    // Exibe a matriz principal
    printf("\nMatriz %ix%i em questao:\n", L, C);
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < C; j++) {
            printf("%i\t", mat[i][j]);
        }
        printf("\n");
    }

    // Menu
    int exercise;
    printf("\nEscolha o exercicio que deseja executar:");
    printf("\n1 | Clonar matriz");
    printf("\n2 | Comparar matrizes");
    printf("\n3 | Contabilizar aparicoes de um numero");
    printf("\n4 | Linha do maior elemento da matriz");
    printf("\n5 | Calcular numeros maiores que a media");
    printf("\n6 | Maior numero acima da diagonal principal");
    printf("\n7 | Diferenca entre o maior numero acima e abaixo da diagonal principal");
    printf("\n8 | Soma dos elementos de uma coluna");
    printf("\n9 | Matriz transposta");
    printf("\n10 | Tabuleiro de rainhas do xadrez");
    printf("\n0 | Para sair");
    printf("\n: ");
    scanf("%i", &exercise);
    fflush(stdin);

    printf("\n");

    if(exercise >= 0 && exercise <= 10) {
        if(exercise == 0) {
            
            printf("Até logo!");

        }else if(exercise == 1) {

            // Declarando a matriz clonada
            int newMat[L][C];

            // Atribuindo valores e exibindo a matriz clonada
            printf("Matriz %ix%i em clonada:\n", L, C);
            for(int i = 0; i < L; i++) {
                for(int j = 0; j < C; j++) {
                    newMat[i][j] = mat[i][j];
                    printf("%i\t", newMat[i][j]);
                }
                printf("\n");
            }

        }else if(exercise == 2) {

            // Declarando a nova matriz
            int newMat[L][C],
                different =  0;

            // Loop enquanto o que o usuário digitar for idêntico à matriz principal
            for(int i = 0; i < L && !different; i++) {
                for(int j = 0; j < C && !different; j++) {
                    printf("Digite o numero correspondente a posicao %ix%i da segunda matriz (Ex: 10): ", i, j);
                    scanf("%i", &newMat[i][j]);
                    fflush(stdin);

                    if(newMat[i][j] != mat[i][j])
                        different = 1;
                }
            }

            printf((different) ? "\nAs matrizes sao diferentes" : "\nAs matrizes sao iguais");

        }else if(exercise == 3) {

            int num,
                count = 0;

            printf("Digite um numero para contabilizar suas exibicoes na matriz (Ex: 10): ");
            scanf("%i", &num);
            fflush(stdin);

            // Loop para contar as aparições do número lido
            for(int i = 0; i < L; i++)
                for(int j = 0; j < C; j++)
                    if(mat[i][j] == num)
                        count++;

            printf("\nO numero %i apareceu %i vezes na matriz", num, count);

        }else if(exercise == 4) {
            
            int biggest,
                line;

            // Loop para encontrar o maior número e a linha que este se encontra
            for(int i = 0; i < L; i++)
                for(int j = 0; j < C; j++)
                    if(i==0 || mat[i][j] > biggest){
                        line = i+1;
                        biggest = mat[i][j];
                    }
            
            printf("O maior elemento da matriz e %i e esta localizado na linha %i", biggest, line);

        }else if(exercise == 5) {
            
            int sum = 0,
                average,
                count = 0;
            
            // Loop para somar os números da matriz principal
            for(int i = 0; i < L; i++)
                for(int j = 0; j < C; j++)
                    sum += mat[i][j];

            // Operação para encontrar a média aritmética
            average = sum / (L * C);

            // Loop para contar quantos números estão acima da média
            for(int i = 0; i < L; i++)
                for(int j = 0; j < C; j++)
                    if(mat[i][j] > average)
                        count++;
            
            printf("%i numeros sao maiores que a media da matriz", count);

        }else if(exercise == 6) {
            
            // Condição que verifica se a matriz é quadrada
            if(L != C) {
                printf("Esta matriz nao possui diagonais pois nao e quadrada");
            } else {
                int biggest = 0;

                // Loop que percorre os números acima da diagonal principal para encontrar o maior
                for(int i = 0; i < L; i++)
                    for(int j = i+1; j < C; j++)
                        if((i==0 && j==1) || mat[i][j] > biggest)
                            biggest = mat[i][j];

                printf("O maior numero acima da diagonal principal e %i", biggest);
            }

        }else if(exercise == 7) {

            // Condição que verifica se a matriz é quadrada
            if(L != C) {
                printf("Esta matriz nao possui diagonais pois nao e quadrada");
            } else {
                int biggestU = 0,
                    biggestD = 0;

                // Loop que percorre a matriz para encontrar o maior número acima e abaixo da matriz principal
                for(int i = 0; i < L; i++){
                    for(int j = 0; j < C; j++){
                        if(i != j){
                            if(i < j) {
                                if((i==0 && j==0) || mat[i][j] > biggestU)
                                    biggestU = mat[i][j];
                            } else {
                                if((i==0 && j==0) || mat[i][j] > biggestD)
                                    biggestD = mat[i][j];
                            }
                        }
                    }
                }
                
                printf(
                    "O maior numero acima da diagonal principal e %i\n"
                    "O maior numero abaixo da diagonal principal e %i\n"
                    "A diferenca entre os numeros e %i" 
                , biggestU, biggestD, biggestU - biggestD);
            }

        }else if(exercise == 8) {

            int col,
                sum = 0;
            
            // Loop enquanto o número for diferente de 1 - 8
            do {
                printf("Digite a coluna (1 - %i) a qual deseja somar os elementos (Ex: 1): ", C);
                scanf("%i", &col);
                fflush(stdin);
            } while(col <= 0 || col > C);

            // Loop para somar os elementros da coluna
            for(int i = 0; i < L; i++)
                sum += mat[i][col-1];

            printf("\nA soma dos numeros da coluna %i e %i", col, sum);
        }else if(exercise == 9) {

            // Loop para exibir a matriz transposta (linha vira coluna)
            printf("Matriz transposta:\n");
            for(int i = 0; i < C; i++) {
                for(int j = 0; j < L; j++) {
                    printf("%i\t", mat[j][i]);
                }
                printf("\n");
            }

        }else if(exercise == 10) {

            // Loop para preencher o tabuleiro de xadrez com 0
            for(int i = 0; i < X; i++) {
                for(int j = 0; j < X; j++) {
                    Board[i][j] = 0;
                }
            }
            
            // Loop para exibir o atual estado do tabuleiro e solicitar que se insira uma nova posição
            for(int p = 0; p < X; p++) {
                printf("Atual tabuleiro:\n");
                for(int i = 0; i < X; i++) {
                    for(int j = 0; j < X; j++) {
                        printf("%i\t", Board[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                setPosition(p);
            }

            // Após inserir as 8 posições, loop para exibir o tabuleiro final
            printf("Tabuleiro final:\n");
            for(int i = 0; i < X; i++) {
                for(int j = 0; j < X; j++) {
                    printf("%i\t", Board[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}