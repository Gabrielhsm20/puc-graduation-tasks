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

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaro variaveis
        String frase;
        StringBuilder newFrase;
        int j, aux, palindromo, fim = 0;

        // Inicializo o scanner
        Scanner input = new Scanner(System.in);

        // Loop enquanto nao se determinar o fim
        do {
            // Leio a proxima linha e atribuo o valor a variavel frase
            frase = input.nextLine();
            // Inicializo a nova frase
            newFrase = new StringBuilder();

            // Verifico se esta frase e igual a "FIM" e, se sim, determino o fim e se encerra o loop
            if(frase.equals("FIM")){
                fim = 1;
            }else{
                // Define que e um palindromo
                palindromo=1;

                j=0;
                // Loop enquanto "i" for menor que a quantidade de letras da frase
                for(int i=0; i<frase.length(); i++) {
                    aux = frase.toLowerCase().charAt(i);
                    // Verifica se o caracter da posicao "i" for diferente de 32 (espaco)
                    if(aux != 32){
                        // Atribui a nova frase o valor do caracter minusiculo da posicao "i"
                        newFrase.append((char) aux);
                        j++;
                    }
                }
                j-=1;

                // Loop enquanto "x" for menor ou igual a "j"
                for(int x=0; x<=j; x++){
                    // Verifica se o primeiro caracter e diferente do ultimo
                    if(newFrase.charAt(x) != newFrase.charAt(j-x)){
                        // Define que nao e mais um palindromo
                        palindromo = 0;
                    }
                }

                // Exibe o resultado
                System.out.println((palindromo == 1) ? "SIM" : "NAO");
            }
        } while(fim == 0);
    }
}