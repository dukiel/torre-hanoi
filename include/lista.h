#ifndef LISTA_H
#define LISTA_H

#include <string>
using namespace std;

struct Nodo {
    string nome;
    Nodo* ant;
    Nodo* prox;
};

struct Lista {
    Nodo* inicio;
    Nodo* fim;
    int tamanho;
};

void inicializar(Lista* l);

void inserirInicio(Lista* l, string nome);
void inserirFim(Lista* l, string nome);
void inserirPosicao(Lista* l, string nome, int pos);

void removerInicio(Lista* l);
void removerFim(Lista* l);

void buscar(Lista* l, string nome);
void listar(Lista* l);
void listarInverso(Lista* l);
void contar(Lista* l);

void limparLista(Lista* l);

#endif