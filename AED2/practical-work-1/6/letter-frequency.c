/*
Neste problema estamos interessados na frequência das letras em uma dada linha de texto.

Especificamente, deseja-se saber qual(is) a(s) letra(s) de maior frequência do texto, ignorando o “case sensitive”, ou seja maiúsculas ou minúsculas (sendo mais claro, “letras” referem-se precisamente às 26 letras do alfabeto).

Entrada
    A entrada contém vários casos de teste. A primeira linha contém um inteiro N que indica a quantidade de casos de teste. Cada caso de teste consiste de uma única linha de texto. A linha pode conter caracteres “não letras”, mas é garantido que tenha ao menos uma letra e que tenha no máximo 200 caracteres no total.

Saída
    Para cada caso de teste, imprima uma linha contendo a(s) letra(s) que mais ocorreu(ocorreram) no texto em minúsculas (se houver empate, imprima as letras em ordem alfabética).

Exemplos de Entrada	e Saída
    3
    Computers account for only 5% of the country's commercial electricity consumption.          co
    Input                                                                                       inptu
    frequency letters                                                                           e
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    // Declaro variaveis
    char frase[200];
    int i,
        qnt,
        maior,
        count[26];

    // Leio a quantidade de frases
    scanf("%i\n", &qnt);

    // Loop quando "a" for menor que a quantidade de frases
    for(int a=0; a<qnt; a++) {
        // Loop para "limpar" o vetor "frase"
        for(int x=0; x<=200; x++)
            frase[x] = 0;
        
        // Leio a frase
        scanf("%[^\n]\n", &frase);

        // Loop para "limpar" o vetor "count"
        for(int b=0; b<=26; b++)
            count[b] = 0;

        i = 0;
        // Loop enquanto o valor do caracter na posicao i e diferente de \0 (fim da frase)
        while(frase[i] != '\0') {
            // Verifica se o caracter na posicao equivale a uma letra do alfabeto
            if(tolower(frase[i]) >= 97 && tolower(frase[i]) <= 122)
                // Incrementa um na posicao referente a letra
                count[(int) tolower(frase[i]) - 96]++;
            
            // Incrementa a posicao a se verificar
            i++;
        }

        maior = 0;
        // Loop enquanto "d" for menor que 26
        for(int d=0; d<=26; d++)
            // Verifica se as aparicoes da letra na frase e maior que 0
            if(count[d] > 0)
                // Verifica se a quantidade de aparicoes e a maior
                if(count[d] > maior)
                    // Se for a maior, atualiza o valor da variavel "maior"
                    maior = count[d];

        // Verifica se a variavel "maior" e maior que 0 (se existe letra na frase)
        if(maior > 0) {
            // Loop enquanto "d" for menor que 26
            for(int d=0; d<=26; d++)
                // Condicao que verifica se a letra e a maior
                if(count[d] == maior)
                    // Exibe as letras que mais apareceram
                    printf("%c", d+96);
            
            printf("\n");
        }  
    }

    return 0;
}
