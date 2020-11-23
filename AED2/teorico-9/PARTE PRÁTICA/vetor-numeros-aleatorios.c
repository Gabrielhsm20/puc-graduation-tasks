#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define QNT 10

int somar(int *v) {
  int soma = 0;
  for(int i=0; i<QNT; i++) {
      soma += v[i];
  }

  return soma;
}

int main() {
  int num, *vet = (int *) malloc(QNT * sizeof(int));

  srand(time(NULL));

  printf("Numeros:\n");
  for(int i=0; i<QNT;i++){
    num = rand() % 100;
    vet[i] = num;
    printf("%i\n", num);
  }

  printf("\nSoma: %i", somar(vet));

  return 0;
}