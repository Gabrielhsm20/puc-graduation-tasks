/*

Calculadora com as quatro operações aritméticas básicas. Oferecer um menu ao usuário com
as operações. Ler os dois operandos. Calcular e escrever o resultado.

*/

#include <stdio.h>

int main(){
    float num1, num2;
    char operation;

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Insira dois números (Ex: 10 10): ");
    scanf("%f %f", &num1, &num2);
    fflush(stdin);

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira uma das operações matemáticas abaixo:");
    printf("\n+ | Adição");
    printf("\n- | Subtração");
    printf("\n/ | Divisão");
    printf("\n* | Multiplicação");
    printf("\n: ");
    scanf("%c", &operation);
    fflush(stdin);

    // Verifica a operação inserida e exibe o resultado
    if(operation == '+'){
        printf("Resultado: %f", num1+num2);
    }else if(operation == '-'){
        printf("Resultado: %f", num1-num2);
    }else if(operation == '*'){
        printf("Resultado: %f", num1*num2);
    }else if(operation == '/'){
        printf("Resultado: %f", num1/num2);
    }else{
        printf("Operação inválida");
    }

    return 0;
}