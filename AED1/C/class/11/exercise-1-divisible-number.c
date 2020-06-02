#include <stdio.h>

int isDivisible(int num) {
    if(num % 3 == 0 && num % 5 == 0){
        return 1;
    }else{
        return -1;
    }
}

int main() {
    int num;

    printf("Digite um numero inteiro maior que zero (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    int divisible = isDivisible(num);

    if(divisible == 1){
        printf("O numero %i e divisivel por 3 e 5", num);
    }else{
        printf("O numero %i nao e divisivel por 3 e 5", num);
    }

    return 0;
}