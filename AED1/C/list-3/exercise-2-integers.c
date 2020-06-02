/*

Construa um programa que escreva na tela do monitor de vídeo os números inteiros de dez
até um (ordem decrescente). Utilize estrutura de repetição com teste no início (while). Mostre
o valor da soma dos números.

*/

#include <stdio.h>

int main(){
    int i = 10,
        end = 1,
        total = 0;

    // Loop para exibir e somar os números inteiros no intervalo de 10 à 1
    while(i >= end){
        printf("%i ", i);
        total += i;
        i--;
    }

    // Exibir o total da soma
    printf("= %i", total);

    return 0;
}