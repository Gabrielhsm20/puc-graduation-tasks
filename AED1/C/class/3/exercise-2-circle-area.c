#include <stdio.h>

#define PI 3.1415

int main(){
    float raio, area;
    
    printf("Qual a medida do raio?");
    scanf("%f", &raio);
    fflush(stdin);

    area = PI * pow(raio, 2);

    printf("\nA área do circulo é igual a %f", area);

    return 0;
}