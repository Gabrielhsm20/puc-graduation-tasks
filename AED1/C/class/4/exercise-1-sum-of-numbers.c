#include <stdio.h>

int main(){
    float num1, num2;

    printf("Digite dois números (Ex: 10 10): ");
    scanf("%f %f", &num1, &num2);
    fflush(stdin);

    printf("\n%f mais %f é %f", num1, num2, num1+num2);

    return 0;
}