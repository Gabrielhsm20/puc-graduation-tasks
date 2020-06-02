/*
    Descrição: função que recebe um número e retorna seu fatorial caso maior que zero e 1 caso menor que zero
    Entradas (tipos e para que servem): um valor inteiro para calcular o fatorial
    Saída (tipo e valor): um valor inteiro referente ao fatorial
*/
int factorial(int num) {
    int result = 1;
    for (int i = num; i > 0; i--) {
        result *= i;
    }

    return result;
}

/*
    Exercício: 1
    Descrição: função que recebe três números e retorna o do meio
    Entradas (tipos e para que servem): três valores inteiros para serem comparados
    Saída (tipo e valor): um valor inteiro referente ao do meio
*/
int middleNumber(int num1, int num2, int num3) {
    if(num1 >= num2 && num1 >= num3){
        return num2 >= num3 ? num2 : num3;
    }else if(num2 >= num1 && num2 >= num3){
        return num1 >= num3 ? num1 : num3;
    }else{
        return num1 >= num2 ? num1 : num2;
    }
}

/*
    Exercício: 2
    Descrição: função que recebe dez números e retorna a média aritmética
    Entradas (tipos e para que servem): dez valores inteiros para calcular a média aritmética
    Saída (tipo e valor): um valor float referente à média aritmética
*/
float averageOfTenNumbers(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10) {
    return (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10) / 10;
}

/*
    Exercício: 3
    Descrição: função que recebe dois valores booleanos e retorna a operação verdade
    Entradas (tipos e para que servem): dois valores booleanos para calcular a operação verdade
    Saída (tipo e valor): um valor booleano referente à operação verdade
*/
int xorOperation(int val1, int val2) {
    return (!val1 && val2) || (val1 && !val2);
}

/*
    Exercício: 4
    Descrição: procedimento que executa a operação e exibe a soma dos 20 primeiros números da série
    Entradas (tipos e para que servem): -
    Saída (tipo e valor): -
*/
void numbersOfTheSum() {

    int numerator = 100,
        denominator = 0;

    float sum = 0;

    for(int i = 0; i < 20; i++) {

        // Operação da série
        sum += numerator / factorial(denominator);
        
        // Subtrai 1 do numerador e soma 1 ao denominador
        numerator--;
        denominator++;
    }
    
    printf("A soma dos 20 primeiros numeros da serie e %f", sum);
}

/*
    Exercício: 5
    Descrição: função que executa o somatório e retorna o resultado
    Entradas (tipos e para que servem): -
    Saída (tipo e valor): um valor float referente ao resultado do somatório
*/
float summation() {
    int numerator = 1,
        denominator = 15;
    float sum = 0;

    // Loop enquanto denominador for maior ou igual à 1
    while(denominator >= 1){
        
        // Operação do somatório
        sum += numerator / (float) (denominator * denominator);
        
        numerator *= 2;
        denominator -= 1;
    }

    return sum;
}

/*
    Exercício: 6
    Descrição: função que recebe um número e retorna o mesmo com 4 casas decimais
    Entradas (tipos e para que servem): um valor float para fazer a operação
    Saída (tipo e valor): um valor float referente ao número da entrada com 4 casas decimais
*/
float moldNumber(float num){
    return (int) (num * 10000) / 10000.0;
}

/*
    Exercício: 6
    Descrição: função que recebe um número e retorna a quantidade de elementos necessários
    Entradas (tipos e para que servem): um valor inteiro para fazer a operação
    Saída (tipo e valor): um valor inteiro referente à quantidade de elementos
*/
int parallelSin(int num) {
    int aux = 1,
        elements = 0;
    float result = 0;

    // Objetivo
    printf("Goal: %f\n", moldNumber(num));

    // Loop enquanto o resultado for diferente do seno (considerando 4 casas decimais)
    while (moldNumber(result) != moldNumber(sin(num))) {
        
        // Operação da série para chegar ao seno
        result += pow(-1, elements) * pow(num, aux) / factorial(aux);

        // Soma 2 ao auxilar e 1 à quantidade de elementos
        aux += 2;          
        elements++;

        // Exibe o resultado a cada ciclo
        printf("\n%f", moldNumber(result));
    }

    printf("\n");

    return elements;
}

/*
    Exercício: 7
    Descrição: função que recebe dois números e retorna um número gerado entre eles
    Entradas (tipos e para que servem): dois valores inteiros para fazer a operação
    Saída (tipo e valor): um valor inteiro gerado
*/
int randomNumber(int min, int max) {

    if (max < min) {
        return -1;
    } else {
        srand(time(NULL));
        
        // "Gera" um número entre o min e o max
        return min + rand() % (max - min);
    }

}

