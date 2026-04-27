#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

static void limparConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    Lista lista;
    inicializar(&lista);

    int op;
    string nome;
    int pos;

    do {
        limparConsole();

        cout << "\n1 - Inserir inicio\n";
        cout << "2 - Inserir fim\n";
        cout << "3 - Inserir posicao\n";
        cout << "4 - Remover inicio\n";
        cout << "5 - Remover fim\n";
        cout << "6 - Buscar\n";
        cout << "7 - Listar\n";
        cout << "8 - Listar inverso\n";
        cout << "9 - Contar\n";
        cout << "0 - Sair\n";

        cin >> op;

        switch (op) {
        case 1:
            cout << "Nome da parada: ";
            cin.ignore();
            getline(cin, nome);
            inserirInicio(&lista, nome);
            break;
        case 2:
            cout << "Nome da parada: ";
            cin.ignore();
            getline(cin, nome);
            inserirFim(&lista, nome);
            break;
        case 3:
            cout << "Nome da parada: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Posicao: ";
            cin >> pos;
            inserirPosicao(&lista, nome, pos);
            break;
        case 4:
            cout << "Removido do inicio";
            removerInicio(&lista);
            cout << "\n[Pressione ENTER para voltar]";
            cin.get();
            break;
        case 5:
            removerFim(&lista);
            break;
        case 6:
            cout << "Buscar parada: ";
            cin.ignore();
            getline(cin, nome);
            buscar(&lista, nome);
            cout << "\n[Pressione ENTER para voltar]";
            cin.get();
            break;
        case 7:
            listar(&lista);
            cout << "\n[Pressione ENTER para voltar]";
            cin.ignore();
            cin.get();
            break;
        case 8:
            listarInverso(&lista);
            cout << "\n[Pressione ENTER para voltar]";
            cin.ignore();
            cin.get();
            break;
        case 9:
            contar(&lista);
            cout << "\n[Pressione ENTER para voltar]";
            cin.ignore();
            cin.get();
            break;
        }

    } while (op != 0);

    limparLista(&lista);
    return 0;
}