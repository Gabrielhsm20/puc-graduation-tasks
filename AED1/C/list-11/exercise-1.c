/*

Crie um programa que leia um arquivo TXT contendo em cada linha os valores de coordenadas X Y Z e retorne a soma das distâncias sequenciais entre os pontos. O nome do arquivo deverá ser informado pelo usuário.

Dica: crie struct e funções/procedimentos para organizar o seu código.

*/

#include <stdio.h>
#define N 4

struct Coordinates {
    int x;
    int y;
    int z;
};

int insertRecords(struct Coordinates coordinates[], FILE *fp){
    int sum = 0;

    for(int i = 0; i < N; i++) {
        printf("Digite as coordenadas X, Y e Z do ponto %i (Ex: 3 4 5): ", i+1);
        scanf("%i %i %i", &coordinates[i].x, &coordinates[i].y, &coordinates[i].z);
        fflush(stdin);

        fprintf(fp, "%i %i %i\n", coordinates[i].x, coordinates[i].y, coordinates[i].z);

        sum += abs(coordinates[i].y - coordinates[i].x) + abs(coordinates[i].z - coordinates[i].y);
    }

    return sum;
}

int main() {
    FILE *fp;
    char fileName[30];
    struct Coordinates coordinates[N];
    
    printf("Digite o nome e tipo do arquivo a ser criado/aberto (Ex: coord.txt): ");
    scanf("%s", &fileName);
    fflush(stdin);

    fp = fopen(fileName, "w");
    if(!fp) { printf("Erro na abertura do arquivo"); exit(0); }

    int sum = insertRecords(coordinates, fp);

    printf("A soma da distancia sequencial entre os pontos e %i", sum);

    fclose(fp);

    return 0;
}