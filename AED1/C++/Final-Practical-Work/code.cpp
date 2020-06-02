#include <iostream>
#include <locale.h>
#include <ctime>
#include <conio.h>

using namespace std;

// Dist�ncia em que ser� percebido a Presa e Predador
#define PERCEIVE_PREY 3
#define PERCEIVE_PREDATOR 3

// A��es: Andar aleat�riamente, Fugir e Perseguir presa
#define RANDOM_WALK 1
#define RUN_AWAY 2
#define CHASE_PREY 3

// Gera uma dire��o "aleat�ria"
#define RANDOM_DIRECTION (rand() % 4) + 1;
// Gera um sentido "aleat�ria" no eixo X
#define RANDOM_DIRECTION_X (rand() % 2) + 3;
// Gera um sentido "aleat�ria" no eixo Y
#define RANDOM_DIRECTION_Y (rand() % 2) + 1;

// Dire��es
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

// Dimens�es do tabuleiro
#define L 6
#define C 6

// Procedimento para escrever na tela o estado
void showState(int s) {
    if(s == 1) {
        cout << "Passeando";
    }else if(s == 2) {
        cout << "Fugindo   ";
    }else if(s == 3) {
        cout << "Perseguindo";
    }else{
        cout << "Indefinido";
    }
}

// Procedimento para escrever na tela a dire��o
void showDirection(int d) {
    if(d == UP) {
        cout << "Cima  ";
    }else if(d == DOWN) {
        cout << "Baixo";
    }else if(d == RIGHT) {
        cout << "Direita";
    }else if(d == LEFT) {
        cout << "Esquerda";
    }else{
        cout << "Indefinido";
    }
}

class Agent;
int AgentType(Agent *Agent);

class World {

public:
    Agent *matrix[L][C];

    // Limpa a matriz
    void init() {
        // Loop para definir como "NULL" todas posi��es da matriz
        for(int i = 0; i < L; i++)
            for(int j = 0; j < C; j++)
                matrix[i][j] = NULL;
    }

    void save() {
        // Exibe a matriz antes de salvar
        show();

        char save = 'n';
        // Pergunta se o usu�rio deseja salvar
        cout << "Deseja salvar o estado final (s para SIM / n para N�O): ";
        cin >> save;

        // Condi��o que verifica se a resposta do usu�rio foi positiva
        if(save == 's'){
            FILE *fp;
            char fileName[30];

            // Solicita que o usu�rio digite o nome do arquivo e sua extens�o
            cout << "Digite o nome do arquivo e sua extens�o (Ex: backup.txt): ";
            cin >> fileName;

            // Abre o arquivo
            fp = fopen(fileName, "w");
            // Verifica se houve �xito ao abrir e, se n�o, exibe uma mensagem e encerra
            if(!fp) { printf("Erro na abertura do arquivo"); exit(0); }

            // Insere na primeira linha do arquivo as dimens�es da matriz
            fprintf(fp, "%i %i\n", L, C);

            // Loop para inserir no arquivo a matriz
            for(int i = 0; i < L; i++){
                for(int j = 0; j < C; j++)
                    fprintf(fp, "%i ", AgentType(matrix[i][j]));
                
                fprintf(fp, "\n");
            }

            // Fecha o arquivo
            fclose(fp);
        }
    }

    // Exibe o atual estado da matriz
    void show() {
        cout << "\n";
        // Loop para imprimir na tela o valor de cada posi��o da matriz
        for(int i = 0; i < L; i++){
            for(int j = 0; j < C; j++)
                cout << AgentType(matrix[i][j]) << " | ";

            cout << "\n";
        }
        cout << "\n";
    }
};

class Agent {

protected:
    int posX;
    int posY;
    int state;
    int direction;
    int *reference;

public:
    int type = 0;

    World *aWorld;

    // Inicia o agente colocando-o em uma posi��o no tabuleiro
    void init(World *w, int initialX, int initialY) {
        posX = initialX;
        posY = initialY;
        aWorld = w;
        aWorld->matrix[posY][posX] = this;
    }

    // Verifica se existe um agente na posi��o passada por par�metro
    int existAgent(int newX, int newY) {
        return aWorld->matrix[newY][newX] == NULL ? 0 : 1;
    }

    // Move o agente para uma nova posi��o
    void move(int newX, int newY) {
        // Condi��o que verifica se a nova posi��o n�o ultrapassa os limites do tabuleiro
        if(newX >= 0 && newX <= C-1 && newY >= 0 && newY <= L-1) {
            // Condi��o que verifica se j� n�o existe um agente na nova posi��o
            if (!existAgent(newX, newY)) {
                aWorld->matrix[posY][posX] = NULL;
                posX = newX;
                posY = newY;
                aWorld->matrix[posY][posX] = this;
            }
        }
    }

