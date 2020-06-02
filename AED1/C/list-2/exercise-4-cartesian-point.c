/*

Faça um programa que leia um ponto cartesiano (dois valores numéricos X e Y) e mostre em
qual quadrante o ponto se encontra.

*/

#include <stdio.h>

int main(){
    float x, y;

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Insira um ponto cartesiano separado por espaço (Ex: 2 2): ");
    scanf("%f %f", &x, &y);
    fflush(stdin);

    printf("\n");

    // Verifica o quadrante em que o ponto cartesiano se encontra
    if(x == 0 && y > 0){
        printf("O ponto (%0.2f, %0.2f) se encontra entre os quadrantes 1 e 2", x, y);
    }else if(x == 0 && y < 0){
        printf("O ponto (%0.2f, %0.2f) se encontra entre os quadrantes 3 e 4", x, y);
    }else if(x > 0 && y == 0){
        printf("O ponto (%0.2f, %0.2f) se encontra entre os quadrantes 1 e 4", x, y);
    }else if(x < 0 && y == 0){
        printf("O ponto (%0.2f, %0.2f) se encontra entre os quadrantes 2 e 3", x, y);
    }else if(x > 0 && y > 0){
        printf("O ponto (%0.2f, %0.2f) se encontra no quadrante 1", x, y);
     }else if(x < 0 && y > 0){
        printf("O ponto (%0.2f, %0.2f) se encontra no quadrante 2", x, y);
    }else if(x < 0 && y < 0){
        printf("O ponto (%0.2f, %0.2f) se encontra no quadrante 3", x, y);
    }else if(x > 0 && y < 0){
        printf("O ponto (%0.2f, %0.2f) se encontra no quadrante 4", x, y);
    }else{
        printf("O ponto (%0.2f, %0.2f) se encontra no centro", x, y);
    }

    return 0;
}