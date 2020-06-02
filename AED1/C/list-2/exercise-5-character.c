/*

Crie um programa que leia um caracter (tipo char) e mostre se:
- É uma letra do alfabeto maiúscula
- É uma letra do alfabeto minúscula
- É um número inteiro entre 0 e 9.
- Caracter diferente das opções anteriores.

*/

#include <stdio.h>

// Biblioteca para os comandos: isdigit, islower e isupper
#include <ctype.h>

int main(){
    char digit;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira um digito (Ex: 0-9,A-Z,a-z): ");
    scanf("%c", &digit);
    fflush(stdin);

    printf("\n");
    
    if(isdigit(digit)){     // Verifica se o digito é um caractere decimal
        printf("Este digito é um caractere decimal");
    }else if(islower(digit)){   // Verifica se o digito é um caractere alfabético minúsculo
        printf("Este digito é um caractere alfabético minúsculo");
    }else if(isupper(digit)){   // Verifica se o digito é um caractere alfabético maiúsculo
        printf("Este digito é um caractere alfabético maiúsculo");
    }else{
        printf("Este digito é um caractere diferente das opções anteriores");
    }

    return 0;
}