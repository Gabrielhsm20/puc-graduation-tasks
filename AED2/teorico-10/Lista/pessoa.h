#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
//====================================
#include <stdio.h>
#include <stdlib.h>
//====================================
typedef struct Pessoa{
  int codigo;
  char nome[100];
  int idade;
}Pessoa;
//====================================
void print_pessoa(Pessoa p){
  printf("codigo: %d, nome: %s, idade: %d\n",
  p.codigo, p.nome, p.idade);
}

Pessoa nova_pessoa(){
  Pessoa p;
  p.codigo = rand()%1000;
  sprintf(p.nome,"Pessoa %d", p.codigo);
  p.idade = 10;
  return p;
}



//====================================
#endif // PESSOA_H_INCLUDED