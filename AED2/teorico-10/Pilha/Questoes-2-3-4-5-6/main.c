#include <stdio.h>
#include "pilha_estatica.h"
//===========================================
void RetiraImpares(Pilha *original){
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  while(!is_empty(original)){
    int d = pop(original);
    if(d%2 == 0)
      push(&pilha_aux, d);
  }

  while(!is_empty(&pilha_aux)){
    int d = pop(&pilha_aux);
    push(original, d);
  }
}
//===========================================
void Clonar(Pilha *original, Pilha *clonada) {
  int aux[original->topo];
  for(int i=original->topo-1; i>=0; i--)
    aux[i] = original->dados[i];

  for(int i=0; i<original->topo; i++)
    push(clonada, aux[i]);
}
//===========================================
void Concatenar(Pilha *pilha1, Pilha *pilha2, Pilha *concatenada) {
  int aux1[pilha1->topo],
      aux2[pilha2->topo];

  for(int i=pilha2->topo-1; i>=0; i--)
    aux2[i] = pilha2->dados[i];
  for(int i=pilha1->topo-1; i>=0; i--)
    aux1[i] = pilha1->dados[i];

  for(int i=0; i<pilha2->topo; i++)
    push(concatenada, aux2[i]);
  for(int i=0; i<pilha1->topo; i++)
    push(concatenada, aux1[i]);
}
//===========================================
void Inverter(Pilha *original) {
  int tam = original->topo,
      aux[original->topo];
  for(int i=original->topo-1; i>=0; i--) {
    aux[original->topo - i] = original->dados[i];
    pop(original);
  }

  for(int i=0; i<tam; i++)
    push(original, aux[i]);
}
//===========================================
int main(void) {
  int option;

  printf("Selecione uma operacao:\n");
  printf("1 | Retira Impares\n");
  printf("2 | Clonar Pilha\n");
  printf("3 | Concatenar Pilhas\n");
  printf("4 | Inverter Pilha\n");
  printf(": ");
  scanf("%i", &option);
  fflush(stdin);

  if(option == 1) {
      // RETIRA IMPARES
      Pilha pilha;
      create_pilha(&pilha);
      for(int i=0; i<5;i++)
        push(&pilha, rand()%100);
      print_pilha(&pilha);

      RetiraImpares(&pilha);
      print_pilha(&pilha);
    
  } else if(option == 2) {
      // CLONA PILHA
      Pilha pilha;
      create_pilha(&pilha);
      for(int i=0; i<5;i++)
        push(&pilha, rand()%100);
      print_pilha(&pilha);

      Pilha pilhaClonada;
      create_pilha(&pilhaClonada);
      Clonar(&pilha, &pilhaClonada);
      print_pilha(&pilhaClonada);
    
  } else if(option == 3) {
      // CONCATENAR PILHA
      Pilha pilha1;
      create_pilha(&pilha1);
      for(int i=0; i<5;i++)
        push(&pilha1, rand()%100);
      print_pilha(&pilha1);

      Pilha pilha2;
      create_pilha(&pilha2);
      for(int i=0; i<5;i++)
        push(&pilha2, rand()%100);
      print_pilha(&pilha2);

      Pilha pilhaConcatenada;
      create_pilha(&pilhaConcatenada);
      Concatenar(&pilha1, &pilha2, &pilhaConcatenada);
      print_pilha(&pilhaConcatenada);
    
  } else if(option == 4) {
      // INVERTER PILHA
      Pilha pilha;
      create_pilha(&pilha);
      for(int i=0; i<5;i++)
        push(&pilha, rand()%100);
      print_pilha(&pilha);

      Inverter(&pilha);
      print_pilha(&pilha);

  } else {
      printf("Opção inválida");
  }

  return 0;
}