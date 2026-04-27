#include <iostream>
#include <cmath>
#include "pilha.h"

using namespace std;

int movimentos = 0;

void mostrarEstado(Pilha* a, Pilha* b, Pilha* c) {
    exibirHaste(a);
    exibirHaste(b);
    exibirHaste(c);
    cout << "-----------------" << endl;
}

void moverDisco(int n, Pilha* origem, Pilha* destino, Pilha* auxiliar, Pilha* a, Pilha* b, Pilha* c) {
    if (n == 1) {
        int disco = desempilhar(origem);
        empilhar(destino, disco);
        movimentos++;
        cout << "Mover disco " << disco << " de " << origem->nome << " para " << destino->nome << endl;
        mostrarEstado(a, b, c);
        return;
    }

    moverDisco(n - 1, origem, auxiliar, destino, a, b, c);
    moverDisco(1, origem, destino, auxiliar, a, b, c);
    moverDisco(n - 1, auxiliar, destino, origem, a, b, c);
}

int main() {
    int n;
    cout << "Digite o numero de discos (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) return 1;

    Pilha A, B, C;
    inicializar(&A, "A");
    inicializar(&B, "B");
    inicializar(&C, "C");

    for (int i = n; i >= 1; i--) {
        empilhar(&A, i);
    }

    cout << "Estado Inicial:" << endl;
    mostrarEstado(&A, &B, &C);

    moverDisco(n, &A, &C, &B, &A, &B, &C);

    cout << "Total de movimentos: " << movimentos << endl;

    return 0;
}