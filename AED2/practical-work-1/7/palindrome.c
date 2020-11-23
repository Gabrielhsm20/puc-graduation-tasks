/*
Um palíndromo é uma palavra, frase ou qualquer outra sequência de unidades  que tenha a propriedade de poder ser lida tanto da direita para a esquerda como da esquerda para a direita. Num palíndromo, normalmente são desconsiderados os sinais ortográficos (diacríticos ou de pontuação), assim como o espaços entre palavras.

Crie uma função iterativa que recebe uma string como parâmetro e retorna VERDADEIRO (true) se essa string é um palíndromo, ou FALSO (false), caso contrário. Implemente um programa para executar sua função que receba várias linhas contendo strings e, para cada string, imprimir a palavra SIM, caso seja uma string, ou a palavra NÃO, caso não seja um palíndromo. A entrada termina com a leitura da palavra FIM.

Entrada
    Uma lista de palavras, finalizando com a palavra FIM

Saída
    Impressão de SIM ou NAO, se a string  é ou não palíndromo.

Exemplos de Entrada	Exemplos de Saída
    Amor em roma            NAO
    O bolo do lobo          SIM
    Subi no onibus          SIM
    FIM
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // Declaro variaveis
    char frase[100], newFrase[100];
    int j, palindromo, fim = 0;

    // Loop enquanto nao se determinar o fim
    do {
        // Leio a proxima frase
        scanf("%[^\n]\n", &frase);

        // Verifico se esta frase e igual a "FIM" e, se sim, determino o fim e se encerra o loop
        if(strcmp(frase, "FIM") == 0){
            fim = 1;
        }else{
            // Define que e um palindromo
            palindromo=1;

            j=0;
            // Loop enquanto "i" for menor que a quantidade de letras da frase - 1
            for(int i=0; i<strlen(frase) - 1; i++) {
                // Verifica se o caracter da posicao "i" for diferente de 32 (espaco)
                if(frase[i] != 32){
                    // Atribui a nova frase o valor do caracter minusiculo da posicao "i"
                    newFrase[j] = tolower(frase[i]);
                    j++;
                }
            }
            j-=1;

            // Loop enquanto "x" for menor ou igual a "j"
            for(int x=0; x<=j; x++)
                // Verifica se o primeiro caracter e diferente do ultimo
                if(newFrase[x] != newFrase[j-x])
                    // Define que nao e mais um palindromo
                    palindromo = 0;
            
            // Exibe o resultado
            printf((palindromo) ? "SIM\n" : "NAO\n");
        }
    } while(!fim);

    return 0;
}