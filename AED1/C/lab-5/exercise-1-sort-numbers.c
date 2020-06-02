#include <stdio.h>

int main(){
    float num1, num2, num3;

    printf("Digite três números (Ex: 10 10 10): ");
    scanf("%f %f %f", &num1, &num2, &num3);
    fflush(stdin);

    if(num1 == num2 && num1 == num3){
        // TODOS IGUAIS
        printf("Números iguais");
    }else if(num1 == num2 && num1 != num3){
        if(num1 > num3){
            // MAIOR: num1 e num2
            // MENOR: num3
            printf("Maior: %f e %f\nMenor: %f", num1, num2, num3);
        }else{
            // MAIOR: num3
            // MENOR: num1 e num2
            printf("Maior: %f\nMenor: %f e %f", num3, num1, num2);
        }
    }else if(num1 == num3 && num1 != num2){
        if(num1 > num2){
            // MAIOR: num1 e num3
            // MENOR: num2
            printf("Maior: %f e %f\nMenor: %f", num1, num3, num2);
        }else{
            // MAIOR: num2
            // MENOR: num1 e num3
            printf("Maior: %f\nMenor: %f e %f", num2, num1, num3);
        }
    }else if(num2 == num3 && num2 != num1){
        if(num2 > num1){
            // MAIOR: num2 e num3
            // MENOR: num1
            printf("Maior: %f e %f\nMenor: %f", num2, num3, num1);
        }else{
            // MAIOR: num1
            // MENOR: num2 e num3
            printf("Maior: %f\nMenor: %f e %f", num1, num2, num3);
        }
    }else if(num1 > num2 && num1 > num3){
        if(num2 > num3){
            // MAIOR: num1
            // MEIO: num2
            // MENOR: num3
            printf("Maior: %f\nMeio: %f\nMenor: %f", num1, num2, num3);
        }else{
            // MAIOR: num1
            // MEIO: num3
            // MENOR: num2
            printf("Maior: %f\nMeio: %f\nMenor: %f", num1, num3, num2);
        }
    }else if(num2 > num1 && num2 > num3){
        if(num1 > num3){
            // MAIOR: num2
            // MEIO: num1
            // MENOR: num3
            printf("Maior: %f\nMeio: %f\nMenor: %f", num2, num1, num3);
        }else{
            // MAIOR: num2
            // MEIO: num3
            // MENOR: num1
            printf("Maior: %f\nMeio: %f\nMenor: %f", num2, num3, num1);
        }
    }else{
        if(num1 > num2){
            // MAIOR: num3
            // MEIO: num1
            // MENOR: num2
            printf("Maior: %f\nMeio: %f\nMenor: %f", num3, num1, num2);
        }else{
            // MAIOR: num3
            // MEIO: num2
            // MENOR: num1
            printf("Maior: %f\nMeio: %f\nMenor: %f", num3, num2, num1);
        }
    }

    return 0;
}