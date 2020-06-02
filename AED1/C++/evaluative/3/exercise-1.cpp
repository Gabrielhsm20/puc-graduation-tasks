/*

Construa uma classe chamada [Fracao] que representação uma fração numérica. Essa classe deve ter os atributos públicos inteiros: numerador e denominador. A classe deve ter um método imprimir para mostrar o numerador e denominador.

a) Ilustre por meio de uma função main a construção de um objeto dessa classe passando para seu construtor o númerador e denominador digitados por um usuário no main, e depois a impressão dos dados do objeto por meio do método imprimir.

b) Construa um método na classe [Fracao] chamado salvar, que recebe um nome de arquivo como parâmetro (char[]) e escreve os valores do numerador e denominador no arquivo indicado. Por exemplo: para a fração 2/3 deverá ser escrita no arquivo arquivo: 2 3

Ilustre no main a chamada desse método após o usuário digitar os valores.

*/

#include <iostream>

using namespace std;

class Fracao {
    int numerador;
    int denominador;

public:
    // Sobrecarga de construtor
    Fracao(int num, int den) {
        numerador = num;
        denominador = den;
    }

    // Objeto para imprimir os dados na tela
    void imprimir() {
        cout << "Numerador: " << numerador << endl;
        cout << "Denominador: " << denominador << endl;
    }

    // Objeto para salvar os dados em um arquivo
    void salvar(char arquivo[]) {
        FILE *fp;
        
        // Abre o arquivo para escrever
        fp = fopen(arquivo, "w");

        // Condição que verifica se houve êxito ao abrir o arquivo
        if(!fp) {
            cout << "Erro na abertura do arquivo";
            exit(0);
        }

        // Printa no arquivo os dados
        fprintf(fp, "%i %i", numerador, denominador);

        // Fecha o arquivo
        fclose(fp);
    }
};

int main() {
    int num, den;

    // Solicita que o usuário insira um numerador
    cout << "Insira um numerador: ";
    cin >> num;
    
    // Solicita que o usuário insira um denominador
    cout << "Insira um denominador: ";
    cin >> den;

    // Instancia e inicia a classe passando os parâmetros para o construtor sobrecarregado
    Fracao fracao(num, den);

    // Imprive os dados
    fracao.imprimir();

    // Salva no arquivo
    fracao.salvar("backup.txt");

    return 0;
}