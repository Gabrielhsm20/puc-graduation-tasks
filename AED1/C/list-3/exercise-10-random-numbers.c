/*

Construa um algoritmo que gere 100 números aleatórios entre 1 e 100, mostre a soma e a
média dos números gerados.

*/

#include <stdio.h>
#include <conio.h>

int main(){
    int sum = 0;

    // Loop para gerar 100 números
    for(int i = 0; i < 100; i++){
        // Gerar um número entre 0 e 100
        int num = rand() % 100;

        // Somar o número gerado à variável sum
        sum += num;
    }

    printf("A soma dos numeros gerados (entre 0 e 100) e: %i", sum);
    printf("\nA media dos numeros gerados (entre 0 e 100) e: %f", (float) sum/100);

    return 0;
}