#include <stdio.h>

int main(){
    float num1, num2;
    int operation;

    do{
        printf("Insira uma das operações matemáticas abaixo:");
        printf("\n1 | Adição");
        printf("\n2 | Subtração");
        printf("\n3 | Divisão");
        printf("\n4 | Multiplicação");
        printf("\n0 | Sair");
        printf("\n: ");
        scanf("%i", &operation);
        fflush(stdin);

        if(operation == 0){
            printf("Saindo do programa");
        }else{
            printf("Insira dois números (Ex: 10 10): ");
            scanf("%f %f", &num1, &num2);
            fflush(stdin);

            if(operation == 1){
                printf("Resultado: %f", num1+num2);
            }else if(operation == 2){
                printf("Resultado: %f", num1-num2);
            }else if(operation == 3){
                printf("Resultado: %f", num1*num2);
            }else if(operation == 4){
                printf("Resultado: %f", num1/num2);
            }else{
                printf("Operação inválida");
            }
        }
    
    }while(operation!=0);

    return 0;
}