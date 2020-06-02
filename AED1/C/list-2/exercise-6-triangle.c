/*

Crie um programa que leia o valor de 3 ângulos de um triângulo e escreva se o triângulo é
Acutângulo, Retângulo ou Obtusângulo. Sendo que:
− Triângulo Retângulo: possui um ângulo reto (igual a 90º)
− Triângulo Obtusângulo: possui um ângulo obtuso (maior que 90º)
− Triângulo Acutângulo: possui três ângulos agudos (menor que 90º)

*/

#include <stdio.h>

int main(){
    float a, b, c;

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Insira os três ângulos de um triângulo (Ex: 60 60 60): ");
    scanf("%f %f %f", &a, &b, &c);
    fflush(stdin);

    printf("\n");
    
    // Verifica se os valores inseridos satisfaz à condição de existência de um triângulo
    if((a+b) > c && (a+c) > b && (b+c) > a && (a+b+c) == 180){
        if(a < 90 && b < 90 && c < 90){
            printf("Triângulo acutângulo");
        }else if(a == 90 || b == 90 || c == 90){
            printf("Triângulo retângulo");
        }else if(a > 90 || b > 90 || c > 90){
            printf("Triângulo obtusângulo");
        }else{
            printf("Erro");
        }
    }else{
        printf("Triângulo inexistente");
    }

    return 0;
}