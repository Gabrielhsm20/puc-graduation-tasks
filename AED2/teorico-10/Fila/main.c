#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pessoa.h"

/*
FILA DE PESSOAS
PESSOA (ID, NOME, IDADE)
CRUD - criar, enfileirar, desenfileirar, tamanho, listar, destroy
*/

void Clonar(Fila *f, Fila *clonada) {
  int pos = (f->inicio+1)%MAX;

  for(int i = 0; i < f->tam; i++){
    enqueue(clonada, f->dados[pos]);
    pos = (pos+1)%MAX;
  }
}

int menu(){

  int opcao;
  printf("\n =====> FILA DE ATENDIMENTO <===== \n");
  printf("1 - Entrar na fila\n");
  printf("2 - Verificar a fila\n");
  printf("3 - Chamar o próximo da fila\n");
  printf("4 - Clonar fila\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");

  scanf("%d", &opcao);

  return opcao;
}

int main(void) {
  
  int op;
  Fila fila;
  Pessoa paux;
  create_fila(&fila);

  Fila clonada;
  create_fila(&clonada);

  do{
    //system("clear");//system("cls");
    op = menu();

    switch(op){
      case 1:
        paux = nova_pessoa();
        enqueue(&fila, paux);
      break;
      case 2:
        print_fila(&fila);
      break;
      case 3:
        paux = dequeue(&fila);
        print_pessoa(paux);
      break;
      case 4:
        Clonar(&fila, &clonada);
        printf("FILA:\n");
        print_fila(&fila);
        printf("CLONADA:\n");
        print_fila(&clonada);
      break;
    }

  }while(op!=0);

  //system("PAUSE");


  return 0;
}