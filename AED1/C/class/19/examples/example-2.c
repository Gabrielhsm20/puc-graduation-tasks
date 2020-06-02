#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char primeiro_nome[100],ultimo_nome[100];
    
    fp = fopen("example-2.txt","w");
    if(!fp){ printf( "Erro na abertura do arquivo"); exit(0); }

    printf("Digite seu primeiro nome: ");
    gets(primeiro_nome);
    
    printf("Digite seu ultimo nome: ");
    gets(ultimo_nome);

    fprintf(fp, "%s, %s",ultimo_nome,primeiro_nome);

    fclose(fp);

    return 0;
}