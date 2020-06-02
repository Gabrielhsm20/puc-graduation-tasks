/*
Construa uma função que recebe dois vetores e retorne a soma dos elementos comuns aos dois vetores. Exemplo:
V1[] = {12, 6, 3, 90, 12}
v2[] = {0, -1, 3, 9, 6, 4}
Elementos comuns: 3 e 6. A função deverá retornar 9 (soma dos 2 elementos).
Crie também uma função main que permita a chamada da função criada após o usuário digitar valores dos vetores. 
*/

#include <stdio.h>

/*
    Descrição: Função que verifica se o número passado via parâmetro existe no vetor passado via parâmetro
    Entradas (tipos e para que servem): um inteiro a ser procurado, o vetor e um inteiro referente ao tamanho do vetor
    Saída (tipo e valor): um valor inteiro, sendo o numero encontrado ou 0 se não encontrar
*/
int commonNumbers(int num, int vect[], int size) {
    for(int i = 0; i < size; i++)
        if(vect[i] == num)
            return num;
    
    return 0;
}

/*
    Descrição: Procedimento que recebe um vetor e seu tamanho, e faz o loop para preenchimento
    Entradas (tipos e para que servem): o vetor e um inteiro referente ao tamanho do vetor
*/
void insertNumbers(int vect[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &vect[i]);
        fflush(stdin);
    }
}

int main() {
    int size;

    // Solicita que o usuário insira o tamanho dos vetores
    printf("Digite o tamanho dos vetores (Ex: 10): ");
    scanf("%i", &size);
    fflush(stdin);

    // Declara os vetores
    int vect1[size],
        vect2[size];
    
    // Solicita o preenchimento do vetor 1
    printf("Preencha o vetor 1\n");
    insertNumbers(vect1, size);

    // Solicita o preenchimento do vetor 2
    printf("\nPreencha o vetor 2\n");
    insertNumbers(vect2, size);

    // Declara a variável soma atribuindo o valor 0
    int sum = 0;

    // Loop para verificar e somar os numeros do vetor 1 que existem no vetor 2 (ou 0 caso não exista)
    for(int i = 0; i < size; i++)
        sum += commonNumbers(vect1[i], vect2, size);
    
    // Condição que verifica se a soma foi realizada e exibe o resultado
    if(sum == 0){
        printf("\nNao ha elementos em comum");
    }else{
        printf("\nA soma dos elementos comum e %i", sum);
    }

    return 0;
}