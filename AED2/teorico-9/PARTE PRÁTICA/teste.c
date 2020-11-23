#include <stdio.h>

int main() {
    int i = 10, *p, *q;

    // p = i
    // p = *i
    // p = *i - Erro de compilação
    // i = **p
    // i = *p
    // i = *p
    // p = *i
    // q = **p
    // q = **p
    // q = *p
    // q = *p

    return 0;
}