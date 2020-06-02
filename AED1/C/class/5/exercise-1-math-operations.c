#include <stdio.h>
#include <math.h>

int main(){
    int num1, num2;

    printf("Digite dois números inteiros (Ex: 10 10): ");
    scanf("%i %i", &num1, &num2);
    fflush(stdin);

    printf("\n%i mais %i é %i", num1, num2, num1+num2);
    printf("\n%i menos %i é %i", num1, num2, num1-num2);
    printf("\n%i vezes %i é %i", num1, num2, num1*num2);
    printf("\n%i dividido por %i é %i", num1, num2, num1/num2);

    return 0;
}