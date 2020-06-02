/*

Construa um algoritmo onde o usuário informar uma data (dia, mês e ano) e verifica se é
uma data válida em 2020. Exemplos:
-30/08/2020 é uma data válida em 2019.
-31/Fev/2005 não é uma data válido, pois não fevereiro não tem 31 dias e o ano é diferente
de 2020.


*/

#include <stdio.h>

int main(){
    int day, month, year;

    // Exibe o comando na tela e atribui os valores inseridos às váriaveis
    printf("Insira uma data separada por espaço (Ex: 10 10 2010): ");
    scanf("%i %i %i", &day, &month, &year);
    fflush(stdin);

    printf("\n");

    /*
    Verifica se a data é inválida:
        Primeira linha:
            Verifica se o dia é menor ou igual à zero ou maior que 31
            Verifica se o mês é menor ou igual à zero ou maior que 12
            Verifica se o ano é diferente de 2020

        Segunda linha:
            Caso o dia seja 31, verifica se o mês corresponde à um mês que não tem 31 dias
        
        Terceira linha:
            Caso o dia seja maior que 29, verifica se o mês é fevereiro
    */
    if(
        day <= 0 || day > 31 || month <= 0 || month > 12 || year != 2020 ||
        (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
        (day > 29 && month == 2)
    ){
        printf("Data inválida em 2020");
    }else{
        printf("Data válida em 2020");
    }

    return 0;
}