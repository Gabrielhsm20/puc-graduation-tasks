/*
Construa um procedimento recebe um vetor de "Veículos" e um valor (float) por parâmetro. O procedimento deverá mostrar na tela e escrever em um arquivo os dados dos veículos cujo valor de mercado sejam maior que o valor recebida como parâmetro.
Crie também uma função main e demais implementações que permitam a chamada do procedimento criado após o usuário digitar os dados dos veículos. 
*/

#include <stdio.h>

// Criando o struct Veiculos (de acordo com enunciado)
struct Veiculos {
   char placa[8];
   int ano_modelo;
   char marca[30];
   char modelo[50];
   float valor_mercado;
};

/*
    Descrição: Procedimento que recebe um vetor e seu tamanho, e faz o loop para preenchimento
    Entradas (tipos e para que servem): o struct vetor e um inteiro referente ao tamanho do vetor
*/
void insertRecords(struct Veiculos veiculos[], int amount) {
    for(int i = 0; i < amount; i++) {
        printf("Insira a placa do veiculo %i: ", i+1);
        scanf("%s", &veiculos[i].placa);
        fflush(stdin);

        printf("Insira o ano do veiculo %i: ", i+1);
        scanf("%i", &veiculos[i].ano_modelo);
        fflush(stdin);

        printf("Insira a marca do veiculo %i: ", i+1);
        scanf("%s", &veiculos[i].marca);
        fflush(stdin);

        printf("Insira o modelo do veiculo %i: ", i+1);
        scanf("%s", &veiculos[i].modelo);
        fflush(stdin);

        printf("Insira o valor do veiculo %i: ", i+1);
        scanf("%f", &veiculos[i].valor_mercado);
        fflush(stdin);

        printf("\n");
    }
}

/*
    Descrição: Procedimento que recebe um vetor, seu tamanho e o valor mínimo do veículo informado pelo usuário, exibe e salva em um arquivo os veiculos com valor superior
    Entradas (tipos e para que servem): o struct vetor, um inteiro referente ao tamanho do vetor e um float referente ao valor mínimo para o veículo
*/
void showSaveRecords(struct Veiculos veiculos[], int amount, float value) {
    // Declara o arquivo
    FILE *fp;

    // Abre o arquivo para escrita (w)
    fp = fopen("backup.txt", "w");

    // Condição que verifica se o arquivo não foi aberto
    if(!fp) { printf("Erro na abertura do arquivo"); exit(0); }

    // Loop que passa por todos registros do vetor
    for(int i = 0; i < amount; i++){
        // Condição que verifica se o valor do veículo em questão é maior que o valor informado pelo usuário
        if(veiculos[i].valor_mercado > value){
            // Exibe os dados do veículo
            printf("%s %i %s %s %f\n", veiculos[i].placa, veiculos[i].ano_modelo, veiculos[i].marca, veiculos[i].modelo, veiculos[i].valor_mercado);
            
            // Salva os dados no arquivo
            fprintf(fp, "%s %i %s %s %f\n", veiculos[i].placa, veiculos[i].ano_modelo, veiculos[i].marca, veiculos[i].modelo, veiculos[i].valor_mercado);
        }
    }

    // Fecha o arquivo
    fclose(fp);
}

int main() {
    int amount;

    // Solicita que o usuário insira a quantidade de veiculos
    printf("Digite a quantidade de veiculos a se registrar (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);
    printf("\n");

    // Declara o vetor com o tamanho inserido pelo usuário
    struct Veiculos veiculos[amount];
    insertRecords(veiculos, amount);

    // Declara a variável valor
    float value;

    // Solicita que o usuário insira um valor mínimo para ser consultado e salvado no arquivo
    printf("\nDigite o valor minimo para ser exibido e salvo em um arquivo (Ex: 30500): ");
    scanf("%f", &value);
    fflush(stdin);

    // Procedimento que exibe e salva no arquivo
    showSaveRecords(veiculos, amount, value);

    return 0;
}