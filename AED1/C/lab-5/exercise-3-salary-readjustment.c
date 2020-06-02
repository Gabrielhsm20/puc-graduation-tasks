#include <stdio.h>
#include <string.h>

int main(){
    int code;
    float salary;

    printf("Digite o código e o salário atual do funcionário (Ex: 1 2000): ");
    scanf("%i %f", &code, &salary);
    fflush(stdin);

    if(code < 1 || code > 5){
        printf("Erro.");
    }else{
        float newSalary;
        char role[30];
        
        if(code == 1){
            strcpy(role, "Escriturário");
            newSalary = salary * 1.5;
        }else if(code == 2){
            strcpy(role, "Secretário");
            newSalary = salary * 1.35;
        }else if(code == 3){
            strcpy(role, "Caixa");
            newSalary = salary * 1.2;
        }else if(code == 4){
            strcpy(role, "Gerente");
            newSalary = salary * 1.1;
        }else{
            strcpy(role, "Diretor");
            newSalary = salary;
        }

        printf("Código: %i\nCargo: %s\nSalário atual: %f\nNovo salário: %f", code, role, salary, newSalary);
    }

    return 0;
}