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

import java.util.Scanner;

public class Main {
    // Metodo para remover os espacos da frase que recebe uma string frase, uma stringbulder newFrase, um int i e um int j
    public static StringBuilder removeSpace(String frase, StringBuilder newFrase, int i, int j) {
        // Declaro uma variavel auxiliar
        int aux;

        // Condicao de parada: verifica se i e menor que o numero de caracters da frase
        if(i < frase.length()){
            aux = frase.toLowerCase().charAt(i);
            // Verifica se o caracter da posicao "i" for diferente de 32 (espaco)
            if(aux != 32){
                // "Concateno" a nova frase o valor do caracter minusiculo da posicao "i"
                newFrase.append((char) aux);
                j++;
            }

            // Recursividade: chamo o proprio metodo incrementando o inteiro referente a posicao
            return Main.removeSpace(frase, newFrase, i+1, j);
        }

        // Retorno a nova frase
        return newFrase;
    }

    // Metodo para verificar se e palindromo que recebe uma stringbuilder newFrase, um int newFraseLength e um int i
    public static int isPalindromo(StringBuilder newFrase, int newFraseLength, int i) {
        // Condicao de parada: verifica se "i" e menor que o numero de caracters da frase
        if(i <= newFraseLength){
            // Verifica se o primeiro caracter e diferente do ultimo
            if(newFrase.charAt(i) != newFrase.charAt(newFraseLength - i)){
                // Retorna 0 (falso)
                return 0;
            }else{
                // Recursividade: chama o proprio metodo incrementando o inteiro referente a posicao
                return isPalindromo(newFrase, newFraseLength, i+1);
            }
        }else{
            // Retorna 1 (true), ja que nada foi retornado anteriormente, ou seja, e palindromo
            return 1;
        }
    }

    public static void main(String[] args) {
        // Declara variaveis
        String frase;
        StringBuilder newFrase;
        int newFraseLength, palindromo, fim = 0;

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
                // Atribuo o retorno do metodo removeSpace (frase sem espacos) para a variavel newFrase
                newFrase = Main.removeSpace(frase, newFrase, 0, 0);

                // Atribuo a quantidade de caracters a variavel newFraseLength
                newFraseLength = newFrase.length();

                // Verifico se a quantidade de caracter e igual a 1 e, se for, ja e um palindromo, ou entao chamo a funcao recursiva passando a frase, o numero de caracters e a posicao 0
                palindromo = newFraseLength == 1 ? 1 : Main.isPalindromo(newFrase, newFraseLength - 1, 0);
                
                // Exibe o resultado
                System.out.println((palindromo == 1) ? "SIM" : "NAO");
            }
        } while(fim == 0);
    }
}