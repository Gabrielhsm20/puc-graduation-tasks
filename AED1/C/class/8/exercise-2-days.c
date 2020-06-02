#include <stdio.h>

int main(){
    int day;

    printf("Insira o número de um dia da semana (sendo 1 para Domingo e 7 para Sábado): ");
    scanf("%i", &day);
    fflush(stdin);

    switch (day){
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("Dia útil");
            break;
        case 1:
        case 7:
            printf("Fim de semana");
            break;
        default:
            printf("Dia inválido");
            break;
    }

    return 0;
}