/*
Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, mostrando esta informação.

Entrada
    A primeira linha de entrada contem um único inteiro N (1 < N < 1000), indicando o número de elementos que deverão ser lidos em seguida para o vetor X[N] de inteiros. A segunda linha contém cada um dos N valores, separados por um espaço.

Saída
    A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço e do menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:” seguido de um espaço e da posição do vetor na qual se encontra o menor valor lido, lembrando que o vetor inicia na posição zero.

Exemplos de Entrada
    10
    1 2 3 4 -5 6 7 8 9 10

Exemplos de Saída
    Menor valor: -5
    Posicao: 4
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaro as variaveis
        int qnt,
            num,
            pos=0,
            vet[] = new int[1000];

        // Inicializo o scanner
        Scanner input = new Scanner(System.in);

        // Pego o proximo inteiro
        qnt = input.nextInt();

        // Loop para ler os proximos numeros e salvar no vetor, além de atribuir a posição na variável "pos" caso seja o primeiro loop ou o numero seja menor que o numero atualmente salvo nesta variavel
        for(int i=0; i<qnt; i++) {
            num = input.nextInt();
            vet[i] = num;
            
            // Salva a posição na variavel "pos" caso seja o primeiro loop ou o numero lido seja menor que o numero da posicao salvo na variavel "pos"
            if(i==0 || num<vet[pos]){
                pos = i;
            }
        }

        // Imprime os dados
        System.out.println("Menor valor: "+ vet[pos]);
        System.out.print("Posicao: "+ pos);

        // Finalizo o scanner
        input.close();
    }
}