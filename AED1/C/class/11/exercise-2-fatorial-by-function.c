#include <stdio.h>

int fatorial(int num) {    
    if(num < 0){
        return -1;
    }else{
        int result = 1;
        for (int i = num; i > 0; i--) {
            result *= i;
        }

        return result;
    }
}

int main() {
    int num;

    printf("Digite um numero inteiro maior que zero (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    int result = fatorial(num);

    printf("O fatorial de %i e %i", num, result);

    return 0;
}