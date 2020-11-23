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

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaro as variaveis
        String frase;
        StringBuilder newFrase;
        int fim = 0, letra, aux;

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
                // Loop enquanto i for menor que o numero de caracters da frase
                for(int i=0; i<frase.length(); i++){
                    // Atribuo na variavel "aux" o valor do caracter da posicao i
                    aux = frase.charAt(i);

                    // Verifico se o caracter vale 32 (espaco) e, se nao, somo a chave (3)
                    letra = aux != 32 ? (int) aux + 3 : aux;

                    // "Concateno" o caracter na nova frase
                    newFrase.append((char) letra);
                }
                
                // Exibo a nova frase
                System.out.println(newFrase);
            }
        } while(fim == 0);

        // Encerro o scanner
        input.close();
    }
}