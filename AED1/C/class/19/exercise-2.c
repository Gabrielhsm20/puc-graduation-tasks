#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char text[100];

    fp = fopen("exercise-2.txt", "w");
    if(!fp) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }

    printf("Digite o texto que deseja gravar no arquivo (Ex: Hello World!): ");
    gets(text);
    fflush(stdin);
    
    fprintf(fp, "%s", text);

    fclose(fp);

    return 0;
}