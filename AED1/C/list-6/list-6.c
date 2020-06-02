/*

1. Crie um procedimento função que recebe três números e retorne por referência o maior e o menor.

2. Crie um procedimento que recebe 3 números como parâmetro de entrada, calcule e retorne e a média dos números usando parâmetro por referência.

3. Crie um procedimento que recebe dois valores boleanos (A e B) e retorne por referência o valor verdade da operação ⌐ (A ^ B).

4. Declare 5 variáveis (números inteiros) na função main e faça a leitura dos valores (scanf).
    Após isso, crie um procedimento que recebe os 5 números inteiro por referência e realize alterações de seus valores, deslocando os valores da esquerda para a direita. Exemplo:
    
    Dados lidos originalmente: a=5, b=9, c=1, d=6, e=19
    Dados atualizados: a=19, b=5, c=9, d=1, e=6
    
    O procedimento também deverá imprimir os resultados dessas trocas conforme ilustrado a seguir:
    
    NOME_VARIAVEL       ENDEREÇO        VALOR ANTIGO      VALOR NOVO
    a                   0000fff1        5                   19
    b                   0000fff2        9                   5
    c                   0000fff3        1                   9
    d                   0000fff4        6                   1
    e                   0000fff5        19                  6

5. Faça um algoritmo que declare uma variável e mostre o valor, endereço e tamanho na memória para cada um dos seguintes tipos: char, int, float, double, int *, char *, int *, float *, double *.
    Exemplo de formato de saída do seu programa:
    O Endereço do char ___ é 0x_______ . Essa variável ocupa ___ bytes.
    O Endereço do int ___ é 0x_______ . Essa variável ocupa ___ bytes.
    O Endereço do float ___ é 0x_______ . Essa variável ocupa ___ bytes.
    O Endereço do double ___ é 0x_______ . Essa variável ocupa ___ bytes.
    
    Dica: use a função sizeof(variável) para obter o tamanho da variável em bytes.

6. Adicione comando para imprimir o valor das variáveis no código a seguir, execute e veja o que
acontece. O que você observa? Qual sua explicação para as saídas?

*/

#include <stdio.h>
#include "functions.h"