    // Valida e, se necess�rio, altera a dire��o do movimento para n�o perder a jogada
    int validateDirection(int direction, int posX, int posY) {       
        // Loop para mudar a dire��o quando o agente chegar no limite VERTICAL do tabuleiro
        while((direction == UP && posY == 0) || (direction == DOWN && posY == L-1)) {
            if(posX == 0){
                direction = RIGHT;
            }else if(posX == C-1){
                direction = LEFT;
            }else{
                direction = RANDOM_DIRECTION_X;
            }
        }

        // Loop para mudar a dire��o quando o agente chegar no limite HORIZONTAL do tabuleiro
        while((direction == LEFT && posX == 0) || (direction == RIGHT && posX == C-1)) {
            if(posY == 0){
                direction = DOWN;
            }else if(posX == L-1){
                direction = UP;
            }else{
                direction = RANDOM_DIRECTION_Y;
            }
        }

        return direction;
    }

    void verifyRadius();
    void decide();
    void exec();
};

class Cat: public Agent {

public:
    Cat() {
        state = RANDOM_WALK;
        direction = RANDOM_DIRECTION;
        type = 1;
    }

    void verifyRadius() {
        // Verifica se existe predador em at� PERCEIVE_PREDATOR quadros para cima
        for(int i = 1; posY > 0 && i <= PERCEIVE_PREDATOR && posY-i >= 0; i++)
            if(existAgent(posX, posY-i)) {
                state = RUN_AWAY;
                direction = DOWN;
                break;
            }

        // Verifica se existe predador em at� PERCEIVE_PREDATOR quadros para baixo
        for(int i = 1; posY < L-1 && i <= PERCEIVE_PREDATOR && posY < L-i; i++)
            if(existAgent(posX, posY+i)) {
                state = RUN_AWAY;
                direction = UP;
                break;
            }

        // Verifica se existe predador em at� PERCEIVE_PREDATOR quadros para esquerda
        for(int i = 1; posX > 0 && i <= PERCEIVE_PREDATOR && posX-i >= 0; i++)
            if(existAgent(posX-i, posY)) {
                state = RUN_AWAY;
                direction = RIGHT;
                break;
            }

        // Verifica se existe predador em at� PERCEIVE_PREDATOR quadros para direita
        for(int i = 1; posX < C-1 && i <= PERCEIVE_PREDATOR && posX < C-i; i++)
            if(existAgent(posX+i, posY)) {
                state = RUN_AWAY;
                direction = LEFT;
                break;
            }
    }

    void decide() {
        // Exibe as �ltimas informa��es
        cout << "G: 1";
        cout << "\t\t�ltimo estado: "; showState(state);
        cout << " - �ltima dire��o: "; showDirection(direction);

        // Reseta o estado e dire��o
        state = RANDOM_WALK;
        direction = RANDOM_DIRECTION;

        // Verifica se existe predadores em um raio de PERCEIVE_PREDATOR quadros e, se necess�rio, define um novo estado e dire��o
        verifyRadius();
    }

    void exec() {
        // Valida e, se necess�rio, altera a dire��o do movimento para n�o perder a jogada
        direction = validateDirection(direction, posX, posY);

        // Executa o movimento
        if(direction == UP) {
            move(posX, posY - 1);
        }else if(direction == RIGHT) {
            move(posX+1, posY);
        }else if(direction == DOWN) {
            move(posX, posY+1);
        }else if(direction == LEFT) {
            move(posX-1, posY);
        }

        // Exibe as atuais informa��es
        cout << "\t\tAtual estado: "; showState(state);
        cout << " - Atual dire��o: "; showDirection(direction);
        cout << endl;
    }
};

class Dog : public Agent {

public:
    Dog() {
        state = RANDOM_WALK;
        direction = RANDOM_DIRECTION;
        type = 2;
    }

    void verifyRadius() {
        // Verifica se existe presa em at� PERCEIVE_PREY quadros para cima
        for(int i = 1; posY > 0 && i <= PERCEIVE_PREY && posY-i >= 0; i++)
            if(existAgent(posX, posY-i)) {
                state = CHASE_PREY;
                direction = UP;
                break;
            }

        // Verifica se existe presa em at� PERCEIVE_PREY quadros para baixo
        for(int i = 1; posY < L-1 && i <= PERCEIVE_PREY && posY < L-i; i++)
            if(existAgent(posX, posY+i)) {
                state = CHASE_PREY;
                direction = DOWN;
                break;
            }

        // Verifica se existe presa em at� PERCEIVE_PREY quadros para esquerda
        for(int i = 1; posX > 0 && i <= PERCEIVE_PREY && posX-i >= 0; i++)
            if(existAgent(posX-i, posY)) {
                state = CHASE_PREY;
                direction = LEFT;
                break;
            }

        // Verifica se existe presa em at� PERCEIVE_PREY quadros para direita
        for(int i = 1; posX < C-1 && i <= PERCEIVE_PREY && posX < C-i; i++)
            if(existAgent(posX+i, posY)) {
                state = CHASE_PREY;
                direction = RIGHT;
                break;
            }
    }

