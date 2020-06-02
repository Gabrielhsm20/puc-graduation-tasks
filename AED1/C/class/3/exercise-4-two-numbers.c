#include <stdio.h>
#include <math.h>

int main(){
    float num1, num2;

    printf("Digite dois números maiores que 0 (Ex: 10 10): ");
    scanf("%f %f", &num1, &num2);
    fflush(stdin);

    printf("\nO numero %f elevado à %f é %f", num1, num2, pow(num1, num2));
    printf("\nO numero %f elevado à %f é %f", num2, num1, pow(num2, num1));

    return 0;
}