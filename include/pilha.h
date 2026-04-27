#ifndef PILHA_H
#define PILHA_H

#include <vector>
#include <string>

struct Pilha {
    std::vector<int> discos;
    std::string nome;
};

void inicializar(Pilha* p, std::string nome);
void empilhar(Pilha* p, int disco);
int desempilhar(Pilha* p);
void exibirHaste(Pilha* p);

#endif