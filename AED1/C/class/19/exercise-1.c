#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;

    fp = fopen("exercise-1.txt", "w");
    if(!fp) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }

    for(int i = 1; i <= 10; i++) {
        fprintf(fp, (i==1) ? "%i" : "\n%i", i);
    }

    fclose(fp);

    return 0;
}