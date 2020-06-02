/*

Na lista anterior, foi elaborado um programa que proveu as funcionalidades de uma
calculadora para as quatro operações aritméticas. Elas foram oferecidas através de um menu
e a opção do usuário foi tratada através da instrução switch. Crie uma nova versão para a
calculadora. Nela, acrescente ao programa a possibilidade de serem realizados vários
cálculos. Para isto, após a escrita do resultado de cada operação, o fluxo de execução deverá
voltar à escrita do menu. Desta forma, o menu deverá ser alterado acrescentando a ele uma
nova opção: sair do programa. Esta deverá ser a primeira opção do menu. Quando
selecionada, a mensagem “Obrigado por usar este programa” deverá ser escrita e o
programa finalizado. Caso contrário, tratar a operação aritmética selecionada.

*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    float num1, num2;
    char operation;
    bool goOut = false;

    // Loop enquanto o usuário não sair do programa
    do{
        printf("Insira uma das operacoes matematicas abaixo:");
        if(goOut){ printf("\nX | Sair do programa"); } // Exibe a opção de sair caso tenha feito o primeiro loop
        printf("\n+ | Adicao");
        printf("\n- | Subtracao");
        printf("\n/ | Divisao");
        printf("\n* | Multiplicacao");
        printf("\n: ");
        scanf("%c", &operation);
        fflush(stdin);

        // Verifica se o usuário deseja sair do programa
        if(goOut && operation == 'X'){
            printf("Obrigado por usar este programa");
        }else{
            goOut = true; // Autoriza a saída após o primeiro loop

            // Verifica se a operação é inválida
            if(operation != '+' && operation != '-' && operation != '/' && operation != '*'){
                printf("Operacao invalida\n\n");
            }else{
                
                // Como a operacao é válida, solicita os números 
                printf("Insira dois numeros (Ex: 10 10): ");
                scanf("%f %f", &num1, &num2);
                fflush(stdin);

                // Verifica a operação inserida e exibe o resultado
                switch (operation){
                    case '+':
                        printf("\nResultado: %f\n\n", num1+num2);
                        break;
                    case '-':
                        printf("\nResultado: %f\n\n", num1-num2);
                        break;
                    case '*':
                        printf("\nResultado: %f\n\n", num1*num2);
                        break;
                    case '/':
                        printf("\nResultado: %f\n\n", num1/num2);
                        break;
                    default:
                        printf("Erro interno");
                        break;
                }
            }
        }
    
    } while(operation!=0);

    return 0;
}