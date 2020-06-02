/*
    Exercise: 1
    Descrição: função que verifica se um inteiro existe em um vetor
    Entradas (tipos e para que servem): um inteiro a ser procurado, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente à posição, caso encontrado, ou -1, caso não encontrado
*/
int searchNum(int num, int vect[], int i) {
    if(vect[i] == num){
        return i;
    }else{
        return i < N1-1 ? searchNum(num, vect, i+1) : -1;
    }
}

/*
    Exercise: 2
    Descrição: função que procura o maior elemento do vetor
    Entradas (tipos e para que servem): um inteiro auxiliar na comparação, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente ao maior elemento
*/
int biggestElement(int biggest, int vect[], int i) {
    if(i==0 || vect[i] > biggest)
        biggest = vect[i];

    return (i < N2-1) ? biggestElement(biggest, vect, i+1) : biggest;
}

/*
    Exercise: 3
    Descrição: função que procura o menor elemento do vetor
    Entradas (tipos e para que servem): um inteiro auxiliar na comparação, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente ao menor elemento
*/
int smallestElement(int smallest, int vect[], int i) {
    if(i==0 || vect[i] < smallest)
        smallest = vect[i];

    return (i < N3-1) ? smallestElement(smallest, vect, i+1) : smallest;
}

/*
    Exercise: 4
    Descrição: função que soma os elementos do vetor
    Entradas (tipos e para que servem): um inteiro auxiliar na soma, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente à soma dos elementos
*/
int sumElements(int sum, int vect[], int i) {
    sum += vect[i];
    return (i < N4-1) ? sumElements(sum, vect, i+1) : sum;
}

/*
    Exercise: 5
    Descrição: função que multiplica os elementos do vetor
    Entradas (tipos e para que servem): um inteiro auxiliar na multiplicação, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente ao produto dos elementos
*/
int multiplicationElements(int multiplication, int vect[], int i) {
    multiplication *= vect[i];
    return (i < N4-1) ? multiplicationElements(multiplication, vect, i+1) : multiplication;
}


/*
    Exercise: 6
    Descrição: função que calcula a media dos elementos do vetor
    Entradas (tipos e para que servem): um inteiro auxiliar na operação, o vetor e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente à média dos elementos
*/
float averageElements(float average, int vect[], int i) {
    average += vect[i];
    return (i < N4-1) ? averageElements(average, vect, i+1) : average/N6;
}

/*
    Exercise: 10
    Descrição: função que verifica se a palavra e um palindromo
    Entradas (tipos e para que servem): um char referente à palavra, um inteiro referente ao tamanho da palavra e um inteiro para auxiliar na contagem
    Saída (tipo e valor): um valor inteiro referente ao maior elemento
*/
int isPalin(char str[], int len, int i) {
    int isP = 0;

    /*
        Verifica se a letra i é igual à letra len-i ou
        se a letra i transformada em maiuscula é igual à len-i transformada em maiuscula

        Caso satisfaça a condição, ou seja, caso as letras forem iguais,
        chama-se a recursividade para verificar a letra seguinte
    */
    if(str[i] == str[len-i] || toupper(str[i]) == toupper(str[len-i]))
        isP = (len > i) ? isPalin(str, len, i+1) : 1;
    
    return isP;
}