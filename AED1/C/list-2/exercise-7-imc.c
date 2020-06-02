/*

Construa um algoritmo que, a partir do peso e altura informados pelo usuário, calcule e
apresente o IMC de uma pessoa e a sua classificação conforme tabela a seguir:
- abaixo de 18,5: Abaixo do peso
- entre 18,6 e 24,9: Peso ideal
- entre 25,0e 29,9: Levemente acima do peso
- entre 30,0 e 34,9: Obesidade grau I
- entre 35,0 e 39,9: Obesidade grau II (severa)
- acima de 40: Obesidade III (mórbida)

*/

#include <stdio.h>

int main(){
    float weight, height, imc;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira o peso (Ex: 60): ");
    scanf("%f", &weight);
    fflush(stdin);

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Insira a altura (Ex: 1.7): ");
    scanf("%f", &height);
    fflush(stdin);

    imc = weight / pow(height, 2);

    printf("\n");

    // Verifica e exibe a classificação do IMC
    if(imc < 18.5){
        printf("IMC: %0.2f\nClassificação: abaixo do peso", imc);
    }else if(imc < 24.9){
        printf("IMC: %0.2f\nClassificação: peso ideal", imc);
    }else if(imc < 29.9){
        printf("IMC: %0.2f\nClassificação: levemente acima do peso", imc);
    }else if(imc < 34.9){
        printf("IMC: %0.2f\nClassificação: obesidade grau I", imc);
    }else if(imc < 39.9){
        printf("IMC: %0.2f\nClassificação: obesidade grau II", imc);
    }else{
        printf("IMC: %0.2f\nClassificação: obesidade mórbida", imc);
    }

    return 0;
}