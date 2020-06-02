#include <stdio.h>

void reverseNumbers(int *num1, int *num2, int *num3, int *num4, int *num5){
    int auxNum1 = *num1, auxNum2 = *num2;

    *num1 = *num5;
    *num2 = *num4;
    *num4 = auxNum2;
    *num5 = auxNum1;
}

int main() {
    int num1, num2, num3, num4, num5;

    printf("Insira 5 numeros inteiros para visualizar o endereco na memoria de suas variaveis (Ex: 1 2 3 4 5): ");
    scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
    fflush(stdin);

    reverseNumbers(&num1, &num2, &num3, &num4, &num5);

    printf("Endereco      |       Valor");
    printf("\n%p      |       %i", &num1, num1);
    printf("\n%p      |       %i", &num2, num2);
    printf("\n%p      |       %i", &num3, num3);
    printf("\n%p      |       %i", &num4, num4);
    printf("\n%p      |       %i", &num5, num5);

    return 0;
}