#include <stdio.h>
#define N 3

struct Pessoas {
    int time;
    int day;
    int month;
    int year;
    char name[50];
};

void insertRecord(struct Pessoas pessoas[]) {
    for(int i = 0; i < N; i++) {
        int day, month, year;

        printf("Digite o nome da pessoa e a data de nascimento %i (Ex: Gabriel 01/01/2001): ", i+1);
        scanf("%s %i/%i/%i", &pessoas[i].name, &pessoas[i].day, &pessoas[i].month, &pessoas[i].year);
        fflush(stdin);

        pessoas[i].time = (pessoas[i].year * 12 * 30 * 24 * 60 * 60) + (pessoas[i].month * 30 * 24 * 60 * 60) + (pessoas[i].day * 24 * 60 * 60);
    }
}

int main() {
    int olderId = 0,
        youngerId = 0;

    struct Pessoas pessoas[N];
    insertRecord(pessoas);

    printf("REGISTROS:\n");
    for(int i = 0; i < N; i++) {
        printf("|\tID: %i\t|\tNOME: %s\t|\tDATA: %i/%i/%i\t|\n", i, pessoas[i].name, pessoas[i].day, pessoas[i].month, pessoas[i].year);
    
        if(i==0 || pessoas[i].time < pessoas[olderId].time)
            olderId = i;

        if(i==0 || pessoas[i].time > pessoas[youngerId].time)
            youngerId = i;
    }

    printf("\n\nO MAIS VELHO:\n");
    printf("|\tID: %i\t|\tNOME: %s\t|\tDATA: %i/%i/%i\t|\n", olderId, pessoas[olderId].name, pessoas[olderId].day, pessoas[olderId].month, pessoas[olderId].year);

    printf("\n\nO MAIS NOVO:\n");
    printf("|\tID: %i\t|\tNOME: %s\t|\tDATA: %i/%i/%i\t|\n", youngerId, pessoas[youngerId].name, pessoas[youngerId].day, pessoas[youngerId].month, pessoas[youngerId].year);

    return 0;
}