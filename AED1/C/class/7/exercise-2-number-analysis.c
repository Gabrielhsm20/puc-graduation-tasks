#include <stdio.h>

int main(){
    int num;

    printf("Digite um número inteiro (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    if(num == 0){
        printf("Zero");
    }else{
        printf("O número %i é ", num);
        if(num*num % 2 == 0){
            printf("par e ");
        }else{
            printf("impar e ");
        }
        
        if(num > 0){
            printf("positivo");
        }else{
            printf("negativo");
        }
    }

    return 0;
}