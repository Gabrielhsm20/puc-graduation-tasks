/*
Crie um procedimento recursivo que recebe dois vetores de caracteres (char[30]) como parâmetro e copie o conteúdo do primeiro de forma invertida para o segundo. A cópia deverá ser feita manipulando os caracteres individualmente, sem uso de funções especiais para cópia de string.
Crie também uma função main e demais implementações que permitam a chamada do procedimento criado após o usuário digitar os dois nomes. 
*/

#include <stdio.h>
#define N 30

/*
    Descrição: Procedimento que recebe duas strings e atribui à segundo o valor invertido da primeira
    Entradas (tipos e para que servem): dois char strings para serem manipuladas, um inteiro com o tamanho da primeira string e um inteiro para auxiliar na recursividade
*/
void invertStrings(char string1[], char string2[], int size, int i) {
    // Operador ternário que atribui o valor "\0" quando a variável auxiliar i igual à variável size, caso contrário atribui a letra referente à posição size-1-i
    string2[i] = i == size ? string1[size] : string1[size-1-i];

    // Condição (de parada) que verifica se a variável auxiliar i é menor ou igual à variável size
    if(i <= size)
        // Chama o procedimento novamente acrescentando 1 à variável auxiliar i
        invertStrings(string1, string2, size, i+1);
}

int main() {
    // Declara as variáveis char para as duas strings
    char string1[N],
         string2[N];

    // Solicita ao usuário que insira uma palavra para ser invertida
    printf("Digite uma palavra que deseja inverter (Ex: CARRO): ");
    scanf("%s", &string1);
    fflush(stdin);

    // Declara a variável que receberá o valor referente ao tamanho da palavra inserida pelo usuário
    int size = 0;

    // Loop que conta a quantidade de letras tem a palavra inserida pelo usuário
    for(int i = 0; i < N && string1[i] != '\0'; i++)
        size++;

    // Chama o procedimento que irá atribuir à variável string2 o valor invertido da string1
    invertStrings(string1, string2, size, 0);

    // Exibe o resultado
    printf("\nPalavra original: %s\nPalavra invertida: %s", string1, string2);

    return 0;
}