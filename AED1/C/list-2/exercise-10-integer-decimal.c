/*

Crie um algoritmo que leia um número real (float) e mostre sua parte inteira e sua parte
fracionária.

*/

#include <stdio.h>

int main(){
    float numReal, numDec;
    int numInt;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira um número real (Ex: 10): ");
    scanf("%f", &numReal);
    fflush(stdin);

    printf("Parte inteira: %i\nParte decimal: %f", (int) numReal, (numReal - (int) numReal));

    return 0;
}