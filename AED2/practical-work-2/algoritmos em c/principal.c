#include "geracao.h"

#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"

int main() {
    clock_t t;
    double cpu_time_used;

    int n = 50000;

    // printf("Tamanho do vetor: ");
    // scanf("%i", &n);
    // fflush(stdin);

    int *vet = (int*) malloc(n*sizeof(int));

    aleatorio(vet, n);
    
    t = clock();
    
    // bolha(vet, n);
    // countingsort(vet, n);
    // heapsort(vet, n);
    // insercao(vet, n);
    // mergesort(vet, n);
    // quicksort(vet, n);
    // selecao(vet, n);
    // shellsort(vet, n);
    
    t = clock() - t;

    free(vet);

    cpu_time_used = (t / (double) CLOCKS_PER_SEC) * 1000;

    printf("\nTempo: %f ms\n", cpu_time_used);

    system("pause");
    return 0;
}