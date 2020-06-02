/*

Nesta atividade você deverá criar um sistema em C para cadastro de alunos. O sistema deverá oferecer as opções:
a) Cadastrar aluno (utilize um vetor de N alunos)
b) Lista alunos
c) Calcular a renda média e nota média dos alunos
d) Mostrar o aluno maior nota
e) Pesquisar alunos por matrícula
As opções seguintes deverão manipular arquivos texto.
f) Backup dos dados - Usuário informa o nome de um arquivo e programa salva os dados
dos alunos em arquivo texto (um registro por linha).
g) Restauração de dados – Usuário informa o nome de um arquivo e programa carregar dados salvo no arquivo na memória primária (um vetor de Alunos).

*/

#include <stdio.h>

struct Students {
    int num;
    char name[50];
    int age;
    char tel[30];
    float income;
    float note;
};

void insertRecord(struct Students students[], int amount) {
    for(int i = 0; i < amount; i++) {
        printf("Digite a matricula do aluno %i (Ex: 1010): ", i+1);
        scanf("%i", &students[i].num);
        fflush(stdin);
        
        printf("Digite o nome do aluno %i (Ex: Gabriel): ", i+1);
        scanf("%s", &students[i].name);
        fflush(stdin);

        printf("Digite a idade do aluno %i (Ex: 19): ", i+1);
        scanf("%i", &students[i].age);
        fflush(stdin);

        printf("Digite o telefone do aluno %i (Ex: 31 9 00000000): ", i+1);
        scanf("%s", &students[i].tel);
        fflush(stdin);

        printf("Digite a renda do aluno %i (Ex: 10500): ", i+1);
        scanf("%f", &students[i].income);
        fflush(stdin);

        printf("Digite a nota do aluno %i (Ex: 10): ", i+1);
        scanf("%f", &students[i].note);
        fflush(stdin);
    }
}

void printRecords(struct Students students[], int amount) {
    for(int i = 0; i < amount; i++)
        printf("%i %s %i %s %f %f\n", students[i].num, students[i].name, students[i].age, students[i].tel, students[i].income, students[i].note);
}

void avarageIncomeNote(struct Students students[], int amount) {
    float sumIncome = 0,
          sumNote = 0;

    for(int i = 0; i < amount; i++) {
        sumIncome += students[i].income;
        sumNote += students[i].note;
    }
    
    printf("A renda media dos alunos e %f\nA nota media dos alunos e %f\n", sumIncome/amount, sumNote/amount);
}

void biggestNote(struct Students students[], int amount) {
    float biggest;

    for(int i = 0; i < amount; i++)
        if(i==0 || students[i].note > biggest)
            biggest = students[i].note;

    printf("A maior nota e %f\n", biggest);
}

void searchNum(struct Students students[], int amount) {
    int num,
        finded = 0;

    printf("Digite a matricula que deseja procurar (Ex: 10): ");
    scanf("%i", &num);
    fflush(stdin);

    for(int i = 0; i < amount; i++){
        if(students[i].num == num){
            printf("\nRegistro encontrado:\n");
            printf("%i %s %i %s %f %f\n", students[i].num, students[i].name, students[i].age, students[i].tel, students[i].income, students[i].note);
            finded = 1; break;
        }
    }

    if(!finded)
        printf("\nNenhum registro encontrado\n");
}

void backupRecords(struct Students students[], int amount) {
    FILE *fp;
    char fileName[30];

    printf("Digite o nome e tipo do arquivo a ser criado/aberto (Ex: backup.txt): ");
    scanf("%s", &fileName);
    fflush(stdin);

    fp = fopen(fileName, "w");
    if(!fp) { printf("Erro na abertura do arquivo"); exit(0); }

    for(int i = 0; i < amount; i++)
        fprintf(fp, "%i %s %i %s %f %f\n", students[i].num, students[i].name, students[i].age, students[i].tel, students[i].income, students[i].note);

    fclose(fp);

    printf("\nBackup realizado com sucesso\n");
}

void readRecords() {
    FILE *fp;
    int num, age;
    char name[50], tel[30], fileName[30];
    float income, note;

    printf("Digite o nome e tipo do arquivo a ser aberto (Ex: backup.txt): ");
    scanf("%s", &fileName);
    fflush(stdin);

    fp = fopen(fileName, "r");
    if(!fp) { printf("Erro na abertura do arquivo"); exit(0); }    

    printf("\nRegistros encontrados:\n");
    while (!feof(fp)){
        fscanf(fp, "%i %s %i %s %f %f\n", &num, &name, &age, &tel, &income, &note);
        printf("%i %s %i %s %f %f\n", num, name, age, tel, income, note);
    }

    fclose(fp);
}

int main() {
    int option = 0,
        amount = 0;

    printf("Digite quantos alunos tem na escola (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);
    printf("\n");

    struct Students students[amount]; 

    do {
        printf("Escolha a opcao que deseja executar:");
        printf("\n1 | Inserir registros");
        printf("\n2 | Ler registros");
        printf("\n3 | Renda e nota media");
        printf("\n4 | Maior nota");
        printf("\n5 | Pesquisar por matricula");
        printf("\n6 | Backup em arquivo");
        printf("\n7 | Carregar do arquivo");
        printf("\n0 | Sair do programa");
        printf("\n: ");
        scanf("%i", &option);
        fflush(stdin);

        printf("\n");

        if(option == 1) {
            insertRecord(students, amount);
        }else if(option == 2) {
            printRecords(students, amount);
        }else if(option == 3) {
            avarageIncomeNote(students, amount);
        }else if(option == 4) {
            biggestNote(students, amount);
        }else if(option == 5) {
            searchNum(students, amount);
        }else if(option == 6) {
            backupRecords(students, amount);
        }else if(option == 7) {
            readRecords(students, amount);
        }

        printf("\n");
    } while(option != 0);

    printf("Ate logo!\n\n");

    return 0;
}