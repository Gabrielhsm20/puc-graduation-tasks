/*

Construa um algoritmo que leia dois pontos cartesianos (x1, y1, x2, y2) e calcule e mostre a
distância entre esses dois pontos.

*/

#include <stdio.h>
#include <math.h>

int main(){
    float x1, y1, x2, y2, distance;

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Digite o primeiro ponto catesiano (Ex: 10 10): ");
    scanf("%f %f", &x1, &y1);
    fflush(stdin);

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Digite o segundo ponto catesiano (Ex: 10 10): ");
    scanf("%f %f", &x2, &y2);
    fflush(stdin);

    // Calcula a distância entre dois pontos: ((x2-x1)² + (y2-y1)²)^1/2
    distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    printf("A distância entre os pontos (%0.2f, %0.2f) e (%0.2f, %0.2f) é: %0.2f", x1, y1, x2, y2, distance);

    return 0;
}