/*

Um determinado material radioativo perde metade de sua massa a cada 50 segundos.
Este tempo é chamado na físico-química de MEIA-VIDA.
Dada a massa inicial, em gramas, faça um algoritmo que utilizando estrutura de repetição, determine o tempo necessário para que essa massa se torne menor que 0.5 gramas. Ao final do algoritmo escreva a massa inicial e o tempo calculado em horas, minutos e segundos.

*/

#include <stdio.h>

/*
    Descrição: função que recebe um numero e retorna o tempode meia vida em segundos
    Entradas (tipos e para que servem): um valor inteiro para ser calculado
    Saída (tipo e valor): um valor inteiro referente ao tempo de meia vida em segundos
*/
int halfLife(float num) {
    int time = 0;
    
    // Loop enquanto num for maior que 0.5
    do {
        // Incrementa o tempo que posteriormente será multiplicado por 50
        time++;

        // Divide o num por 2
        num /= 2;
    } while(num > 0.5);

    // Retorna o tempo em segundos
    return time * 50;    
}

int main() {
    float number;

    // Comando que solicita que o usuário insira um numero para ser calculado
    printf("Digite uma massa (em gramas) a ser calculada o tempo de meia vida (Ex: 10): ");
    scanf("%f", &number);
    fflush(stdin);

    // Transformação de segundos em horas, minutos e segundos
    int halfLifeTime = halfLife(number),
        hours = halfLifeTime / (60*60),
        minutes = (halfLifeTime - hours) / 60,
        secconds = (halfLifeTime - hours*60*60 - minutes*60);

    printf("O tempo necessario para que a massa de %0.2f gramas se torne menor que 0.5 gramas e %i horas, %i minutos e %i segundos", number, hours, minutes, secconds);

    return 0;
}