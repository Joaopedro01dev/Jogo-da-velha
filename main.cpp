#include <bits/stdc++.h>
using namespace std;

int velha[3][3];
int jogadas = 0;

void reiniar(){
    int contador = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            velha[i][j] = contador;
            contador++;
        }
    }

    jogadas = 0;
}

char mostrarCasa(int x){
    if(x == -1) return 'X';
    if(x == -2) return 'O';

    return '0';
}

void mostrarVelha(){
    cout << endl << endl;

    for(int i = 0; i < 3; i++){
        cout << " ";
        for(int j = 0; j < 3; j++){
            char c = mostrarCasa(velha[i][j]);

            if(c == '0') cout << velha[i][j];
            else cout << c;

            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n-----------\n";
    }
}

bool respostaValida(int resp, int &i, int &j){
    if(resp < 1 || resp > 9) return false;

    i = (resp - 1) / 3;
    j = (resp - 1) % 3;

    return velha[i][j] > 0;
}

bool verificarVitoria(){
    for (int i = 0; i < 3; i++) {
        if (velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2])
            return true;

        if (velha[0][i] == velha[1][i] && velha[1][i] == velha[2][i])
            return true;
    }

    //verificar diagonal primaria
    if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]){
        return true;
    }
    //verificar diagonal secundaria
    if(velha[2][0] == velha[1][1] && velha[1][1] == velha[0][2]){
        return true;
    }

    return false;
}

bool confirmar(){
    cout << "Deseja reiniciar o jogo? (S/N): ";
    char c;
    cin >> c;
    
    if(c == 's' || c == 'S') return true;
    if(c == 'n' || c == 'N') return false;

    cout << "Resposta invalida!" << endl;
    confirmar();
}

int main(){
    reiniar();
    
    while(true){
        mostrarVelha();

        int jogador = jogadas % 2 == 0 ? 1 : 2;
        char simbolo = jogadas % 2 == 0 ? 'X' : 'O';

        cout << endl  << endl << "Jogador " << jogador << " (" << simbolo << "), escolha uma posicao: ";
        int resp, i, j;
        cin >> resp;
        
        if(!respostaValida(resp, i, j)){
            cout << "Posição inválida ou já ocupada! Escolha outra posição." << endl;
            continue;
        }
        
        velha[i][j] = -jogador;
        jogadas++;

        if(verificarVitoria()){
            mostrarVelha();

            cout << endl << endl << "Parabens! Jogador " << jogador << " venceu!" << endl;

            if(confirmar()) reiniar();
            else break;
        }

        if(jogadas == 9){
            mostrarVelha();
            cout << endl << "Empate! Nenhum jogador venceu!" << endl;

            if(confirmar()) reiniar();
            else break;
        }
    }
    cout << "Obrigado por jogar o jodo da velha, ate a proxima!";
    return 0;
}