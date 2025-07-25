# Trabalho de Algoritmos e Estrutura de Dados sobre POO e Listas. 

## Sobre a classe abstrata `Elemento`

- Atributo protegido concreto: `ID`
  - Método público concreto: `getID()`
- Essa classe vai ser utilizada como pai de outras classes concretas:
  - Cada uma deve ter atributos/métodos adicionais
- Método publico virtual: `imprimirInfo()`
  - Deve ser implementado por toda classe herdeira

## Classes de alocação sequencial

Implementar como classes **container**, que gerenciam memória dos objetos herdeiros de Elemento.

Analisar e comentar a **complexidade** de cada método.

- Lista Não Ordenada
  - [X] InserirNoInicio
  - [X] InserirNoFinal
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] RemoverPeloId
  - [X] BuscarPeloId
  - [X] AlterarPeloId

- Lista Ordenada
  - [X] Inserir (lembrar de ordernar o elemento pelo `ID`)
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] RemoverPeloId
  - [X] BuscarPeloId (busca binária usando o `ID`)
  - [X] AlterarPeloId

As estruturas a seguir devem ser montadas por **composição**.

Avaliar e comentar a **ineficiência** da manipulação, em seguida propor e implementar uma segunda versão **otimizada**.

- Pilha
  - [X] Empilhar
  - [X] Desempilhar
  - [X] ConsultarTopo
  - [X] PilhaCheia
  - [X] PilhaVazia

- Fila
  - [X] Emfileirar
  - [X] Desemfileirar
  - [X] ConsultarInicio
  - [X] ConsultarFim
  - [X] FilaCheia
  - [X] FilaVazia

## Classes de alocação encadeada

A classe interna de nó (herdada de elemento) deve ser **privada** (encapsulada) dentro de cada estrutura.

- ListaSimplesmenteEncadeada
  - [X] InserirNoInicio
  - [X] InserirNoFinal
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] RemoverPeloId
  - [X] BuscarPeloId
  - [X] AlterarPeloId

- ListaDuplamenteEncadeada
  - [X] InserirNoInicio
  - [X] InserirNoFinal
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] RemoverPeloId
  - [X] BuscarPeloId
  - [X] AlterarPeloId

- ListaDuplamenteEncadeadaCircular
  - [X] InserirNoInicio
  - [X] InserirNoFinal
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] RemoverPeloId
  - [X] BuscarPeloId
  - [X] AlterarPeloId

As estruturas a seguir devem ser montadas por **composição**.

Escolher a estrutura (ListaSimplesmenteEncadeada, ListaDuplamenteEncadeada ou ListaDuplamenteEncadeadaCircular) mais **eficiente** para implementar em cada caso.

- Pilha
  - [X] Empilhar
  - [X] Desempilhar
  - [X] ConsultarTopo
  - [X] PilhaVazia

- Fila
  - [X] Emfileirar
  - [X] Desemfileirar
  - [X] ConsultarInicio
  - [X] ConsultarFim
  - [X] FilaVazia

- Deque
  - [X] InserirNoInicio
  - [X] InserirNoFinal
  - [X] RemoverPrimeiro
  - [X] RemoverUltimo
  - [X] DequeVazia

Lembrar que a classe interna de nó (herdada de elemento) deve ser **privada** (encapsulada) dentro da estrutura.

Basear a organização no atributo ID.

Ajuda: https://en.wikipedia.org/wiki/Binary_search_tree.

- Árvore Binária de Busca
  - [X] Inserir
  - [X] BuscarPeloId
  - [X] RemoverPeloId
  - Percursos: (não sei oque o prof quis dizer com esses topicos (sou burro, perdão))
    - [ ] emOrdem
    - [ ] preOrdem
    - [ ] posOrdem

## Avaliação e demonstração

Para alocação sequencial:
- Adicionar objetos de diferentes subclasses de Elemento na mesma estrutura
- Chamar imprimirInfo() para mostrar polimorfismo

Para estruturas dinâmicas:
- Demonstrar o comportamento esperado

- Testa as estruturas
  - [X] Lista Não Ordenada
  - [X] Lista Ordenada
  - [X] Pilha (Sequencial)
  - [X] Fila (Sequencial)
  - [X] ListaSimplesmenteEncadeada
  - [X] ListaDuplamenteEncadeada
  - [X] ListaDuplamenteEncadeadaCircular
  - [X] Pilha (Encadeada)
  - [X] Fila (Encadeada)
  - [X] Deque (Encadeada)
  - [X] Árvore Binária de Busca

    
## Para fazer antes de enviar

- [ ] Deixar o repositório público

Organizar README.md:
- [X] Explicações de design
- [X] Tabela de complexidade
- [X] Nomes dos integrantes do grupo
