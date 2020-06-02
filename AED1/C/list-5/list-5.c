/*

1. Crie uma função que recebe três números e retorne o elemento do meio.

2. Crie uma função que recebe 10 números como parâmetro de entrada, calcule e retorne e a média dos números.

3. Crie uma função que recebe dois valores boleanos (A e B) e retorne o valor verdade da operação XOR em relação aos dois valores.

4. Crie um procedimento que calcule e escreva a soma dos 20 primeiros números da série:
    100/0! + 99/1! + 98/2! + 97/3! + ... + 1/99!

5. Crie uma função que calcule e retorne o seguinte somatório:
    S = 1/225 + 2/196 + 4/169 + 8/144 + ... + 16384/1

6. Crie uma função que receba um número real x e calcule a série a seguir:

    sin(x) = x - x^3/3! + x^5/5! - x^7/7! ...

    Cuidado: a série possui infinitos elementos. Limite o número de termos até alcançar uma precisão de 4 casas decimais.

7. Crie uma função que recebe dois inteiros (min e max) e retonar um valor aleatório entre min e max. Max deve ser maior que min, caso contrário sua função deverá retornar -1.

8. Crie um procedimento que recebe valor monetário de até 2 casas decimais e escreva por extenso o valor. Exemplo: se o usuário digital R$ 5,68, então a seu procedimento deverá imprimir: “cinco reais, sessenta e oito centavos”.
    Seu procedimento deverá trabalhar com números positivos até a casa dos bilhões

*/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include "functions.h"

int main() {
    int exercise;

    printf("Escolha o exercicio que deseja executar:");
    printf("\n1 | Retorna o numero do meio");
    printf("\n2 | Retorna a media aritmetica");
    printf("\n3 | Retorna o valor verdade");
    printf("\n4 | Retorna a soma dos numeros da serie");
    printf("\n5 | Retorna o somatorio");
    printf("\n6 | Retorna o calculo da serie seno");
    printf("\n7 | Retonar um valor aleatorio entre min e max");
    printf("\n8 | Retonar o valor monetario por extenso");
    printf("\n0 | Para sair");
    printf("\n: ");
    scanf("%i", &exercise);
    fflush(stdin);

    if(exercise == 0 || exercise == 1 || exercise == 2 || exercise == 3 || exercise == 4 || exercise == 5 || exercise == 6 || exercise == 7 || exercise == 8) {
        if(exercise == 0) {
            
            printf("Até logo!");

        }else if(exercise == 1) {
 
            int num1, num2, num3;

            printf("Insira tres numeros inteiros (Ex: 1 2 3): ");
            scanf("%i %i %i", &num1, &num2, &num3);
            fflush(stdin);

            printf("O numero do meio e %i", middleNumber(num1, num2, num3));
 
        }else if(exercise == 2) {

            int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;

            printf("Insira dez numeros inteiros (Ex: 1 2 3 4 5 6 7 8 9 10): ");
            scanf("%i %i %i %i %i %i %i %i %i %i", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10);
            fflush(stdin);

            printf("A media aritmetica dos 10 numeros e %i", averageOfTenNumbers(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10));

        }else if(exercise == 3) {

            int val1, val2;

            printf("Insira dois valores booleanos 0 ou 1 (Ex: 1 1): ");
            scanf("%i %i", &val1, &val2);
            fflush(stdin);

            printf("O valor verdade da operacao e %i", xorOperation(val1, val2));

        }else if(exercise == 4) {

            numbersOfTheSum();

        }else if(exercise == 5) {

            printf("O resultado da soma do somatorio e %f", summation());

        }else if(exercise == 6) {
            
            int num;

            printf("Insira um numero inteiro (Ex: 1): ");
            scanf("%i", &num);
            fflush(stdin);

            printf("O numero de elementos necessarios e %i", parallelSin(num));

        }else if(exercise == 7) {

            int num1, num2;

            printf("Insira dois numeros inteiros min e max (Ex: 5 10): ");
            scanf("%i %i", &num1, &num2);
            fflush(stdin);

            printf("O numero gerado, entre %i e %i, e %i", num1, num2, randomNumber(num1, num2));

        }else if(exercise == 8) {

            float num;

            printf("Digite um valor em reais (Ex: 150.57): ");
            scanf("%f", &num);
            fflush(stdin);
            
            writeNumber(num);

        }
    }

    return 0;
}