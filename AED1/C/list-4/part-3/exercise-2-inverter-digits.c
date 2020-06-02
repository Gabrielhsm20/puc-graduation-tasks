/*

Faça um algoritmo que imprime o reverso de um número inteiro lido pelo teclado. Exemplo:
O reverso de 1234 é 4321.

*/

#include <stdio.h>

int main(){
    int i;

    printf("Insira um numero inteiro (Ex: 4567): ");
    scanf("%i", &i);
    fflush(stdin);

    // Loop para dividir i por 10 a cada ciclo enquanto i for maior que 10
    for (; i > 10; i/=10) {

        // Exibir o resto da divisão
        printf("%i", i % 10);

    }

    // Exibe o i quando não for mais maior que 10
    printf("%i", i);

    /*
        Exemplo:  123

        123 % 10: 3
        12 % 10: 2
        Como i não é maior que 10, exibe o próprio:  1
    */
    
    return 0;
}