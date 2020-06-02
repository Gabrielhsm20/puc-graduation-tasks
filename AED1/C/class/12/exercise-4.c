#include <stdio.h>

int *numberAddress(int *num1, int *num2, int *num3, int *num4, int *num5){
    if(*num1 <= *num2 && *num1 <= *num3 && *num1 <= *num4 && *num1 <= *num5){
        return num1;
    }else if(*num2 <= *num1 && *num2 <= *num3 && *num2 <= *num4 && *num2 <= *num5){
        return num2;
    }else if(*num3 <= *num1 && *num3 <= *num2 && *num3 <= *num4 && *num3 <= *num5){
        return num3;
    }else if(*num4 <= *num1 && *num4 <= *num2 && *num4 <= *num3 && *num4 <= *num5){
        return num4;
    }else{
        return num5;
    }
}

int main() {
    int num1, num2, num3, num4, num5;

    printf("Insira 5 numeros inteiros para visualizar o endereco na memoria de suas variaveis (Ex: 1 2 3 4 5): ");
    scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
    fflush(stdin);

    printf("Endereco      |       Valor");
    printf("\n%p      |       %i", &num1, num1);
    printf("\n%p      |       %i", &num2, num2);
    printf("\n%p      |       %i", &num3, num3);
    printf("\n%p      |       %i", &num4, num4);
    printf("\n%p      |       %i", &num5, num5);

    printf("\n\n");

    int *address = numberAddress(&num1, &num2, &num3, &num4, &num5);

    printf("O menor numero e %i e seu endereco e %p", *address, address);

    return 0;
}