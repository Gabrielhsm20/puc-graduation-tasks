/*
    Exercise: 1
    Descrição: função que recebe três números inteiros e retorna a divisao do primeiro pelo segundo tendo o terceiro como auxiliar
    Entradas (tipos e para que servem): três valores inteiro para serem calculados
    Saída (tipo e valor): um valor inteiro referente ao quociente da divisão
*/
int division(int num1, int num2, int quotient) {
    // Se num1 for maior ou igual à num2, realiza a subtração de num1-num2 e aumenta 1 no quociente
    if(num1 >= num2){
        // Recursividade para incrementar o quociente enquanto a for maior que b
        quotient = division(num1-num2, num2, quotient+1);
    }

    // Retorna o quociente
    return quotient;
}

/*
    Exercise: 2
    Descrição: função que recebe dois números inteiros e retorna a quantidade de algarismos do primeiro tendo o segundo como auxiliar
    Entradas (tipos e para que servem): dois valores inteiro para serem calculados
    Saída (tipo e valor): um valor inteiro referente ao número de algarismos
*/
int countLength(int num, int length) {
    // Se a divisao de num por 10 for diferente de 0, realiza a divisão e aumenta 1 na contagem de algarismos
    if(num / 10 != 0){
        // Recursividade para incrementar a quantidade de algarismos enquanto o num / 10 for diferente de 0
        length = countLength(num/10, length+1);
    }

    return length;
}

/*
    Exercise: 3
    Descrição: função que recebe dois números inteiros e retorna a soma dos algarismos do primeiro tendo o segundo como auxiliar
    Entradas (tipos e para que servem): dois valores inteiro para serem calculados
    Saída (tipo e valor): um valor inteiro referente à soma de algarismos
*/
int sunNumbers(int num, int sun) {
    /*
        Se o número for maior que 10 chama a função recursiva passando o número / 10 e o
        número desconsiderando o último algarismo (que já foi somado), e caso seja menor
        que 10, apenas soma o próprio número.
    */
    sun += (num > 10) ? sunNumbers(num / 10, num - num/10*10) : num;

    // Retorna a soma dos algarismos
    return sun;
}

/*
    Exercise: 4
    Descrição: função que recebe dois números inteiros e retorna a multiplicação do primeiro pelo segundo
    Entradas (tipos e para que servem): dois valores inteiro para serem calculados
    Saída (tipo e valor): um valor inteiro referente ao resultado da multiplicação
*/
int multiplication(int num1, int num2) {
    // Se num2 for maior que 1, realiza a adição de num1 + num1 e diminui 1 no num2
    if(num2 > 1){
        // Recursividade para somar num1+num1 enquanto num2 for maior que 1
        num1 += multiplication(num1, num2-1);
    }

    // Retorna o resultado
    return num1;
}

/*
    Exercise: 5
    Descrição: função que recebe quatro números inteiros, faz uma progressão geométrica e retorna o n-ésimo termo indicado pelo usuário
    Entradas (tipos e para que servem): quatro valores inteiro para formarem a progressão geométrica e retornar o n-ésimo termo
    Saída (tipo e valor): um valor inteiro referente ao n-ésimo termo
*/
int pg(int num, int reason, int position, int i) {

    // Condição para parar a recursividade no termo desejado pelo usuário
    if(position > i) {

        // Recursividade que forma a progressão geométrica enquanto não chegar ao n-ésimo termo
        num = pg(num*reason, reason, position, i+1);
    }

    return num;
}