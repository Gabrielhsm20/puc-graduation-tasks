#include <stdio.h>

void somar(int *result, int *num1, int *num2) {
    *result = *num1 + *num2;
}

void subtracao(int *result, int *num1, int *num2) {
    *result = *num1 - *num2;
}

void divisao(int *result, int *num1, int *num2) {
    *result = *num1 / *num2;
}

void multiplicacao(int *result, int *num1, int *num2) {
    *result = *num1 * *num2;
}

int main() {
    int num1, num2, *result = (int *)malloc(sizeof(int));
    char option;

    printf("Digite o primeiro numero: ");
    scanf("%i", &num1);
    fflush(stdin);

    printf("Digite o segundo numero: ");
    scanf("%i", &num2);
    fflush(stdin);

    printf("Selecione uma operacao:\n");
    printf("+ | Adicao\n");
    printf("- | Substracao\n");
    printf("/ | Divisao\n");
    printf("* | Multiplicacao\n");
    printf(": ");
    scanf("%c", &option);

    switch (option) {
        case '+':
            somar(result, &num1, &num2);
            printf("%i + %i = %i", num1, num2, *result);
            break;
        case '-':
            subtracao(result, &num1, &num2);
            printf("%i - %i = %i", num1, num2, *result);
            break;
        case '/':
            divisao(result, &num1, &num2);
            printf("%i / %i = %i", num1, num2, *result);
            break;
        case '*':
            multiplicacao(result, &num1, &num2);
            printf("%i * %i = %i", num1, num2, *result);
            break;
        default:
            printf("Opcao nao encontrada");
    }

    free(result);

    return 0;
}