#include <stdio.h>

int main(){
    int num1, num2, num3;

    printf("Digite três números inteiros (Ex: 10 10 10): ");
    scanf("%i %i %i", &num1, &num2, &num3);
    fflush(stdin);

    if(num1 == num2 && num1 == num3){
        printf("%i = %i = %i", num1, num2, num3);
    }else if(num1 == num2 && num1 != num3){
        if(num1 > num3){
            // printf("%i = %i > %i", num1, num2, num3);
            printf("%i < %i = %i", num3, num2, num1);
        }else{
            // printf("%i > %i = %i", num3, num1, num2);
            printf("%i = %i < %i", num2, num1, num3);
        }
    }else if(num1 == num3 && num1 != num2){
        if(num1 > num2){
            // printf("%i = %i > %i", num1, num3, num2);
            printf("%i < %i = %i", num2, num3, num1);
        }else{
            // printf("%i > %i = %i", num2, num1, num3);
            printf("%i = %i < %i", num3, num1, num2);
        }
    }else if(num2 == num3 && num2 != num1){
        if(num2 > num1){
            // printf("%i = %i > %i", num2, num3, num1);
            printf("%i < %i = %i", num1, num3, num2);
        }else{
            // printf("%i > %i = %i", num1, num2, num3);
            printf("%i = %i < %i", num3, num2, num1);
        }
    }else if(num1 > num2 && num1 > num3){
        if(num2 > num3){
            // printf("%i > %i > %i", num1, num2, num3);
            printf("%i < %i < %i", num3, num2, num1);
        }else{
            // printf("%i > %i > %i", num1, num3, num2);
            printf("%i < %i < %i", num2, num3, num1);
        }
    }else if(num2 > num1 && num2 > num3){
        if(num1 > num3){
            // printf("%i > %i > %i", num2, num1, num3);
            printf("%i < %i < %i", num3, num1, num2);
        }else{
            // printf("%i > %i > %i", num2, num3, num1);
            printf("%i < %i < %i", num1, num3, num2);
        }
    }else{
        if(num1 > num2){
            // printf("%i > %i > %i", num3, num1, num2);
            printf("%i < %i < %i", num2, num1, num3);
        }else{
            // printf("%i > %i > %i", num3, num2, num1);
            printf("%i < %i < %i", num1, num2, num3);
        }
    }

    return 0;
}