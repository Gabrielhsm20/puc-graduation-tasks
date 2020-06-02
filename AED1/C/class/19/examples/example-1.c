#include <stdio.h>

int main(){
    FILE *arquivo;

    arquivo = fopen("example-1.txt", "w");

    if(arquivo == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        return 1;
    } 
    
    printf("Arquivo README criado com sucesso.\n");

    fclose(arquivo); 

    return 0;
}