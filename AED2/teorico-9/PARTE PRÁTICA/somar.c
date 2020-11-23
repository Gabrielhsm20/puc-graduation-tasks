#include <stdio.h>

int somar(int *v) {
    int soma = 0;

    for(int i=0; i<3; i++)
        soma += *v+i;

    return soma;
}

int main() {
    int *vetor[] = {1,2,3},
    soma = somar(&vetor);

    printf("%d", soma);

    return 0;
}