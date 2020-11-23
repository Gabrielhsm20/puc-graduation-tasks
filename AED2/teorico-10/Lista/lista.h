#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
//=================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pessoa.h"
//=================================================
typedef struct Lista{
  Pessoa *dados;
  int MAX;
  int qtd;
}Lista;
//=================================================
void create_lista(Lista *l, int n){
  l->MAX = n;
  l->dados = (Pessoa*)malloc(n*sizeof(Pessoa));
  l->qtd = 0;
}
//=================================================
bool add_lista(Lista *l, Pessoa p){

  if(l->qtd == l->MAX){
    printf("\nLista cheia!\n");
    return false;
  }

  l->dados[l->qtd++] = p;

  return true;
}
//=================================================
void print_lista(Lista *l){

  for(int i=0; i<l->qtd; i++)
    print_pessoa(l->dados[i]);

}
//=================================================
bool update_lista(Lista *l, Pessoa p){

  if(p.codigo <= 0 || p.codigo > l->qtd){
    printf("Pessoa nao encontrada na lista");
    return false;
  }

  l->dados[p.codigo-1] = p;
  return true;
}
//=================================================
bool delete_lista(Lista *l, int id){

  if(id <= 0 || id > l->qtd){
    printf("Produto nao encontrado na lista");
    return false;
  }

  for(int i=id; i < l->qtd;i++){
      l->dados[i-1] = l->dados[i];
      l->dados[i-1].codigo--;
  }

  l->qtd--;
  return true;
}
//=================================================




//=================================================

#endif // FILA_H_INCLUDED