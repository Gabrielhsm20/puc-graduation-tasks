#include <stdio.h>

int main(){
    float score;
    char discipline[30];

    printf("Digite a nota do aluno e a disciplina (Ex: 100 Matemática): ");
    scanf("%f %s", &score, &discipline);
    fflush(stdin);

    if(score >= 0 && score <= 100){

        if(score >= 60){
            printf("APROVADO em %s", discipline);
        }else{
            printf("REPROVADO em %s", discipline);
        }

    }else{
        printf("Nota inválida");
    }

    return 0;
}