/*
    Exercício: 8
    Descrição: procedimento que recebe um número e exibe este número por extenso
    Entradas (tipos e para que servem): um valor inteiro a ser exibido por extenso
    Saída (tipo e valor): -
*/
void writeNumberClass(int num) {
    int hundreds = num / pow(10,2); // Separa as centenas
    num -= hundreds * pow(10,2); // Subtrai as centenas
    int dozens = num / 10; // Separa as dezenas
    num -= dozens * 10; // Subtrai as dezenas
    int units = num; // O que sobra é as unidades

    if(hundreds > 0){
        if(hundreds == 1){
            printf("cento");
        }else if(hundreds == 2){
            printf("duzentos");
        }else if(hundreds == 3){
            printf("trezentos");
        }else if(hundreds == 4){
            printf("quatrocentos");
        }else if(hundreds == 5){
            printf("quinhentos");
        }else if(hundreds == 6){
            printf("seiscentos");
        }else if(hundreds == 7){
            printf("setecentos");
        }else if(hundreds == 8){
            printf("oitocentos");
        }else if(hundreds == 9){
            printf("novecentos");
        }
    }    
    
    if(dozens > 0){
        if(hundreds > 0){ printf(" e "); }
        if(dozens == 1){
            if(units == 0){
                printf("dez");
            }else{
                if(units == 1){
                    printf("onze");
                }else if(units == 2){
                    printf("doze");
                }else if(units == 3){
                    printf("treze");
                }else if(units == 4){
                    printf("catorze");
                }else if(units == 5){
                    printf("quinze");
                }else if(units == 6){
                    printf("dezesseis");
                }else if(units == 7){
                    printf("dezessete");
                }else if(units == 8){
                    printf("dozoito");
                }else if(units == 9){
                    printf("dozenove");
                }
            }
        }else if(dozens == 2){
            printf("vinte");
        }else if(dozens == 3){
            printf("trinta");
        }else if(dozens == 4){
            printf("quarenta");
        }else if(dozens == 5){
            printf("cinquenta");
        }else if(dozens == 6){
            printf("sessenta");
        }else if(dozens == 7){
            printf("setenta");
        }else if(dozens == 8){
            printf("oitenta");
        }else if(dozens == 9){
            printf("noventa");
        }
    }
    
    if(dozens != 1 && units > 0){
        if(hundreds > 0 || dozens > 0){ printf(" e "); }
        if(units == 9){
            printf("nove");
        }else if(units == 8){
            printf("oito");
        }else if(units == 7){
            printf("sete");
        }else if(units == 6){
            printf("seis");
        }else if(units == 5){
            printf("cinco");
        }else if(units == 4){
            printf("quatro");
        }else if(units == 3){
            printf("tres");
        }else if(units == 2){
            printf("dois");
        }else if(units == 1){
            printf("um");
        }
    }
}

/*
    Exercício: 8
    Descrição: procedimento que recebe um número, separa em classes e organiza a exibição deste número por extenso
    Entradas (tipos e para que servem): um valor inteiro a ser exibido por extenso
    Saída (tipo e valor): -
*/
void writeNumber(float num) {
    int class4 = num / pow(10,9); // Separa a classe dos bilhões
    num -= class4 * pow(10,9); // Subtrai a classe dos bilhões

    int class3 = num / pow(10,6); // Separa a classe dos milhões
    num -= class3 * pow(10,6); // Subtrai a classe dos milhões

    int class2 = num / pow(10,3); // Separa a classe dos milhares
    num -= class2 * pow(10,3); // Subtrai a classe dos milhares
    
    int class1 = num; // Separa a classe simples
    num -= class1; // Subtrai a classe simples

    int decimal = num * 100; // O que sobra é decimal (multiplicada por 100 para virar inteiro)

    printf("\n");
    printf("Classe 4: %i\n", class4);
    printf("Classe 3: %i\n", class3);
    printf("Classe 2: %i\n", class2);
    printf("Classe 1: %i\n", class1);
    printf("Decimal: %i\n", decimal);
    printf("\n");

    printf("Resultado: ");

    if(class4 > 0){
        writeNumberClass(class4);
        if(class4 == 1){
            printf(" bilhao");
        }else{
            printf(" bilhoes");
        }
    }

    if(class3 > 0){
        if(class4 > 0){
            if(class2 == 0 && class1 == 0){
                printf(" e ");
            }else{
                printf(", ");
            }
        }

        writeNumberClass(class3);
        if(class3 == 1){
            printf(" milhao");
        }else{
            printf(" milhoes");
        }
    }
    
    if(class2 > 0){
        if(class4 > 0 || class3 > 0){
            if(class1 == 0){
                printf(" e ");
            }else{
                printf(", ");
            }
        }

        writeNumberClass(class2);
        printf(" mil");
    }

    if(class1 > 0){
        if(class4 > 0 || class3 > 0 || class2 > 0){
            if(decimal == 0){
                printf(" e ");
            }else{
                printf(", ");
            }
        }

        writeNumberClass(class1);
    }

    printf(" reais");

    if(decimal > 0){
        if(class4 > 0 || class3 > 0 || class2 > 0 || class1 > 0){
            printf(" e ");
        }

        writeNumberClass(decimal);
        printf(" centavos");
    }
}