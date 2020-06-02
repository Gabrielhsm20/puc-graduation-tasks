#include <stdio.h>

int factorial(int num) {
    if(num <= 1){
        return 1;
    }else{
        return num * factorial(num-1);
    }
}

int main() {
    int num;

    printf("Insira um numero o qual deseja calcular o fatorial (Ex: 5): ");
    scanf("%i", &num);
    fflush(stdin);

    printf("O fatorial de %i e %i", num, factorial(num));

    return 0;
}