#include <stdio.h>
#include <math.h>

int main(){
    int dayA, monthA, yearA;
    int dayB, monthB, yearB;

    printf("Digite a data atual (Ex: 10/10/2010): ");
    scanf("%i/%i/%i", &dayA, &monthA, &yearA);
    fflush(stdin);

    printf("Digite a data de aniversário (Ex: 10/10/2010): ");
    scanf("%i/%i/%i", &dayB, &monthB, &yearB);
    fflush(stdin);

    int years = yearA - yearB;
    int months = (years * 12) + monthA;
    int days = (months * 30) + dayA;
    int weaks = days/7;

    if(monthB > monthA || (monthB == monthA && dayB > dayA)){ years--; }

    printf("Idade:\n- dias: %i\n- semanas: %i\n- meses: %i\n- anos: %i", days, weaks, months, years);

    return 0;
}