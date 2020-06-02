/*

Identificar se um inteiro lido é par ou não. Se o número for menor ou igual a zero, informe ao
usuário que o número deve ser maior que zero.

*/

#include <stdio.h>

// Função para solicitar e retornar um número maior que zero
int input(char command[60]){
    int value;

    printf("%s", command);
    scanf("%i", &value);
    fflush(stdin);

    if(value <= 0){
        input("Insira um número inteiro MAIOR que zero (Ex: 10): ");
    }else{
        return value;
    }
}

int main(){
    // Declara de variável que receberá o retorno da função
    int num = input("Insira um número inteiro maior que zero (Ex: 10): ");

    printf("\n");

    // Verifica se o número inserido é par
    if(num % 2 == 0){
        printf("O número %f é par", num);
    }else{
        printf("O número %f é impar", num);
    }

    return 0;
}