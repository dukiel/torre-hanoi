#include <iostream>
#include <cassert>
#include "lista.h"

using namespace std;

int main() {
    Lista l;
    inicializar(&l);

    inserirInicio(&l, "Ponto B");
    inserirInicio(&l, "Ponto A");
    inserirFim(&l, "Ponto D");
    inserirPosicao(&l, "Ponto C", 2);

    cout << "Teste Ida: ";
    listar(&l);
    cout << "Teste Volta: ";
    listarInverso(&l);

    assert(l.tamanho == 4);

    removerFim(&l);
    assert(l.tamanho == 3);

    cout << "Testes concluidos com sucesso!\n";

    limparLista(&l);
    return 0;
}