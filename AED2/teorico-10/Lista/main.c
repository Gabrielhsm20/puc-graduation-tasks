#include <stdio.h>
#include <string.h>
#include "lista.h"
//#include "lista_estatica.h"
//#include "lista_dinamica.h"
// #include "lista_dupla.h"

// Requisitos
// CRUD Pessoa - Create, Read, Update, Delete
// Pessoa (Código, Nome, Idade)

int menu(){
  
  int opcao = 0;
  printf("\n====> PESSOAS <=====\n");
  printf("1 - Listar pessoas\n");
  printf("2 - Adicionar nova Pessoa\n");
  printf("3 - Editar dados de uma Pessoa\n");
  printf("4 - Apagar uma Pessoa\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);

  return opcao;
}

int main(void) {

  Lista estoque;
  Pessoa paux;
  int op = 0, id;
  create_lista(&estoque, 10);

do{

  op = menu();

  switch(op){

    case 1:
      print_lista(&estoque);
      break;

    case 2:
      paux = nova_pessoa();
      paux.codigo = estoque.qtd+1;
      add_lista(&estoque, paux);
      break;

    case 3:
          printf("\nDigite o codigo da pessoa: ");
          scanf("%d", &id);
          paux = nova_pessoa();
          paux.codigo = id; 
          update_lista(&estoque, paux);
    break;

    case 4:
          printf("\nDigite o codigo da pessoa: ");
          scanf("%d", &id);
          delete_lista(&estoque, id);
    break;
  }
}while(op != 0);



  return 0;
}