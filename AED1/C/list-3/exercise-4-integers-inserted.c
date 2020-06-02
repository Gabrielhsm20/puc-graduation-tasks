/*

Crie uma nova versão para o programa anterior, de forma que o limite inferior e limite
superior sejam valores lidos. Utilize a estrutura de repetição FOR.

*/

#include <stdio.h>

int main(){
    int init,
        end,
        total = 0;

    printf("Insira um numero inteiro inicial (Ex: 10): ");
    scanf("%i", &init);
    fflush(stdin);

    printf("Insira um numero inteiro final (Ex: 1): ");
    scanf("%i", &end);
    fflush(stdin);

    // Verifica a ordem do loop (crescente/decrescente)
    if(init > end){
        // Loop para exibir e somar os números inteiros no intervalo inserido (decrescente)
        for(int i = init; i >= end; i--){
            printf("%i ", i);
            total += i;
        }
    }else{
        // Loop para exibir e somar os números inteiros no intervalo inserido (crescente)
        for(int i = init; i <= end; i++){
            printf("%i ", i);
            total += i;
        }
    }

    printf("= %i", total);

    return 0;
}