#include <stdio.h>
#define N 3

struct Pessoas {
    int age;
    char name[50];
};

void insertRecord(struct Pessoas pessoas[]) {
    for(int i = 0; i < N; i++) {
        printf("Digite a idade e o nome da pessoa %i (Ex: 20 Gabriel): ", i+1);
        scanf("%i %s", &pessoas[i].age, &pessoas[i].name);
        fflush(stdin);
    }
}

int main() {
    int olderId = 0;

    struct Pessoas pessoas[N];
    insertRecord(pessoas);

    printf("REGISTROS:\n");
    for(int i = 0; i < N; i++) {
        printf("|\tID: %i\t|\tNOME: %s\t|\tIDADE: %i\t|\n", i, pessoas[i].name, pessoas[i].age);
    
        if(i==0 || pessoas[i].age > pessoas[olderId].age)
            olderId = i;
    }
    
    printf("\n\nO MAIS VELHO:\n");
    printf("|\tID: %i\t|\tNOME: %s\t|\tIDADE: %i\t|\n", olderId, pessoas[olderId].name, pessoas[olderId].age);

    return 0;
}