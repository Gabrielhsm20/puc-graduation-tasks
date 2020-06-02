/*

Construa um algoritmo que mostre os números impares de 100 a 110. Utilize estrutura de
repetição com teste no início (while)

*/

#include <stdio.h>

int main(){
    int i = 100,
        end = 110;

    // Loop para encontrar os números impares no intervalo de 100 à 110
    while(i < end){
        // Verifica se o número em questão à ímpar, exibe e pula para o próximo ímpar
        if(i % 2 != 0){
            printf("%i\n", i);
            i+=2;
        }else{
            i++;
        }
    }

    return 0;
}