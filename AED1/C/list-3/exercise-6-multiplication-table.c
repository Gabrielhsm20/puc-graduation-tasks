/*

Faça um algoritmo que a tabulada relativa ao número 9 e seus multiplicando de 0 a 100.
Exemplo:
9 x 0 = 0
9 x 1 = 9
9 x 2 = 18
...
9 x 100 = 900

*/

#include <stdio.h>

int main(){
    int num = 9;

    // Loop onde a variável i crescente multiplica o 9 e exibe o resultado
    for(int i = 0; i <= 100; i++){
        printf("9 x %i = %i\n", i, 9*i);
    }    

    return 0;
}