/*
O Imperador Júlio César foi um dos principais nomes do Império Romano. Entre suas contribuições, temos um algoritmo de criptografia chamado "Ciframento de César". Segundo os historiadores, César utilizava esse algoritmo para criptografar as mensagens que enviava aos seus generais durante as batalhas. A ideia básica é um simples deslocamento de caracteres. Assim, por exemplo, se a chave utilizada para criptografar as mensagens for 3, todas as ocorrências do caractere 'a' são substituídas pelo caractere 'd', as do 'b' por 'e', e assim sucessivamente. Crie uma função iterativa que recebe uma string como parâmetro e retorna outra contendo a entrada de forma cifrada. Neste exercício, suponha a chave de ciframento três. Implemente um programa para executar sua função que receba várias linhas contendo strings e, para cada string, imprimir a a mensagem criptografada. A entrada termina com a leitura da palavra FIM. Você deve cifrar somente letras do alfabeto  (A até Z, a até z), os demais caracteres não serão cifrados. Se a chave é igual a 3,  'a' é substituído por 'd', então 'z' é substituído por 'c', pois o algoritmo anda de forma circular sobre o alfabeto (A até Z, a até z).

Entrada
    Lista de palavras, finalizada pela palavra "FIM".

Saída
    Mensagem criptografada de cada linha.

Exemplos de Entrada	
    O rato roeu a roupa do rei de roma
    FIM

Exemplos de Saída
    R udwr urhx d urxsd gr uhl gh urpd
*/

#include <stdio.h>

// Funcao recursiva que recebe como parametro um char frase e um int i referente a posicao
char *ciframentoCesar(char frase[], int i) {
    // Condicao de parada: verifica se o valor do caracter na posicao i e diferente de \0 (fim da frase)
    if(frase[i] != '\0') {
        // Se o caracter da posicao for diferente de espaco (ascii 32), soma a chave (3)
        if(frase[i] != ' ')
            frase[i] += 3;

        // Recursividade: chama a propria funcao incrementando o inteiro referente a posicao
        ciframentoCesar(frase, i+1);
    }else{
        // Determina o fim da frase na posicao i-1
        frase[i-1] = '\0';

        // Retorna a frase
        return frase;
    }
}

int main(void) {
    // Declaro as variaveis
    char frase[100];
    int i=0, fim = 0;

    // Loop enquanto nao se determinar o fim
    do {
        // Leio a proxima frase
        scanf("%[^\n]\n", &frase);
        
        // Verifico se esta frase e igual a "FIM" e, se sim, determino o fim e se encerra o loop
        if(strcmp(frase, "FIM") == 0){
            fim = 1;
        }else{
            // Exibe fase encriptada retornada pela funcao recursiva ciframentoCesar
            printf("%s\n", ciframentoCesar(frase, 0));
        }
    } while(!fim);

    return 0;
}
