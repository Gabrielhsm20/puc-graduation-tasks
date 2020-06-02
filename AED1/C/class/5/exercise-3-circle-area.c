#include <stdio.h>

#define PI 3.1415

int main(){
    float raio;
    
    printf("Digite a medida do raio (Ex: 10): ");
    scanf("%f", &raio);
    fflush(stdin);

    printf("\nA área do circulo é igual a %f", PI * pow(raio, 2));

    return 0;
}