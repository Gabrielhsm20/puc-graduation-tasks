/*

Acrescente no programa desenvolvido anteriormente a possibilidade do usuário digitar a
forma de pagamento. O usuário digita um código (1 a 4) e o sistema mostra a opção de
pagamento correspondente a esse código e aplica mais um desconto ao valor final da compra,
como segue:

Código Forma de Pagamento           Desconto
1 Dinheiro                          5%
2 Cartão Débito                     3%
3 Cartão Crédito                    0%
4 Boleto                            2%

Utilize a estrutura de controle de fluxo switch-case

*/

#include <stdio.h>

int main(){
    int amount, form;
    float total, discount1, discount2, discountTotal;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Digite a quantidade de parafusos que será comprada (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Digite a forma de pagamento: ");
    printf("\n1 | Dinheiro");
    printf("\n2 | Cartão de débito");
    printf("\n3 | Cartão de crédito");
    printf("\n4 | Boleto");
    printf("\n: ");
    scanf("%i", &form);
    fflush(stdin);

    // Verifica se a quantidade inserido é inválida
    if(amount > 0){
        // Verifica a quantidade inserida e retorna o valor do desconto 1
        if(amount < 100){
            discount1 = 0;
        }else if(amount < 200){
            discount1 = 0.1;
        }else if(amount < 300){
            discount1 = 0.2;
        }else if(amount < 400){
            discount1 = 0.3;
        }else{
            discount1 = 0.4;
        }

        // Verifica a forma de pagamento e retorna o valor do desconto 2
        switch (form){
            case 1:
                discount2 = 0.05;
                break;
            case 2:
                discount2 = 0.03;
                break;
            case 3:
                discount2 = 0;
                break;
            case 4:
                discount2 = 0.02;
                break;
            default:
                discount2 = 0;
                break;
        }

        // Calcula o desconto total
        discountTotal = discount1+discount2;

        // Calcula o valor a ser pago
        total = amount*0.5*(1-discountTotal);

        printf("Valor a ser pago: %0.2f (%0.2f%% de desconto)", total, discountTotal*100);

    }else{
        printf("Quantidade inválida");
    }

    return 0;
}