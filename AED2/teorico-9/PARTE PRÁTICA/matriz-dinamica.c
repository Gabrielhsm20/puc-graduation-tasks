#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 5
#define COLUNA 5

int main() {
  int num,
      maior, xMaior, yMaior,
      menor, xMenor, yMenor,
      posicaoMenor,
      *vet = (int *) malloc(LINHA * COLUNA * sizeof(int));

  srand(time(NULL));

  for(int i=0; i<LINHA; i++) {
    for(int j=0; j<COLUNA; j++) {
      num = rand() % 100;
      vet[i*COLUNA + j] = num;
      printf("%i\t", num);

      if((i == 0 && j == 0) || num > maior) {
        maior = num;
        xMaior = i + 1;
        yMaior = j + 1;
      }

      if((i == 0 && j == 0) || num < menor) {
        menor = num;
        xMenor = i + 1;
        yMenor = j + 1;
      }
    }
    printf("\n");
  }

  printf("\nMaior: %i Posicao: %i x %i", maior, xMaior, yMaior);
  printf("\nMenor: %i Posicao: %i x %i", menor, xMenor, yMenor);

  return 0;
}