#include <stdio.h>

int main(){
    int num, factorial = 1;

    do{
        printf("Insira um número inteiro positivo maior que zero (Ex: 10): ");
        scanf("%i", &num);
        fflush(stdin);

        if(num > 0){
            for(int i = num; i > 0; i--){
                factorial *= i;
            }

            printf("%i fatorial é %i", num, factorial);
        }
    }while(num <= 0);

    return 0;
}