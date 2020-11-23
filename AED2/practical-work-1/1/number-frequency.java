/*
Neste problema sua tarefa será ler vários números e em seguida dizer quantas vezes cada número aparece na entrada de dados, ou seja, deve-se escrever cada um dos valores distintos que aparecem na entrada por ordem crescente de valor.

Entrada
    A entrada contém apenas 1 caso de teste. A primeira linha de entrada contem um único inteiro N, que indica a quantidade de valores que serão lidos para X (1 ≤ X ≤ 2000) logo em seguida. Com certeza cada número não aparecerá mais do que 20 vezes na entrada de dados.

Saída
    Imprima a saída de acordo com o exemplo fornecido abaixo, indicando quantas vezes cada um deles aparece na entrada por ordem crescente de valor.

Exemplos de Entrada
    7
    8   10  8   260 4   10  10

Exemplos de Saída
    4 aparece 1 vez(es)
    8 aparece 2 vez(es)
    10 aparece 3 vez(es)
    260 aparece 1 vez(es)
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaro as variaveis
        int qnt,
            num,
            vet[] = new int[2000];

        // Inicializo o scanner
        Scanner input = new Scanner(System.in);

        // Pego o proximo inteiro
        qnt = input.nextInt();

        // Atribuo o valor 0 a todas posicoes do vetor
        for(int i=0; i<vet.length; i++)
            vet[i] = 0;

        // Loop para ler os proximos numeros e incrementar na sua posicao 
        for(int i=0; i<qnt; i++){
            num = input.nextInt();
            vet[num]++;
        }

        // Loop para exibir o numero de aparicoes onde o valor for diferente de zero
        for(int i=0; i<vet.length; i++)
            if(vet[i] > 0)
                System.out.printf("%d aparece %d vez(es)\n", i, vet[i]);

        // Finalizo o scanner
        input.close();
    }
}