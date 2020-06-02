/*

Faça um algoritmo que calcule e escreva a soma dos 20 primeiros números da série:

100/0! + 99/1! + 98/2! + 97/3! + ... + 1/99!

*/

#include <stdio.h>

// Função para encontrar o fatorial do número passado via parâmetro
int factorial(int num) {
    int result = 1;
    for (int i = num; i > 0; i--) {
        result *= i;
    }

    return result;
}

int main(){
    int numerator = 100,
        denominator = 0;
    float result = 0;

    // Loop para somar o resultado das 20 primeiras operações da série
    for (int i = 0; i < 20; i++) {
        // Soma à variável result o resultado da operação do numerador dividido pelo fatorial do denominador
        result += numerator / (float) factorial(denominator);
        printf("%i / %f = %f\n", numerator, (float) factorial(denominator), result);
        
        // Diminui 1 no numerador
        numerator--;

        // Aumenta 1 no denominador
        denominator++;
    }

    // Obs.: A princípio imaginei que a resposta estaria incorreta pois está dando
    // problema para encontrar o fatorial de 13 em diante
    printf("A soma dos 20 primeiro numeros da serie e %f", result);

    return 0;
}