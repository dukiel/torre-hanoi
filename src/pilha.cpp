#include <iostream>
#include <algorithm>
#include "pilha.h"

using namespace std;

void inicializar(Pilha* p, string nome) {
    p->nome = nome;
    p->discos.clear();
}

void empilhar(Pilha* p, int disco) {
    p->discos.push_back(disco);
}

int desempilhar(Pilha* p) {
    if (p->discos.empty()) return -1;
    int disco = p->discos.back();
    p->discos.pop_back();
    return disco;
}

void exibirHaste(Pilha* p) {
    cout << p->nome << ": [";
    for (size_t i = 0; i < p->discos.size(); i++) {
        cout << p->discos[i] << (i == p->discos.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}