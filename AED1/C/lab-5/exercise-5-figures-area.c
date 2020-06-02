#include <stdio.h>

#define PI 3.1415

int main(){
    int num;

    printf("Escolha a figura que você deseja calcular a área: ");
    printf("\n1 - Quadrado");
    printf("\n2 - Retângulo");
    printf("\n3 - Triângulo");
    printf("\n4 - Circulo");
    printf("\n: ");
    scanf("%i", &num);
    fflush(stdin);

    float size1, size2, area = 0;

    switch (num){
        case 1:
            printf("Insira o tamanho do lado do quadrado (Ex: 10): ");
            scanf("%f", &size1);
            fflush(stdin);
            area = pow(size1, 2);
            break;

        case 2:
            printf("Insira o tamanho da base e da altura do retângulo (Ex: 10 10): ");
            scanf("%f %f", &size1, &size2);
            fflush(stdin);
            area = size1 * size2;
            break;

        case 3:
            printf("Insira o tamanho da base e da altura do triângulo (Ex: 10 10): ");
            scanf("%f %f", &size1, &size2);
            fflush(stdin);
            area = (size1 * size2) / 2;
            break;
        
        case 4:
            printf("Insira o tamanho do raio do circulo (Ex: 10): ");
            scanf("%f", &size1);
            fflush(stdin);
            area = PI * pow(size1, 2);
            break;
    
        default:
            printf("Opção inválida");
            break;
    }

    if(area){
        printf("A área correspondente à figura equivale à: %0.2f", area);
    }

    return 0;
}