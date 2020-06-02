/*

Um comerciante deseja fazer o levantamento do lucro das mercadorias que ele
comercializa. Para isto, mandou digitar uma linha para cada mercadoria com o código,
preço de compra e preço de venda das mesmas. Faça um algoritmo que determine e
escreva quantas mercadorias proporcionam lucro < 10%, 10% <= lucro <= 20% e lucro >
20%. Determine também e escreva o valor total de compra e de venda de todas as
mercadorias, assim como o lucro total. As entradas de dados devem ser finalizadas após
o usuário digitar um código negativo de produto.

*/

#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar variável booleana

int main() {
    // Variável booleana que define quando será finalizado o loop de acréscimos de mercadorias
    bool goOut = false;
    
    int merchandise = 1, // Variável que armazena a quantidade de mercadorias adicionadas
        lessThan10 = 0, // Variável que armazena a quantidade de mercadorias com lucro inferior à 10%
        between10And20 = 0, // Variável que armazena a quantidade mercadorias com lucro maior ou igual à 10% e menor ou igual à 20%
        moreThan20 = 0; // Variável que armazena a quantidade mercadorias com lucro superior à 20%

    float purchaseTotal = 0, // Variável que armazena o valor total comprado
          saleTotal = 0; // Variável que armazena o valor total vendido

    // Loop de acréscimo de mercadorias
    do {

        int code; // Variável que irá receber o código da mercadoria
        float purchase, sale, percentage; // Variáveis que irão receber o preço de compra, preço de venda e porcentagem de lucro

        // Condição para apenas exibir a opção de saída do loop quando se adicionar 1 ou mais mercadorias
        if(merchandise == 1){
            printf("Insira o codigo, preco de compra e preco de venda da mercadoria %i: ", merchandise);
        }else{
            printf("Insira o codigo, preco de compra e preco de venda da mercadoria %i ou -1 -1 -1 para exibir o resultado: ", merchandise);
        }
        scanf("%i %f %f", &code, &purchase, &sale);
        fflush(stdin);

        // Condição para contabilizar os dados inseridos apenas se o código for maior ou igual à 0
        if(code >= 0){
            merchandise++; // Adiciona +1 na variável que armazena a quantidade de mercadorias adicionadas

            percentage = (sale - purchase) * 100 / purchase; // Calcula a porcentagem de lucro

            // Condição para contabilizar a categoria do lucro de acordo com a porcentagem de lucro obtida
            if(percentage < 10){
                lessThan10++; // Soma 1 à variável que armazena a quantidade de lucros inferiores à 10%
            }else if(percentage >= 10 && percentage <= 20){
                between10And20++; // Soma 1 à variável que armazena a quantidade de lucros maiores ou iguais à 10% e menores ou iguais à 20%
            }else{
                moreThan20++; // Soma 1 à variável que armazena a quantidade de lucros superiores à 20%
            }

            purchaseTotal += purchase; // Soma o valor de compra desta mercadoria à variável que armazena o valor total de compra
            saleTotal += sale; // Soma o valor de venda desta mercadoria à variável que armazena o valor total de venda
        }

        /*
            Se for inserido pelo menos uma mercadoria e o código inserido for negativo se torna verdadeira
            a variável que define a opção de sair do loop de acréscimos de mercadorias
        */
        goOut = merchandise > 1 && code < 0 ? true : false;

    } while(!goOut); // Loop enquanto a variável goOut for falsa
    
    // Exibe o resultado de acordo com os dados inseridos
    printf("O valor total de compra foi %0.2f\n", purchaseTotal);
    printf("O valor total de venda foi %0.2f\n", saleTotal);
    printf("O valor total de lucro foi %0.2f\n", saleTotal - purchaseTotal);
    printf("%i mercadorias proporcionaram lucro menor que 10%%\n", lessThan10);
    printf("%i mercadorias proporcionaram lucro maior ou igual 10%% e menor ou igual 20%%\n", between10And20);
    printf("%i mercadorias proporcionaram lucro maior que 20%%\n", moreThan20);

    return 0;
}