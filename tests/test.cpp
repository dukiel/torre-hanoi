#include <iostream>
#include <cassert>
#include "../include/pilha.h"

using namespace std;

void test_pilha_basico() {
    Pilha p;
    inicializar(&p, "Teste");

    empilhar(&p, 10);
    empilhar(&p, 20);
    assert(p.discos.size() == 2);
    assert(p.discos.back() == 20);

    int d1 = desempilhar(&p);
    assert(d1 == 20);
    assert(p.discos.size() == 1);

    int d2 = desempilhar(&p);
    assert(d2 == 10);
    assert(p.discos.empty());

    assert(desempilhar(&p) == -1);
}

void test_hanoi_logica() {
    Pilha a, b, c;
    inicializar(&a, "A");
    inicializar(&b, "B");
    inicializar(&c, "C");

    empilhar(&a, 2);
    empilhar(&a, 1);

    empilhar(&b, desempilhar(&a));
    empilhar(&c, desempilhar(&a));
    empilhar(&c, desempilhar(&b));

    assert(a.discos.empty());
    assert(b.discos.empty());
    assert(c.discos.size() == 2);
    assert(c.discos[0] == 2);
    assert(c.discos[1] == 1);
}

int main() {
    test_pilha_basico();
    test_hanoi_logica();
    cout << "Testes concluidos." << endl;
    return 0;
}