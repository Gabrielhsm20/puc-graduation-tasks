/*
Um palíndromo é uma palavra, frase ou qualquer outra sequência de unidades  que tenha a propriedade de poder ser lida tanto da direita para a esquerda como da esquerda para a direita. Num palíndromo, normalmente são desconsiderados os sinais ortográficos (diacríticos ou de pontuação), assim como o espaços entre palavras.

Crie uma função RECURSIVA que recebe uma string como parâmetro e retorna VERDADEIRO (true) se essa string é um palíndromo, ou FALSO (false), caso contrário. Implemente um programa para executar sua função que receba várias linhas contendo strings e, para cada string, imprimir a palavra SIM, caso seja uma string, ou a palavra NÃO, caso não seja um palíndromo. A entrada termina com a leitura da palavra FIM.

Entrada
    Uma lista de palavras, finalizando com a palavra FIM

Saída
    Impressão de SIM ou NAO, se a string  é ou não palíndromo.

Exemplos de Entrada	Exemplos de Saída
    Amor em roma        NAO
    O bolo do lobo      SIM
    Subi no onibus      SIM
    FIM
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funcao para remover os espacos da frase que recebe um char frase, um char newFrase, um int i e um int j
char *removeSpace(char frase[], char newFrase[], int i, int j) {
    // Condicao de parada: verifica se i e menor que o numero de caracters da frase - 1
    if(i<strlen(frase) - 1){
        // Verifica se o caracter da posicao "i" for diferente de 32 (espaco)
        if(frase[i] != 32){
            // Atribui a nova frase o valor do caracter minusiculo da posicao "i"
            newFrase[j] = tolower(frase[i]);
            j++;
        }
        
        // Recursividade: chama a propria funcao incrementando o inteiro referente a posicao
        removeSpace(frase, newFrase, i+1, j);
    }else{
        // Retorna a nova frase (sem espacos)
        return newFrase;
    }
}

// Funcao para verificar se e palindromo que recebe um char newFrase, um int fraseLength e um int i
int isPalindromo(char newFrase[], int fraseLength, int i) {
    // Condicao de parada: verifica se "i" e menor que o numero de caracters da frase
    if(i <= fraseLength){
        // Verifica se o primeiro caracter e diferente do ultimo
        if(newFrase[i] != newFrase[fraseLength - i]){
            // Retorna 0 (falso)
            return 0;
        }else{
            // Recursividade: chama a propria funcao incrementando o inteiro referente a posicao
            isPalindromo(newFrase, fraseLength, i+1);
        }
    }else{
        // Retorna 1 (true), ja que nada foi retornado anteriormente, ou seja, e palindromo
        return 1;
    }
}

int main(void) {
    // Declara variaveis
    char frase[100], newFrase[100];
    int newFraseLength, palindromo, fim = 0;

    // Loop enquanto nao se determinar o fim
    do {
        // Leio a proxima frase
        scanf("%[^\n]\n", &frase);

        // Loop para "limpar" o vetor newFrase
        for(int i=0; i<100; i++)
            newFrase[i] = 0;

        // Verifico se esta frase e igual a "FIM" e, se sim, determino o fim e se encerra o loop
        if(strcmp(frase, "FIM") == 0){
            fim = 1;
        }else{
            // Copio o retorno da funcao removeSpace (frase sem espacos) para a variavel newFrase
            strcpy(newFrase, removeSpace(frase, newFrase, 0, 0));

            // Atribuo a quantidade de caracters a variavel newFraseLength
            newFraseLength = strlen(newFrase);

            // Verifico se a quantidade de caracter e igual a 1 e, se for, ja e um palindromo, ou entao chamo a funcao recursiva passando a frase, o numero de caracters e a posicao 0
            palindromo = newFraseLength == 1 ? 1 : isPalindromo(newFrase, newFraseLength - 1, 0);

            // Exibe o resultado
            printf((palindromo) ? "SIM\n" : "NAO\n");
        }
    } while(!fim);

    return 0;
}