# 02-trab-lista-itineraria

## Descricao
Sistema de gerenciamento de itinerários de transporte utilizando Lista Duplamente Encadeada em C++. Escolhi a lista duplamente encadeada por alguns motivos:
1. navegação bidirecional: que me permite percorrer o itinerario do começo ao fim e vice-versa
2. inserção pratica: diferente de vetores do metodo tad, esse nao exige deslocar todos os elemetnos na memoria.
3. flexivel: cada nó armazena o ponteiro para o proximo e pro anterior, garante a flexibilidade em operações mais dificeis.

## Identificação

**Instituição:** Universidade do Vale do Itajaí (UNIVALI)

**Curso:** Ciência da Computação

**Aluno:** Daniel Luiz Cardoso

**Professor:** Luiz Henrique Américo Salazar

## Requisitos
* **Compilador:** GCC (g++) versão 11.0 ou superior.
* **Ambiente:** VSCode ou qualquer terminal com suporte a Make/CMake.
* **Extensões sugeridas (VSCode):** C/C++, CMake Tools.

## Compilação
O projeto usa o cmake pra gerenciar a build de forma mais simples.
1. na raiz do projeto, crie a pasta de build: mkdir build && cd build
2. Configure o projeto: cmake ..
3. Compile: cmake --build .

## Teste e main
> (opção 1)
Para utilizar o diretorio de tests, o programa foi feito de uma forma que dê pra fazer uma alternancia entre o "main" e o "test" de forma simples.
No arquivo cmakelists.txt, vc irá deixar um # na linha em que deseje ignorar, e livre na linha que deseje compilar, por ex:

```text
rodar o main:
cmakeists.txt
└── linha 7: #add_ex...
└── linha 8: add_ex...
```

```text
rodar o teste:
cmakeists.txt
└── linha 7: add_ex...
└── linha 8: #add_ex...
(ou seja, você somente alterna entre qual arquivo o cmake vai esconder
na hora da compilação, e deixar livre somente o que irá ser compilado.)
```
> (opção 2)
Voce pode rodar o codigo no seu main tambem, utilizando os respectivos comandos:

```text
rodar o main:
g++ -I include main.cpp src/lista.cpp -o programa
```
```text
rodar os testes:
g++ -I include tests/test.cpp src/lista.cpp -o testes
```

## Funções

> inserirPosicao
Permite inserir uma parada em qualquer ponto do itinerário, ajustando automaticamente os ponteiros dos nodos vizinhos para manter a integridade da lista.

> limparLista
Garante o gerenciamento correto da memória (evitando Memory Leaks). Percorre toda a estrutura liberando cada nodo alocado com delete antes de encerrar o programa.

> buscar
Implementa uma busca flexível utilizando string::npos, permitindo encontrar paradas mesmo que o usuário digite apenas parte do nome.

## Organização do Projeto
```text
src/: Implementação da lógica (lista.cpp).
include/: Definições de estruturas e protótipos (lista.h).
tests/: Testes de unidade com assert (test.cpp).
main.cpp: Interface de menu interativo para o usuário.
```

representação visual de cada diretorio/arquivo:
```text
.
├── include/
│   └── lista.h         # Definições de structs e protótipos
├── src/
│   └── lista.cpp       # Implementação das funções da lista
├── tests/
│   └── test.cpp        # Script de testes unitários (asserts)
├── .gitignore          # Filtro de arquivos para o Git
├── CMakeLists.txt      # Configuração do build system
├── main.cpp            # Interface principal (Menu)
└── README.md           # Documentação do projeto
```
