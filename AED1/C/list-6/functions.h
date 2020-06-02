/*
    Exercício: 1
    Descrição: procedimento que recebe três números e atribui o valor do maior e menor às variaveis
    Entradas (tipos e para que servem): três valores inteiros para comparar e duas variáveis maior e menor que receberão o resultado
    Saída (tipo e valor): -
*/
void higherAndSmallestNumber(int *num1, int *num2, int *num3, int *higher, int *smallest) {

    if(*num1 >= *num2 && *num1 >= *num3) {
        *higher = *num1;
        *smallest = *num2 >= *num3 ? *num3 : *num2;
    }else if(*num2 >= *num1 && *num2 >= *num3){
        *higher = *num2;
        *smallest = *num1 >= *num3 ? *num3 : *num1;
    }else{
        *higher = *num3;
        *smallest = *num1 >= *num2 ? *num2 : *num1;
    }
}

/*
    Exercício: 2
    Descrição: procedimento que recebe três números e atribui o valor da média à variavel average
    Entradas (tipos e para que servem): três valores inteiros para calcular a média e uma variável média que receberá o resultado
    Saída (tipo e valor): -
*/
void arithmeticAverage(int *num1, int *num2, int *num3, int *average) {
    *average = (*num1 + *num2 + *num3) / 3;
}

/*
    Exercício: 3
    Descrição: procedimento que recebe dois valores booleanos e atribui o valor do !(val1 ^ val2) à variavel result
    Entradas (tipos e para que servem): três valores inteiros para comparar e duas variáveis maior e menor
    Saída (tipo e valor): -
*/
void nANDOperation(int *val1, int *val2, int *result) {
    *result = !(*val1 && *val2);
}

/*
    Exercício: 4
    Descrição: procedimento que recebe cinco numeros inteiros e muda a sequência
    Entradas (tipos e para que servem): cinco valores inteiros a serem reordenados
    Saída (tipo e valor): -
*/
void shiftValues(int *num1, int *num2, int *num3, int *num4, int *num5) {
    int aux = *num2;

    *num2 = *num1;
    *num1 = *num5;
    *num5 = *num4;
    *num4 = *num3;
    *num3 = aux;
}

/*
    Exercício: 6.1
    Descrição: procedimento que recebe um valor inteiro e o exibe na tela
    Entradas (tipos e para que servem): um valor inteiro a ser exibido
    Saída (tipo e valor): -
*/
void misterio1(int xval) {
    int x;
    x = xval;
    /* Imprima o endereço e valor de x aqui */
    printf("%i", x);
}

/*
    Exercício: 6.2
    Descrição: procedimento que exibe uma variável sem valor atribuído
    Entradas (tipos e para que servem): um valor inteiro sem necessidade
    Saída (tipo e valor): -
*/
void misterio2(int nada) {
    int y;
    /* Imprima o endereço e valor de y aqui */
    printf("%i", y);
}