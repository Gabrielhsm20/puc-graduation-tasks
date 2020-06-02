/*

Calcular e escrever a idade média de uma turma de n alunos, sendo n um valor lido.

*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int totalStudents = 0,
        totalAge = 0;
    bool goOut = false;

    // Loop enquanto o usuário não solicitar a média
    int age;
    do{
        totalStudents++; // Aumenta a quantidade de estudantes

        // Solicia a idade do usuário
        printf("Insira a idade do estudante %i (Ex: 10)", totalStudents);
        
        // Após inserir 2 ou mais estudantes se torna possível solicitar a média e, portanto, exibe esta informação
        if(totalStudents > 2){ printf(" ou 0 para exibir a media"); }
        
        printf(": ");
        scanf("%i", &age);
        fflush(stdin);

        // Verifica se o usuário deseja ver a média e se o total de estudante é maior que 2
        if(age == 0 && totalStudents > 2){
            goOut = true; // Indica a saida do loop
            totalStudents--; // Remove o estudante que seria inserido neste loop mas que não foi
        }else{
            totalAge += age; // Soma a idade do estudante inserido neste loop aos demais
        }
    } while(!goOut);

    printf("A media de idade dos %i estudantes e: %f", totalStudents, (float) totalAge/totalStudents);

    return 0;
}