/*

Um número é primo se ele for divisível apenas por ele mesmo e por 1. O número 11 é
primo pois é divisivel apenas por 11 e por 1. Já o número 9 não é primo, pois é divisível
por 9, 3 e 1.

Construa uma função que recebe um número inteiro n e retorne o maior número primo
até n. Por exemplo: se o usuário digitar 21, a função deverá retornar 19 pois esse é maior
número primo até n=21.

Crie também uma função main que permita a chamada da função criada após o usuário
digitar o valor de n. Após a função retornar o seu valor, mostre para o usuário se o
número é primo ou não.

*/

#include <stdio.h>

/*
    Descrição: função que recebe um numero e retorna ele mesmo, caso seja primo, ou o primo mais próximo
    Entradas (tipos e para que servem): um valor inteiro para ser verificado
    Saída (tipo e valor): um valor inteiro referente ao próprio numero da entrada, caso este seja primo, ou o primo mais proximo
*/
int verifyNumber(int num) {
    int returnNumber = num; // Variavel que recebe o número que será retornado

    // Loop para verificar se o número é divisivel apenas por 1 e por ele mesmo
    for(int i = 2; i < num; i++) {
        /*
            Se o número for divisivel por algum numero entre 1 e ele mesmo quer dizer que ele não é primo
            Então inicia se uma recursividade para pegar o primo mais próximo
        */
        if(num % i == 0) {
            returnNumber = verifyNumber(num-1); // Recursividade informada logo acima
        }
    }

    // Retorna o valor da variável returnNumber
    return returnNumber;
}

int main() {
    int number, // Variavel que recebera o valor inserido
        returnNumber; // Variavel que recebera o valor retornado pela funcao

    // Comando que solicita que o usuário insira um numero para ser verificado
    printf("Digite um numero para saber se ele e primo ou para obter o maior primo ate este numero (Ex: 20): ");
    scanf("%i", &number);
    fflush(stdin);

    // Atribuição do valor retornado pela função à variável returnNumber
    returnNumber = verifyNumber(number);

    /*
        Verifica se o valor retornado é o mesmo que o valor inserido.
        Se sim, o valor inserido é primo e então exibe o proprio valor
        Se não, o valor inserido não é primo e então exibe o propiro valor e o primo mais próximo
    */
    if(number == returnNumber){
        printf("O numero %i inserido e primo", number);
    }else{
        printf("O numero %i inserido nao e primo. O primo mais proximo e %i", number, returnNumber);
    }

    return 0;
}