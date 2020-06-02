#include <stdio.h>
#include <math.h>

int main(){
    float number;

    printf("Digite um número maior que 0 (Ex: 10): ");
    scanf("%f", &number);
    fflush(stdin);

    printf("\nO numero %f ao quadrado: %f", number, pow(number, 2));
    printf("\nO numero %f ao cubo: %f", number, pow(number, 3));
    printf("\nA raiz quadrada do numero: %f", sqrt(number));
    printf("\nA raiz cubica do numero: %f", pow(number, 1.0/3));

    return 0;
}