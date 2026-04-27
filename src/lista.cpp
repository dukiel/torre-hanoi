#include <iostream>
#include "lista.h"

using namespace std;

void inicializar(Lista* l) {
    l->inicio = nullptr;
    l->fim = nullptr;
    l->tamanho = 0;
}

void inserirInicio(Lista* l, string nome) {
    Nodo* novo = new Nodo{ nome, nullptr, l->inicio };

    if (l->inicio != nullptr)
        l->inicio->ant = novo;
    else
        l->fim = novo;

    l->inicio = novo;
    l->tamanho++;
}

void inserirFim(Lista* l, string nome) {
    Nodo* novo = new Nodo{ nome, l->fim, nullptr };

    if (l->fim != nullptr)
        l->fim->prox = novo;
    else
        l->inicio = novo;

    l->fim = novo;
    l->tamanho++;
}

void inserirPosicao(Lista* l, string nome, int pos) {
    if (pos <= 0) {
        inserirInicio(l, nome);
        return;
    }
    if (pos >= l->tamanho) {
        inserirFim(l, nome);
        return;
    }

    Nodo* atual = l->inicio;
    for (int i = 0; i < pos; i++)
        atual = atual->prox;

    Nodo* novo = new Nodo{ nome, atual->ant, atual };

    if (atual->ant != nullptr) {
        atual->ant->prox = novo;
    }
    atual->ant = novo;
    l->tamanho++;
}

void removerInicio(Lista* l) {
    if (l->inicio == nullptr) return;

    Nodo* temp = l->inicio;
    l->inicio = l->inicio->prox;

    if (l->inicio != nullptr)
        l->inicio->ant = nullptr;
    else
        l->fim = nullptr;

    delete temp;
    l->tamanho--;
}

void removerFim(Lista* l) {
    if (l->fim == nullptr) return;

    Nodo* temp = l->fim;
    l->fim = l->fim->ant;

    if (l->fim != nullptr)
        l->fim->prox = nullptr;
    else
        l->inicio = nullptr;

    delete temp;
    l->tamanho--;
}

void buscar(Lista* l, string nome) {
    Nodo* atual = l->inicio;
    bool achou = false;

    while (atual != nullptr) {
        if (atual->nome.find(nome) != string::npos){
            cout << "Encontrado: " << atual->nome << endl;
            achou = true;
        }
        atual = atual->prox;
    }
    if (!achou)
        cout << "(!) Nenhuma parada encontrda com esse nome.\n";
}

void listar(Lista* l) {
    Nodo* atual = l->inicio;

    while (atual != nullptr) {
        cout << atual->nome << " -> ";
        atual = atual->prox;
    }

    cout << "NULL\n";
}

void listarInverso(Lista* l) {
    Nodo* atual = l->fim;

    while (atual != nullptr) {
        cout << atual->nome << " -> ";
        atual = atual->ant;
    }

    cout << "NULL\n";
}

void contar(Lista* l) {
    cout << "Total: " << l->tamanho << endl;
}

void limparLista(Lista* l) {
    while (l->inicio != nullptr) {
        removerInicio(l);
    }
}