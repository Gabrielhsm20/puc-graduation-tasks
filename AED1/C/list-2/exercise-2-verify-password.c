/*

Escreva um programa que verifique a validade de uma senha fornecida pelo usuário. A
senha válida é o número 5555. Devem ser impressas as seguintes mensagens:
ACESSO PERMITIDO - caso a senha seja válida.
ACESSO NEGADO - caso a senha seja inválida.

*/

#include <stdio.h>

int main(){
    int pass;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira a senha de acesso (Ex: 1212): ");
    scanf("%i", &pass);
    fflush(stdin);

    printf("\n");

    // Verifica se a senha inserida é válida
    if(pass == 5555){
        printf("ACESSO PERMITIDO");
    }else{
        printf("ACESSO NEGADO");
    }

    return 0;
}