int main() {
    int exercise;

    printf("Escolha o exercicio que deseja executar:");
    printf("\n1 | Retorna o maior e menor numero");
    printf("\n2 | Retorna a media aritmetica");
    printf("\n3 | Retorna o valor verdade");
    printf("\n4 | Retorna os numeros em posicoes diferentes");
    printf("\n5 | Retorna o endereco e tamanho de diferentes tipos de variaveis");
    printf("\n6 | Retorna os misterios");
    printf("\n0 | Para sair");
    printf("\n: ");
    scanf("%i", &exercise);
    fflush(stdin);

    if(exercise == 0 || exercise == 1 || exercise == 2 || exercise == 3 || exercise == 4 || exercise == 5 || exercise == 6 || exercise == 7 || exercise == 8) {
        if(exercise == 0) {
            
            printf("Até logo!");

        }else if(exercise == 1) {

            int num1, num2, num3,
                higher, smallest;

            printf("Insira tres numeros inteiros (Ex: 1 2 3): ");
            scanf("%i %i %i", &num1, &num2, &num3);
            fflush(stdin);

            higherAndSmallestNumber(&num1, &num2, &num3, &higher, &smallest);

            printf("Dentre os numeros %i, %i e %i, o maior e %i e o menor e %i", num1, num2, num3, higher, smallest);

        }else if(exercise == 2) {

            int num1, num2, num3, average;

            printf("Insira tres numeros inteiros (Ex: 1 2 3): ");
            scanf("%i %i %i", &num1, &num2, &num3);
            fflush(stdin);

            arithmeticAverage(&num1, &num2, &num3, &average);

            printf("A media aritmetica dos numeros %i, %i e %i e %i", num1, num2, num3, average);

        }else if(exercise == 3) {

            int val1, val2, result;

            printf("Insira dois valores booleanos (Ex: 1 0): ");
            scanf("%i %i", &val1, &val2);
            fflush(stdin);

            nANDOperation(&val1, &val2, &result);

            printf("O valor verdade da operacao !(%i ^ %i) e %i", val1, val2, result);

        }else if(exercise == 4) {

            int num1, num2, num3, num4, num5;

            printf("Insira cinco numeros inteiros (Ex: 1 2 3 4 5): ");
            scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
            fflush(stdin);

            shiftValues(&num1, &num2, &num3, &num4, &num5);

            printf("VARIAVEL    |   ENDERECO    |   VAL. ANTIGO    |    VAL. NOVO");
            printf("\nnum1        |    %p   |        %i         |   %i", &num1, num2, num1);
            printf("\nnum2        |    %p   |        %i         |   %i", &num2, num3, num2);
            printf("\nnum3        |    %p   |        %i         |   %i", &num3, num4, num3);
            printf("\nnum4        |    %p   |        %i         |   %i", &num4, num5, num4);
            printf("\nnum5        |    %p   |        %i         |   %i", &num5, num1, num5);

        }else if(exercise == 5) {

            char var1 = 'M';
            // char *var2 = ...;

            int var3 = 10;
            // int *var4 = ...;

            float var5 = 10.5;
            // float *var6 = ...;

            double var7 = 10.1010;
            // double *var8 = ...;

            printf("\nVariavel: var1\nTipo: char\nEndereco: %p\nValor: %c\nEspaco: %f bytes\n", &var1, var1, sizeof(var1));
            // printf("\nVariavel: var2\nTipo: char *\nEndereco: %p\nValor: %c\nEspaco: %f bytes\n", &var2, var2, sizeof(var2));
            
            printf("\nVariavel: var3\nTipo: int\nEndereco: %p\nValor: %i\nEspaco: %f bytes\n", &var3, var3, sizeof(var3));
            // printf("\nVariavel: var4\nTipo: int *\nEndereco: %p\nValor: %i\nEspaco: %f bytes\n", &var4, var4, sizeof(var4));
            
            printf("\nVariavel: var5\nTipo: float\nEndereco: %p\nValor: %f\nEspaco: %f bytes\n", &var5, var5, sizeof(var5));
            // printf("\nVariavel: var6\nTipo: float *\nEndereco: %p\nValor: %f\nEspaco: %f bytes\n", &var6, var6, sizeof(var6));

            printf("\nVariavel: var7\nTipo: double\nEndereco: %p\nValor: %d\nEspaco: %f bytes\n", &var7, var7, sizeof(var7));
            // printf("\nVariavel: var8\nTipo: double *\nEndereco: %p\nValor: %d\nEspaco: %f bytes\n", &var8, var8, sizeof(var8));

        }else if(exercise == 6) {

            printf("Misterio 1: ");
            misterio1(7);
            
            printf("\nMisterio 2: ");
            misterio2(11);

            /*
                O que você observa?
                    No misterio1, o número 7 passado como parâmetro foi atribuido
                    ao valor da variável x declarada no procedimento que
                    anteriormente possivelmente poderia ter um valor qualquer
                    que pode ser denominado "lixo".

                    Já no misterio2, por mais que o numero 11 foi passado como
                    parâmetro, este valor não foi atribuído à variável "y"
                    declarada dentro do procedimento que ficou sem um atribuição
                    e, portanto, ao exibir seu valor, foi mostrado um valor
                    qualquer (lixo).
                
                Qual sua explicação para as saídas?
                    As partições da memória tem constantemente conteúdo gravado
                    e regravado (gravado por cima), e após o término da
                    utilização, nem sempre o conteúdo que ali ficou é limpado,
                    então, quando outro programa vai para utilizar, este conteudo
                    pode ainda estar existindo.
            */

        }
    }

    return 0;
}