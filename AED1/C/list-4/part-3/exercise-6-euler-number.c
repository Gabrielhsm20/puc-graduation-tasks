/*

Faça um algoritmo que leia um número X do teclado e calcular o valor de ex através da seguinte série:

e^x = x^0 + x^1/1! + x^2/2! + x^3/3!...

Deverão ser adicionados apenas os termos maiores ou iguais a 10-4

*/

#include <stdio.h>
#include <math.h>

int factorial(int num) {
    int result = 1;
    for (int i = num; i > 0; i--) {
        result *= i;
    }

    return result;
}

int main(){
    int num,
        count = 0;

    float result = 0,
          term = 0;

    printf("Insira um numero inteiro (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    // Loop enquanto o termo for maior que 10^-4
    do {
        // Número inserido pelo usuário elevado à count dividido pelo fatorial de count
        term = pow(num, count) / (float) factorial(count);
        
        // Soma apenas se o resultado for maior ou igual à 10^-4
        if(term >= pow(10, -4)){
            result += term;
        }

        // Soma 1 ao expoente/denominador
        count++;
    } while (term > pow(10, -4));

    // Como o último termo é menor ou igual à 10^-4 o loop para, e é exibido o resultado
    printf("O resultado da soma e %f", result);

    return 0;
}