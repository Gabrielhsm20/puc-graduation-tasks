#include <stdio.h>
#include <string.h>

#include "pilha.h"

int main(void) {
  int exit = 0;
  char digito;
  
  Pilha pilha;
  create_pilha(&pilha);

  do {
    printf("Digite um caracter ou 0 para sair: ");
    scanf("%c", &digito);
    fflush(stdin);

    if(digito == 48) {
      exit = 1;
    } else {
      push(&pilha, digito);
    }
  } while(!exit);

  print_pilha(&pilha);
  
  return 0;
}