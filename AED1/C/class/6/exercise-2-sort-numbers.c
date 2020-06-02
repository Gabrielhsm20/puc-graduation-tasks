#include <stdio.h>

int main(){
    float num1, num2;

    printf("Digite dois números (Ex: 10 10): ");
    scanf("%f %f", &num1, &num2);
    fflush(stdin);

    if(num1 == num2){
        printf("%f é igual a %f", num1, num2);
    }else if(num1 > num2){
        printf("%f é maior que %f", num1, num2);
    }else{
        printf("%f é menor que %f", num1, num2);
    }

    return 0;
}