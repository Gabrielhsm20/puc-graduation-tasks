#include <stdio.h>

int main(){
    float base, heigth, area;
   
    printf("Qual a medida da base?");
    scanf("%f", &base);
    fflush(stdin);

    printf("Qual a medida da altura?");
    scanf("%f", &heigth);
    fflush(stdin);

    area = (base * heigth)/2;

    printf("\nA área do triângulo é igual a %f", area);

    return 0;
}