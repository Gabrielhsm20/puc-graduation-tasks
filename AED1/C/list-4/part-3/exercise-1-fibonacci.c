/*

O Matemático Italiano Leonardo de Pisa nasceu na Itália por volta de 1175 e ficou conhecido
como Fibonacci (Filho de Bonaccio). A partir da publicação do livro Liber Abacci, (livro do
Ábaco) em 1202, Fibonacci tornou-se famoso, principalmente devido aos inúmeros temas
desenvolvidos nesse trabalho. Nele aparecem estudos sobre o clássico problema envolvendo
populações de coelhos, o qual foi a base para o estabelecimento da célebre sequência (números)
de Fibonacci, como segue:
F = 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 ...

*/

#include <stdio.h>

int main(){
    int amount;

    printf("Insira a quantidade de elementos a serem exibidos (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);

    int pre2 = 0,
        pre1 = 0,
        num;

    // Loop para exibir a quantidade requerida pelo usuário
    for (int i = 0; i < amount; i++) {
        // Atribui valor 0 para a primeira exibição e 1 para a segunda, após isso começa somar os dois anteriores
        num = i == 0 ? 0 : pre2 < 1 ? 1 : pre2 + pre1;

        // Atribui o valor do último à variável do pnultimo
        pre2 = pre1;

        // Atribui o valor do número atual à variável do último
        pre1 = num;

        printf("%i ", num);
    }

    return 0;
}