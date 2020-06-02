/*

Calcular e escrever a idade média de uma turma de n alunos, sendo n um valor lido.

*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int totalStudents = 0,
        totalAge = 0;
    
    printf("Insira a quantidade de alunos da turma (Ex: 10): ");
    scanf("%i", &totalStudents);
    fflush(stdin);
    
    // Loop para solicitar as idades
    int age;
    for(int i = 1; i <= totalStudents; i++){
        // Solicita a idade do usuário
        printf("Insira a idade do estudante %i (Ex: 10): ", i);
        scanf("%i", &age);
        fflush(stdin);

        totalAge += age; // Soma a idade do estudante inserido neste loop aos demais
    }

    printf("A media de idade dos %i estudantes e: %f", totalStudents, (float) totalAge/totalStudents);

    return 0;
}