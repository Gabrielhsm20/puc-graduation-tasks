/*
Dados três valores X, Y e Z, verificar se eles podem ser os comprimentos dos lados de um triângulo e, se forem, verificar se é um triângulo equilátero, isósceles ou escaleno. Se eles não formarem um triângulo, escrever a mensagem "NAO FORMA UM TRIANGULO". Considere as seguintes propriedades:

O comprimento de cada lado em um triângulo é menor que a soma dos outros dois lados;

Equilátero: tem os comprimentos dos três lados iguais;
Isósceles: tem os comprimentos de dois lados iguais;
Escaleno: tem os comprimentos dos três lados diferentes.

Entrada
    Três valores reais que representam os três lados de um triângulo.

Saída
    Impressão do tipo de triângulo, ou a mensagem "NAO FORMA UM TRIANGULO", caso os lados não formem um triângulo.

Exemplos de Entrada	e Saída
    3 4 5       ESCALENO
    3 4 4       ISOSCELES
    4 4 4       EQUILATERO
    8 3 3       NAO FORMA UM TRIANGULO
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaro variáveis
        int num1, num2, num3;

        // Inicializo o scanner
        Scanner input = new Scanner(System.in);

        // Leio os tres proximos numeros referente aos laods do triangulo
        num1 = input.nextInt();
        num2 = input.nextInt();
        num3 = input.nextInt();

        // Condicao de existencia do triangulo
        if(
            (num2 - num3) < num1 && (num2 + num3) > num1 &&
            (num1 - num3) < num2 && (num1 + num3) > num2 &&
            (num2 - num1) < num3 && (num2 + num1) > num3
        ) {
            // Verifica a classificacao do triangulo
            if(num1 == num2 && num1 == num3) {
                System.out.print("EQUILATERO");
            } else if(
                num1 == num2 && num1 != num3 ||
                num1 == num3 && num1 != num2 ||
                num2 == num3 && num2 != num1
            ) {
                System.out.print("ISOSCELES");
            } else {
                System.out.print("ESCALENO");
            }
        } else {
            System.out.print("NAO FORMA UM TRIANGULO");
        }

        // Encerro o scanner
        input.close();
    }
}