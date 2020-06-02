/*

Faça um programa que calcule a área total (m2) de uma casa com 3 cômodos. O usuário deve
inserir a largura e comprimento de cada um dos cômodos, calcular a área individual de cada um e
por fim exibir a área total da casa.

*/

#include <stdio.h>

int main(){
    float widthArea1, heightArea1;
    float widthArea2, heightArea2;
    float widthArea3, heightArea3;

    printf("Insira as dimensões do cômodo 1 (Ex: 10 x 10): ");
    scanf("%f x %f", &widthArea1, &heightArea1);
    fflush(stdin);

    printf("Insira as dimensões do cômodo 2 (Ex: 10 x 10): ");
    scanf("%f x %f", &widthArea2, &heightArea2);
    fflush(stdin);

    printf("Insira as dimensões do cômodo 3 (Ex: 10 x 10): ");
    scanf("%f x %f", &widthArea3, &heightArea3);
    fflush(stdin);

    printf("\nA área total da casa é %0.2f", (widthArea1*heightArea1) + (widthArea2*heightArea2) + (widthArea3*heightArea3));

    return 0;
}