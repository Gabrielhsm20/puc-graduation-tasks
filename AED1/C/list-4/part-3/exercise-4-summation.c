/*

Faça um algoritmo que calcule o seguinte somatório:

S = 1/225 + 2/196 + 4/169 + 8/144 + ... + 16384/1

*/

#include <stdio.h>

int main(){

    int numerator = 1,
        denominator = 15;
    float sum = 0;

    // Loop enquanto o denominador for maior que 1
    while(denominator >= 1){
        // Soma à variável sum o resultado da operação do numerador dividido pelo denominador ao quadrado
        sum += numerator / (float) (denominator * denominator);
        
        // Dobra o numerador
        numerator *= 2;

        // Diminui 1 do denominador
        denominator -= 1;
    }

    printf("O resultado é %f", sum);

    return 0;
}