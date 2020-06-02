#include <stdio.h>

struct Students {
    int num;
    char name[50];
};

void insertRecord(struct Students students[], int amount, FILE *fp) {
    for(int i = 0; i < amount; i++) {
        printf("Digite o nome e o numero matricula do aluno %i (Ex: Gabriel 1010): ", i+1);
        scanf("%s %i", &students[i].name, &students[i].num);
        fflush(stdin);

        fprintf(fp, "%s %i\n", students[i].name, students[i].num);
    }
}

void readRecords(FILE *fp) {
    int num;
    char name[100];
    
    while (!feof(fp)){
        fscanf(fp, "%s %i\n", &name, &num);
        printf("%s %i\n", name, num);
    }
}

int main() {
    int option;

    printf("Escolha a opcao que deseja executar:");
    printf("\n1 | Inserir registros");
    printf("\n2 | Ler registros");
    printf("\n3 | Limpar os registros");
    printf("\n: ");
    scanf("%i", &option);
    fflush(stdin);

    if(option == 1) {

        int amount;

        printf("Digite quantos registros deseja inserir (Ex: 10): ");
        scanf("%i", &amount);
        fflush(stdin);

        struct Students students[amount];
        FILE *fp;

        fp = fopen("exercise-3.txt", "a");
        if(!fp){ printf("Erro na abertura do arquivo"); exit(0); }

        insertRecord(students, amount, fp);

        fclose(fp);

    }else if(option == 2) {
                
        FILE *fp;
        fp = fopen("exercise-3.txt", "r");
        if(!fp){ printf("Erro na abertura do arquivo"); exit(0); }

        readRecords(fp);

        fclose(fp);

    }else if(option == 3) {

        FILE *fp;

        fp = fopen("exercise-3.txt", "w");
        if(!fp){ printf("Erro na abertura do arquivo"); exit(0); }
        
        fclose(fp);
        
    }

    return 0;
}