/*

1. Escreva uma função recursiva que recebe um vetor como parâmetro e um valor k. Caso o valor k exista no vetor, a função deverá retornar a sua posição, senão deverá retornar -1.
    Dado um vetor de inteiros A, apresente algoritmos recursivos para calcular

2. O elemento máximo do vetor.

3. O elemento mínimo do vetor

4. A soma dos elementos do vetor.

5. O produto dos elementos do vetor.

6. A média dos elementos do vetor.

7. Construa um algoritmo que leia duas sequencias de caracteres (string) e verifique se elas são idênticas.

8. Faça um algoritmo que leia três nomes os imprima em ordem alfabética.

9. Construa um algoritmo que leia uma palavra (vetor de caracteres) e verifique recursivamente se a palavra é um palíndromo.

10. Implemente a questão anterior de forma recursiva.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
    Definições com declaração referente ao exercício
    Antes do include das funções pois utilizo estas nelas
*/
#define N1 10
#define N2 10
#define N3 10
#define N4 10
#define N5 10
#define N6 10

#include "functions.h"

int main() {
    int exercise;

    printf("Escolha o exercicio que deseja executar:");
    printf("\n1 | Procura no vetor");
    printf("\n2 | Maior elemento do vetor");
    printf("\n3 | Menor elemento do vetor");
    printf("\n4 | Soma dos elementos do vetor");
    printf("\n5 | Produto dos elementos do vetor");
    printf("\n6 | Media dos elementos do vetor");
    printf("\n7 | Compara strings");
    printf("\n8 | Nomes em ordem alfabetica");
    printf("\n9 | Verifica se a palavra e um palindromo");
    printf("\n10 | Verifica se a palavra e um palindromo");
    printf("\n0 | Para sair");
    printf("\n: ");
    scanf("%i", &exercise);
    fflush(stdin);

    if(exercise >= 0 && exercise <= 10) {
        if(exercise == 0) {
            
            printf("Até logo!");

        }else if(exercise == 1) {

            int num,
                vect[N1] = {0,1,2,3,4,5,6,7,8,9};

            printf("Digite um numero a ser verificado se existe em um dado o vetor com termos sendo algarismos de 0 a 9 (Ex: 7): ");
            scanf("%i", &num);
            fflush(stdin);

            int search = searchNum(num, vect, 0);
            
            // Verifica se o retorno é maior ou igual a 0 (diferente de -1) para exibir a posição
            if(search >= 0){
                printf("O numero existe no vetor e sua posicao e: %i", search);
            }else{
                printf("O numero nao existe no vetor. %i", search);
            }

        }else if(exercise == 2) {

            int vect[N2] = {0,1,2,3,4,5,6,7,8,9};
            printf("O maior elemento do vetor e o numero %i", biggestElement(0, vect, 0));

        }else if(exercise == 3) {

            int vect[N3] = {0,1,2,3,4,5,6,7,8,9};
            printf("O menor elemento do vetor e o numero %i", smallestElement(0, vect, 0));

        }else if(exercise == 4) {

            int vect[N4] = {0,1,2,3,4,5,6,7,8,9};
            printf("A soma dos elementos do vetor e %i", sumElements(0, vect, 0));

        }else if(exercise == 5) {

            int vect[N5] = {1,2,3,4,5,6,7,8,9,10};
            printf("O produto dos elementos do vetor e %i", multiplicationElements(1, vect, 0));

        }else if(exercise == 6) {

            int vect[N6] = {0,1,2,3,4,5,6,7,8,9};
            printf("A media dos elementos do vetor e %.3f", averageElements(0, vect, 0));

        }else if(exercise == 7) {

            char str1[20],
                 str2[20];

            printf("Digite a primeira string (Ex: Gabriel): ");
            scanf("%s", &str1);
            fflush(stdin);

            printf("Digite segunda string (Ex: Henrique): ");
            scanf("%s", &str2);
            fflush(stdin);

            // Condição que verifica se as strings são iguais
            if(strcmp(str1, str2) == 0) {
                printf("As strings sao iguais");
            } else {
                printf("As strings sao diferentes");
            }

        }else if(exercise == 8) {

            char str1[20],
                 str2[20],
                 str3[20];

            printf("Digite o primeiro nome (Ex: Gabriel): ");
            scanf("%s", &str1);
            fflush(stdin);

            printf("Digite o segundo nome (Ex: Henrique): ");
            scanf("%s", &str2);
            fflush(stdin);

            printf("Digite o terceiro nome (Ex: Silva): ");
            scanf("%s", &str3);
            fflush(stdin);

            // Char que armazena as letras do alfabeto em ordem
            char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

            // Loop para exibir os nomes em ordem alfabética
            for(int i = 0; i < 26; i++) {

                if(str1[0] == alf[i] || str1[0] == toupper(alf[i]))
                    printf("%s\n", str1);

                if(str2[0] == alf[i] || str2[0] == toupper(alf[i]))
                    printf("%s\n", str2);

                if(str3[0] == alf[i] || str3[0] == toupper(alf[i]))
                    printf("%s\n", str3);

            }

        }else if(exercise == 9) {

            char str[50];

            printf("Digite uma palavra (Ex: Gabriel): ");
            scanf("%s", &str);
            fflush(stdin);

            // Variável que armazena quantidade de letras da string e tira 1 para se adequar ao loop que inicia em 0
            int length = strlen(str)-1;

            // Formando a exibição do resultado
            printf("A palavra %s ", str);

            // Loop para verificar se a string é um palindromo
            for(int i = 0; i < length; i++) {
                
                /*
                    Condição que verifica se:
                        a letra i é diferente da letra length-i
                        &&
                        a letra i transformada em maiuscula é diferente da letra length-i transformada em maiuscula
                    
                    Caso satisfaça a condição, ou seja, caso as letras comparadas forem diferentes,
                    não carateriza-se um palindromo, então para o loop e exibe "nao" para formar a exibição do resultado
                */
                if(str[i] != str[length-i] && toupper(str[i]) != toupper(str[length-i])) {
                    printf("nao ");
                    break;
                }
            
            }

            // Conclui a exibição do resultado
            printf("e um palindromo");

        }else if(exercise == 10) {

            char str[50];

            printf("Digite uma palavra (Ex: Gabriel): ");
            scanf("%s", &str);
            fflush(stdin);

            printf("A palavra %s ", str);
            if(!isPalin(str, strlen(str)-1, 0)) // Condição que verifica se é palindromo e forma a exibição do resultado (printf)
                printf("nao ");
            printf("e um palindromo");

        }
    }

    return 0;
}