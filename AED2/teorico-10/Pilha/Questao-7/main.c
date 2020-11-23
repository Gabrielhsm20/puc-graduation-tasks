#include <stdio.h>
#include "pilha.h"

int main(void) {
  int qnt;

  scanf("%i", &qnt);

  for(int i=0; i<qnt; i++) {
      Pilha pilha;
      bool incorrect = false;
      char expressao[100];
    
      create_pilha(&pilha);
      
      scanf("%s", &expressao);

      for(int j=0; j<strlen(expressao); j++) {
          if(expressao[j] == 40) {
              push(&pilha, expressao[j]);
          } else if(expressao[j] == 41) {
              if(is_empty(&pilha)) {
                  incorrect = true;
                  break;
              } else {
                  pop(&pilha);
              }
          }
      }
      if(incorrect || !is_empty(&pilha)) {
        printf("Expressão Matemática Incorreta\n");
      } else {
        printf("Expressão Matemática Correta\n");
      }
  }
  return 0;
}