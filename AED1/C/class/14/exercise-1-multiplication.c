#include <stdio.h>

int multiplication(int num1, int num2, int i) {
    int aux = 0;

    if(i < num2){
        aux = num1 + multiplication(num1, num2, i++);
    }

    return aux;
}

int main() {

    int num1 = 3, num2 = 4;
    printf("A multiplicacao de %i por %i e igual a %i", num1, num2, multiplication(num1, num2, 0));

    return 0;
}