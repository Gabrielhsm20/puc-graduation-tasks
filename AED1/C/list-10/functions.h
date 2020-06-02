/*
    Exercise: 10
    Descrição: procedimento que lê as coordenadas da jogada e, caso seja válida, seta no tabuleiro de xadrez
    Entradas (tipos e para que servem): um inteiro referente ao número da jogada
    Saída (tipo e valor): -
*/
void setPosition(int i) {
    int x = 0,
        y = 0;

    // Loop que solicita o X da jogada
    do {
        printf("Jogada %i - Insira um X (linha) entre 1 e 8 (Ex: 5): ", i+1);
        scanf("%i", &x);
        fflush(stdin);
    } while(x < 1 || x > 8);

    // Loop que solicita o Y da jogada
    do {
        printf("Jogada %i - Insira um Y (coluna) entre 1 e 8 (Ex: 5): ", i+1);
        scanf("%i", &y);
        fflush(stdin);
    } while(y < 1 || y > 8);

    printf("\n");

    // Condição que verifica se a jogada é válida e seta no tabuleiro
    if(verifyPosition(x-1, y-1)) {
        // Position[i].id = i;
        // Position[i].x = x-1; 
        // Position[i].y = y-1;

        Board[x-1][y-1] = 1;
    }else{
        printf("\n");
        
        // Caso seja inválida, solicita novamente que o usuário insira a posição
        setPosition(i);
    }
}

/*
    Exercise: 10
    Descrição: função que recebe as coordenadas da jogada e verifica se é válida
    Entradas (tipos e para que servem): dois inteiros referente às coordenadas da jogada
    Saída (tipo e valor): um inteiro sendo 1 para válida e 0 para inválida
*/
int verifyPosition(int x, int y) {
    int i, j;

    // Loop que percorre em direção ao Norte e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    while(i >= 0) {
        if(Board[i][y] == 1){
            printf("Posicao invalida, colisao ao norte. Tente novamente!\n");
            return 0;
        }
        i--;
    }

    // Loop que percorre em direção ao Sul e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    while(i < X) {
        if(Board[i][y] == 1){
            printf("Posicao invalida, colisao ao sul. Tente novamente!\n");
            return 0;
        }
        i++;
    }

    // Loop que percorre em direção ao Oeste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = y;
    while(i >= 0) {
        if(Board[x][i] == 1){
            printf("Posicao invalida, colisao ao oeste. Tente novamente!\n");
            return 0;
        }
        i--;
    }

    // Loop que percorre em direção ao Leste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = y;
    while(i < X) {
        if(Board[x][i] == 1){
            printf("Posicao invalida, colisao ao leste. Tente novamente!\n");
            return 0;
        }
        i++;
    }

    // Loop que percorre em direção ao Noroeste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    j = y;
    while(i >= 0 && j >= 0) {
        if(Board[i][j] == 1){
            printf("Posicao invalida, colisao ao noroeste. Tente novamente!\n");
            return 0;
        }
        i--;
        j--;
    }

    // Loop que percorre em direção ao Nordeste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    j = y;
    while(i < X && j >= 0) {
        if(Board[i][j] == 1){
            printf("Posicao invalida, colisao ao nordeste. Tente novamente!\n");
            return 0;
        }
        i++;
        j--;
    }

    // Loop que percorre em direção ao Sudoeste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    j = y;
    while(i >= 0 && j < X) {
        if(Board[i][j] == 1){
            printf("Posicao invalida, colisao ao sudoeste. Tente novamente!\n");
            return 0;
        }
        i--;
        j++;
    }

    // Loop que percorre em direção ao Sudeste e retorna 0 caso encontre alguma rainha (jogada inválida)
    i = x;
    j = y;
    while(i < X && j < X) {
        if(Board[i][j] == 1){
            printf("Posicao invalida, colisao ao sudeste. Tente novamente!\n");
            return 0;
        }
        i++;
        j++;
    }

    return 1;
}