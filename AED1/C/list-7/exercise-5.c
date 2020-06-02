/*

A distância de Manhattan entre dois pontos é dado pela soma das diferenças absoluta entre suas dimensões.

= | x 1 − x 2 | + | y 1 − y 2 |

Exemplo:
Ponto 1) x1=3, y1=2
Ponto 2) x2=2, y2=5

Neste caso, a distância será = |3-2| + |2-5| = 1 + 3 = 4

Construa um procedimento recebe as coordenadas (x,y) de um ponto P e um valor n. O procedimento deverá calcular e retornar por referência a soma das distâncias do ponto P para outros n pontos a serem gerados aleatoriamente.
Construa também uma função main que solicita ao usuário o ponto inicial e o valor de n, faz a chamada do procedimento passando os parâmetros, e depois mostra a soma das distâncias.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

/*
    Descrição: procedimento que executa a soma da distancia dos pontos cartesianos passados por referência com outros pontos aleatorios
    Entradas (tipos e para que servem): endereço das variaveis n, x, y e distance para ser feito a operação e retornado o resultado por referência
    Saída (tipo e valor): -
*/
void distancePoints(int *n, int *x, int *y, int *distance) {
    int sum = 0;

    // Loop enquanto i for menor que n
    for(int i = 0; i < *n; i++) {
        // Declarando e atribuindo pontos cartesianos aleatórios
        int x2 = rand() % 100,
            y2 = rand() % 100;

        // Somando a distância à x e y
        sum += fabs(*x - x2) + fabs(*y - y2);
    }
    
    // Passando o resultado por referência
    *distance = sum;
}

int main() {
    int n, x, y, distance; 

    // Comando que solicita que o usuário insira um ponto cartesiano
    printf("Digite um ponto cartesiano x y (Ex: 10 5): ");
    scanf("%i %i", &x, &y);
    fflush(stdin);

    // Comando que solicita que o usuário insira a quantidade de comparações
    printf("Digite a quantidade de pontos a serem comparados (Ex: 10): ");
    scanf("%i", &n);
    fflush(stdin);

    // Chamada do procedimento para realizar a soma dos pontos cartesianos com outros N gerados
    distancePoints(&n, &x, &y, &distance);

    // Exibição das informações finais do programa
    printf("A soma das distancias do ponto cartesiano x = %i e y = %i com outros %i pontos aleatorios e %i", x, y, n, distance);

    return 0;
}