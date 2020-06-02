/*

Sabe-se que um cliente pode obter descontos ao comparar parafusos em uma loja. O preço de
cada parafuso é R$ 0,50, e os seguintes descontos podem ser aplicados:

Quantidades de Parafusos            Desconto
Entre 101 e 200                     10%
Entre 201 e 300                     20%
Entre 301 e 400                     30%
Acima de 401                        40% (desconto máximo)

Construa um algoritmo que recebe o número de parafusos desejados pelo cliente e
informados pelo usuário e determina o valor total da compra. Caso a quantidade seja menor
ou igual a zero, o sistema deverá mostrar uma mensagem informando que a quantidade é
inválida.

*/

#include <stdio.h>

int main(){
    int amount;
    float total, discount;

    // Exibe o comando na tela e atribui o valor inserido à váriavel
    printf("Digite a quantidade de parafusos que será comprada (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);

    // Verifica a quantidade inserida e retorna o valor a ser pago
    if(amount > 0){
        if(amount < 100){
            discount = 0;
        }else if(amount < 200){
            discount = 0.1;
        }else if(amount < 300){
            discount = 0.2;
        }else if(amount < 400){
            discount = 0.3;
        }else{
            discount = 0.4;
        }

        // Calcula o valor a ser pago
        total = amount*0.5*(1-discount);

        printf("Valor a ser pago: %0.2f (%0.2f%% de desconto)", total, discount*100);

    }else{
        printf("Quantidade inválida");
    }

    return 0;
}