    void decide() {
        // Exibe as �ltimas informa��es
        cout << "C: 2";
        cout << "\t\t�ltimo estado: "; showState(state);
        cout << " - �ltima dire��o: "; showDirection(direction);

        // Reseta o estado e dire��o
        state = RANDOM_WALK;
        direction = RANDOM_DIRECTION;

        // Verifica se existe presas em um raio de PERCEIVE_PREY quadros e, se necess�rio, define um novo estado e dire��o
        verifyRadius();
    }

    void exec() {
        // Valida e, se necess�rio, altera a dire��o do movimento para n�o perder a jogada
        direction = validateDirection(direction, posX, posY);

        // Executa o movimento
        if(direction == UP) {
            move(posX, posY - 1);
        }else if(direction == RIGHT) {
            move(posX+1, posY);
        }else if(direction == DOWN) {
            move(posX, posY+1);
        }else if(direction == LEFT) {
            move(posX-1, posY);
        }

        // Exibe as atuais informa��es
        cout << "\t\tAtual estado: "; showState(state);
        cout << " - Atual dire��o: "; showDirection(direction);
        cout << endl;
    }
};

class Walls : public Agent {

public:
    Walls() {
        direction = RANDOM_DIRECTION;
        type = 3;
    }

    void decide() {
        // Exibe as �ltimas informa��es
        cout << "W: 3";
        cout << "\t\t�ltima dire��o: ";
        showDirection(direction);
    }

    void exec() {
        // Valida a atual dire��o e, quando o agente estiver nos "escanteios" do tabuleiro, retorna uma nova dire��o
        direction = validateDirection(direction, posX, posY);

        // Executa o movimento
        if(direction == UP) {
            move(posX, posY - 1);
        }else if(direction == RIGHT) {
            move(posX+1, posY);
        }else if(direction == DOWN) {
            move(posX, posY+1);
        }else if(direction == LEFT) {
            move(posX-1, posY);
        }

        // Exibe as atuais informa��es
        cout << "\t\tAtual dire��o: ";
        showDirection(direction);
        cout << endl;
    }
};

int AgentType(Agent *a) {
    return a == NULL ? 0 : a->type; 
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int exit = 0;
    // Loop enquanto "exit" for 0, ou seja, enquanto o usu�rio n�o escolher a op��o "sair"
    do {
        int option;
        // Loop enquanto a op��o escolhida for inv�lida
        do {
            system("cls");
            
            // Solicita que o usu�rio escolha uma op��o
            cout << "Selecione qual modelo de vida artificial deseja simular:" << endl;
            cout << "[1] Agente Walls" << endl;
            cout << "[2] Presa x Predador" << endl;
            cout << "[0] Sair" << endl;
            cin >> option;

        } while(option != 0 && option != 1 && option != 2);

        system("cls");

        // Se o usu�rio escolheu a op��o "sair", � atribuido o valor verdadeiro (1) para "exit" e ent�o finaliza o loop (e o programa)
        if(option == 0){
            exit = 1;
        }else{
            // Como o usu�rio n�o escolheu sair, abaixo � verificado qual modelo de vida artificial foi escolida
            if(option == 1) {
                // Instancia e inicia o mundo "quintal"
                World quintal;
                quintal.init();

                // Instancia e inicia o agente "walls" no mundo "quintal" e na posi��o (3,3)
                Walls walls;
                walls.init(&quintal, 3,3);

                int count = 1, p = 1;
                // Loop enquanto n�o chegar na cent�sima jogada ou o usu�rio escolher sair
                do {
                    // Agente "walls" decide e executa
                    walls.decide();
                    walls.exec();

                    // Exibe o mundo
                    quintal.show();

                    // Solicita uma nova a��o
                    cout << "[Jogada "<<count<<"] Digite 1 para continuar ou qualquer outra coisa para sair: ";		
                    cin >> p;
                            
                    system("cls");
                } while(count++ < 100 && p==1);

                quintal.save();
            }else if(option == 2) {
                // Instancia e inicia o mundo "quintal"
                World quintal;
                quintal.init();

                // Instancia e inicia o agente gato "felix" no mundo "quintal" e na posi��o (0,0)
                Cat felix;
                felix.init(&quintal, 0, 0);

                // Instancia e inicia o agente cachorro "bob" no mundo "quintal" e na posi��o (L-1,C-1)
                Dog bob;
                bob.init(&quintal, L-1, C-1);

                int count = 1, p = 1;
                do {
                    // Agente "felix" decide e executa
                    felix.decide();
                    felix.exec();
                    
                    // Agente "bob" decide e executa
                    bob.decide();
                    bob.exec();

                    // Exibe o mundo
                    quintal.show();

                    // Solicita uma nova a��o
                    cout << "[Jogada "<<count<<"] Digite 1 para continuar ou qualquer outra coisa para sair: ";		
                    cin >> p;
                            
                    system("cls");
                } while(count++ < 100 && p==1);
                
                quintal.save();
            }


            // Reseta a op��o atribuindo o valor "NULL" para o usu�rio escolher uma nova
            option = NULL;
        }
    } while(!exit); // Caso exit seja verdadeiro (1), o programa � finalizado

    cout << "At� logo!\n";
    
    return 0;
}