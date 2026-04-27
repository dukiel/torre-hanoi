# 02-trab-lista-itineraria

## Descricao
Soluçao do quebra-cabeça matemático Torre de Hanói utilizando a estrutura
de dados Pilha em C++. O projeto foca no uso de algoritmos recursivos para 
a manipulação de discos entre três hastes (A, B e C), respeitando as regras
clássicas de movimentação. A escolha da Pilha justific-se por:
1. lifo: Ideal para o problema, pois apenas o disco do topo pode ser removido e movido por vez.
2. Integridade de Dados: Impede o acesso a elementos no meio ou na base da haste, garantindo que as regras do jogo não sejam violadas via código.
3. Recursiva: A estrutura de pilha espelha a pilha de chamadas da função recursiva usada para resolver o problema.

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

## Execução dos testes
> (opção 1)
Para utilizr o diretorio de tests, o programa foi feito de uma forma que dê pra fazer uma alternancia entre o "main" e o "test" de forma simples.
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
g++ -I include main.cpp src/pilha.cpp -o programa
```
```text
rodar os testes:
g++ -I include tests/test.cpp src/pilha.cpp -o testes
```

## Funções

> hanoi
Resolve o problema movendo n-1 discos para a haste auxiliar, o disco base para
o destino, e os n-1 restantes para o destino final.

> empilhar / desempilhar
Garantem a inserção e remoção apenas no topo da estrutura.

> imprimirEstado
Lista os discos presentes em cada haste após cada movimentação
para acompanhamento no console.

## Organização do Projeto
```text
src/: Implementação da lógica da pilha (pilha.cpp).
include/: Definição da struct Pilha e protótipos (pilha.h).
tests/: Testes unitáris com assert (test.cpp).
main.cpp: Lógica recursiva de Hanói e interface de entrada.
README.md: Docmentação do projeto e respostas teóricas.
```

representação visual de cada diretorio/arquivo:
```text
.
├── include/
│   └── pilha.h         # Definições de structs e protótpos
├── src/
│   └── pilha.cpp       # Implementação das funções da lista
├── tests/
│   └── test.cpp        # Script de testes unitario
├── .gitignore          # Filtro de arquivos para o Git
├── CMakeLists.txt      # Configuração do build system
├── main.cpp            # Interface principal (Menu)
└── README.md           # Documentação do projeto
```
