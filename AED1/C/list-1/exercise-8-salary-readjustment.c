/*

Faça um programa que calcula o novo valor do salário de um funcionário. O usuário informa o
salário atual (ex. 3.100,00) e o percentual do reajuste (ex. 4,2 %).

*/

#include <stdio.h>

int main(){
    float salary, readjustment;

    printf("Insira o salário (Ex: 1000): ");
    scanf("%f", &salary);
    fflush(stdin);

    printf("Insira a porcentagem de reajuste (Ex: 10.5): ");
    scanf("%f", &readjustment);
    fflush(stdin);

    printf("\nO salário após o reajuste será %0.2f", salary * (1 + (readjustment / 100)));

    return 0;
}