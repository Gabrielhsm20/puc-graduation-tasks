#include <stdio.h>

int main(){
    float num1, num2, num3, total;

    printf("Digite as três notas (Ex: 10 10 10): ");
    scanf("%f %f %f", &num1, &num2, &num3);
    fflush(stdin);

    total = (num1 + num2 + num3) / 3;

    if(total < 0 || total > 10){
        printf("Erro.");
    }else{
        if(total < 5){
            printf("Conceito: E");
        }else if(total < 6){
            printf("Conceito: D");
        }else if(total < 7){
            printf("Conceito: C");
        }else if(total < 8){
            printf("Conceito: B");
        }else{
            printf("Conceito: A");
        }
    }

    return 0;
}