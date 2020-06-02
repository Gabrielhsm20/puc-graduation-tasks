/*

Crie um procedimento que recebe um número inteiro k maior que 1. O seu
procedimento deverá calcular e "retornar por referência" um valor de n (maior que 1) que
atenda a seguinte condição:

Por exemplo, para o caso de k = 4, então um valor de n=5 satisfaz a condição.
Construa também uma função main que solicita ao usuário o valor de k, faz a chamada do
procedimento passando os parâmetros, e depois mostra o valor de n encontrado.

*/

#include <stdio.h>
#include <math.h> // Biblioteca math.h para utilizar funções como pow (potenciação)

/*
    Descrição: procedimento que recebe um número e atribui o valor que atende à condição à variável correspondingNumber
    Entradas (tipos e para que servem): um valor inteiro para realizar o loop e verificar a condição
*/
void verifyNumber(int *num, int *correspondingNumber) {
    int i = 1; // Variável que possui o número a ser verificado a cada loop
    *correspondingNumber = 0; // Atribui o valor 0 ao ponteiro correspondingNumber para auxiliar no loop

    do {
    
        i++; // Soma 1 à variável que possui o numero a ser verificado
        *correspondingNumber = i > 1 && pow(*num, i) > pow(i, *num) ? i : 0;
    
    } while(*correspondingNumber == 0);

}

int main() {
    int number, // Variável que recebera o valor inserido
        correspondingNumber; // Variável que recebera o valor retornado por referência do procedimento

    // Comando que solicita que o usuário insira um numero para ser operado
    printf("Digite um numero inteiro (Ex: 20): ");
    scanf("%i", &number);
    fflush(stdin);

    // Chama o procedimento que faz a verificação e retorna por referência o número que atende à condição
    verifyNumber(&number, &correspondingNumber);

    // Exibe o número que atende à condição
    printf("O numero que atente a condicao e %i", correspondingNumber);

    return 0;
}