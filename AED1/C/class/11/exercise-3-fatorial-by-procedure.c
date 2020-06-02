#include <stdio.h>

void fatorial(int num) {
    if(num < 0){
        printf("Erro. O numero deveria ser maior que zero.");
    }else{
        int result = 1;
        for (int i = num; i > 0; i--) {
            result *= i;
        }

        printf("O fatorial de %i e %i", num, result);
    }
}

int main() {
    int num;

    printf("Digite um numero inteiro maior que zero (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    fatorial(num);

    return 0;
}