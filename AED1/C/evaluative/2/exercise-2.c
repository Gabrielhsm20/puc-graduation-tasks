/*
Crie um procedimento que recebe uma matriz de tamanho Nx2 com N pontos cartesianos e faça a inversão desses pontos
*/

#include <stdio.h>

/*
    Descrição: Procedimento que recebe um vetor e seu tamanho, e faz o loop para preenchimento
    Entradas (tipos e para que servem): o vetor e um inteiro referente ao tamanho do vetor
*/
void insertNumbers(int mat[][2], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Insira o valor do ponto X=%i Y=%i: ", i+1, j+1);
            scanf("%i", &mat[i][j]);
            fflush(stdin);
        }
    }
}

/*
    Descrição: Procedimento que recebe uma matriz e seu tamanho, faz o loop e exibe os valores com linhas invertidas
    Entradas (tipos e para que servem): a matriz e um inteiro referente ao tamanho da matriz
*/
void showInvertLines(int mat[][2], int size) {
    for(int i = size-1; i >= 0; i--){
        for(int j = 0; j < 2; j++)
            printf("%i ", mat[i][j]);

        printf("\n");
    }
}

int main() {
    int size;

    // Solicita que o usuário insira o numero de linhas da matriz
    printf("Digite o numero de linhas da matriz (Ex: 10): ");
    scanf("%i", &size);
    fflush(stdin);

    // Declara a matriz
    int mat[size][2];

    // Solicita o preenchimento da matriz
    printf("Preencha a matriz\n");
    insertNumbers(mat, size);

    // Exibe matriz original digitada pelo usuário
    printf("\nMatriz original:\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 2; j++)
            printf("%i ", mat[i][j]);

        printf("\n");
    }

    // Exibe a matriz com as linhas invertidas
    printf("\nMatriz invertida:\n");
    showInvertLines(mat, size);

    return 0;
}