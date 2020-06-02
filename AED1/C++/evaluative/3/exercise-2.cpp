/*

Implemente um algoritmo para cadastro de um equipamento de uma empresa. O equipamento deverá ter: matrícula (int), nome (char[30]), descrição (char[50]), valor de aquisição (numérico), data de movimentação (dia, mes e ano).

A implementação deverá ser orientada a objetos em C++ e deve ter recursos e conceitos implementados conforme se solicita a seguir:

O seu algoritmo deverá dar as opções/menu para o usuário:
a) Cadastrar o equipamento.
b) Mostrar os dados desse equipamento
c) Salvas os dados do equipamento em arquivo BINÁRIO.

Os seguintes recursos/conceitos deverão se implementados e indicados no código (comentários):

d) Uso de classe para representar o equipamento, com atributos e métodos.
e) Uso de sobrecarga de construtores
f) Uso de herança e método abstrato

OBSERVAÇÃO P/ PROFESSOR: NÃO ENCONTREI ONDE USAR O ITEM "E" (SOBRECARGA DE CONSTRUTORES), PORÉM UTILIZEI NA QUESTÃO 1.

*/

#include <iostream>

using namespace std;

class Equipamento {

// Protegido para funcionar apenas nessa classe e nas classes herdeiras
protected:
    int matricula;
    char nome[30];
    char descricao[50];
    int valor;
    int dia;
    int mes;
    int ano;

public:
    // Métodos abstratos
    void Cadastrar();
    void Exibir();
    void Salvar();
};

// Classe violão que herda os objetos da classe Equipamento
class Violao: public Equipamento {

public:
    // Objeto para cadastrar os dados
    void Cadastrar() {
        cout << "Insira a matricula (Ex: 10): ";
        cin >> matricula;

        cout << "Insira o nome (Ex: Violao): ";
        cin >> nome;

        cout << "Insira a descricao (Ex: Musica): ";
        cin >> descricao;

        cout << "Insira o valor (Ex: 200): ";
        cin >> valor;

        cout << "Insira a data de movimentacao (Ex: 10/10/2010): ";
        scanf("%i/%i/%i", &dia, &mes, &ano);

        cout << "\nCadastrado com sucesso!\n";
    }

    // Objeto para exibir os dados
    void Exibir() {
        cout << "Matricula: " << matricula << endl;
        cout << "Nome: " << nome << endl;
        cout << "Descricao: " << descricao << endl;
        cout << "Valor: " << valor << endl;
        cout << "Data de movimentacao: " << dia << "/" << mes << "/" << ano << endl;
    }

    // Objeto para salvar os dados
    void Salvar(char arquivo[]) {
        FILE *fp;
        
        // Abre o arquivo para escrever
        fp = fopen(arquivo, "wb");

        // Condição que verifica se houve êxito ao abrir o arquivo
        if(!fp) {
            cout << "Erro na abertura do arquivo";
            exit(0);
        }

        // Printa no arquivo os dados
        // Se não fosse binário:    fprintf(fp, "%i\t%s\t%s\t%i\t%i/%i/%i", matricula, nome, descricao, valor, dia, mes, ano);
        fwrite(&matricula, sizeof(int), 1, fp);
        fwrite(&nome, sizeof(char), 30, fp);
        fwrite(&descricao, sizeof(char), 50, fp);
        fwrite(&valor, sizeof(int), 1, fp);
        fwrite(&dia, sizeof(int), 1, fp);
        fwrite(&mes, sizeof(int), 1, fp);
        fwrite(&ano, sizeof(int), 1, fp);

        // Fecha o arquivo
        fclose(fp);
    }
};

int main() {
    int opcao,
        cadastrado = 0,
        exit = 0;

    // Instancia a classe Violao
    Violao violao;

    // Loop enquanto o usuário não indicar o desejo de sair
    do {
        cout << "\n";

        // Solicita que o usuário selecione uma opção
        cout << "Selecione uma opcao abaixo:" << endl;
        cout << "[1] Cadastrar o equipamento" << endl;
        cout << "[2] Mostrar os dados desse equipamento" << endl;
        cout << "[3] Salvar os dados do equipamento em arquivo" << endl;
        cout << "[0] Sair" << endl;
        cin >> opcao;

        cout << "\n";

        // Caso a opção seja 0, a variável "exit" se torna verdadeira e o loop se encerra
        if(opcao == 0) {
            exit = 1;
        }else if(opcao == 1) {
            // Objeto para cadastrar o equipamento
            violao.Cadastrar();
            // Indica que o equipamento já foi cadastrado para as outras opções funcionarem
            cadastrado++;
        }else if(opcao == 2) {
            // Verifica se o equipamento já foi cadastrado antes de exibí-lo
            if(!cadastrado) {
                cout << "Antes de mostrar os dados voce precisa cadastrar o equipamento\n";
            }else{
                // Objeto que exibe o equipamento
                violao.Exibir();
            }
        }else if(opcao == 3) {
            // Verifica se o equipamento já foi cadastrado antes de salvá-lo
            if(!cadastrado) {
                cout << "Antes de salvar os dados voce precisa cadastrar o equipamento\n";
            }else{
                // Objeto para salvar os dados no arquivo backup2.txt
                violao.Salvar("backup2.txt");
            }
        }

    } while(!exit); // Encerra o loop caso a variável "exit" seja verdadeira

    return 0;
}