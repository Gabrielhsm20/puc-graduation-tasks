#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
//=====================================
typedef struct Pessoa{
  int id;
  char nome[100];
  int idade;
}Pessoa;
//=====================================
void print_pessoa(Pessoa p){
  printf("%d, %s, %d\n", p.id, p.nome, p.idade);
}
//=====================================
Pessoa nova_pessoa(){
  Pessoa p;
  
  p.id = rand()%1000;
  sprintf(p.nome,"Pessoa: %d", p.id);
  p.idade = rand()%100 + 15;

  return p;
}
//=====================================
Pessoa invalida_pessoa(){
  Pessoa p;
  
  p.id = -1;
  sprintf(p.nome,"Pessoa: %d", p.id);
  p.idade = 0;

  return p;
}



//=====================================
#endif // PESSOA_H_INCLUDED