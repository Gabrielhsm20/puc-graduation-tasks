#include <stdio.h>

int main(){
    float base, heigth;
   
    printf("Digite a base e a altura do triângulo (Ex: 10 5): ");
    scanf("%f %f", &base, &heigth);
    fflush(stdin);

    printf("\nA área do triângulo é igual a %f", (base * heigth)/2);

    return 0;
}