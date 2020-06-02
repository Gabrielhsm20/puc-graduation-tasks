/*

Faça um algoritmo que imprima um triangulo alinhado a direta, com n linhas, sendo n um
número inteiro informado pelo usuário. No exemplo a seguir n = 5
*
**
***
****
*****

*/

#include <stdio.h>

int main(){
    int height;

    printf("Insira a altura do triangulo (Ex: 10): ");
    scanf("%i", &height);
    fflush(stdin);

    // Loop que define a quantidade de linhas do triângulo de acordo com a altura inserida pelo usuário
    for(int row = 1; row <= height; row++){
        // Loop para exibir asteriscos até a quantidade de colunas (asteriscos) ficar igual à de linhas
        for(int col = 1; col <= row; col++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}