/*

Faça um programa que calcule a média de consumo de combustível de um veículo. O usuário
deve informar o KM inicial (ex. 13.000 km), o KM final (ex. 15.000 km) e quantos litros foram
gastos no percurso.


*/

#include <stdio.h>

int main(){
    float initialKm, finalKm, liters;

    printf("Insira a quilometragem inicial do carro (Ex: 1000): ");
    scanf("%f", &initialKm);
    fflush(stdin);

    printf("Insira a quilometragem final do carro (Ex: 2000): ");
    scanf("%f", &finalKm);
    fflush(stdin);

    printf("Insira a quantidade de combustível gasto no percurso (Ex: 100): ");
    scanf("%f", &liters);
    fflush(stdin);

    printf("\nA performance do carro é %0.2f km/litro", (finalKm - initialKm) / liters);

    return 0;
}