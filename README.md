Trabalho de Algoritmos e Estrutura de Dados sobre POO e Listas. 

---

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
  - [ ] InserirNoInicio
  - [ ] InserirNoFinal
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] RemoverPeloId
  - [ ] BuscarPeloId
  - [ ] AlterarPeloId

- Lista Ordenada
  - [ ] Inserir (lembrar de ordernar o elemento pelo `ID`)
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] RemoverPeloId
  - [ ] BuscarPeloId (busca binária usando o `ID`)
  - [ ] AlterarPeloId

As estruturas a seguir devem ser montadas por **composição**.

Avaliar e comentar a **ineficiência** da manipulação, em seguida propor e implementar uma segunda versão **otimizada**.

- Pilha
  - [ ] Empilhar
  - [ ] Desempilhar
  - [ ] ConsultarTopo
  - [ ] PilhaCheia
  - [ ] PilhaVazia

- Fila
  - [ ] Emfileirar
  - [ ] Desemfileirar
  - [ ] ConsultarInicio
  - [ ] ConsultarFim
  - [ ] FilaCheia
  - [ ] FilaVazia

## Classes de alocação encadeada

A classe interna de nó (herdada de elemento) deve ser **privada** (encapsulada) dentro de cada estrutura.

- ListaSimplesmenteEncadeada
  - [ ] InserirNoInicio
  - [ ] InserirNoFinal
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] RemoverPeloId
  - [ ] BuscarPeloId
  - [ ] AlterarPeloId

- ListaDuplamenteEncadeada
  - [ ] InserirNoInicio
  - [ ] InserirNoFinal
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] RemoverPeloId
  - [ ] BuscarPeloId
  - [ ] AlterarPeloId

- ListaDuplamenteEncadeadaCircular
  - [ ] InserirNoInicio
  - [ ] InserirNoFinal
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] RemoverPeloId
  - [ ] BuscarPeloId
  - [ ] AlterarPeloId

As estruturas a seguir devem ser montadas por **composição**.

Escolher a estrutura (ListaSimplesmenteEncadeada, ListaDuplamenteEncadeada ou ListaDuplamenteEncadeadaCircular) mais **eficiente** para implementar em cada caso.

- Pilha
  - [ ] Empilhar
  - [ ] Desempilhar
  - [ ] ConsultarTopo
  - [ ] PilhaVazia

- Fila
  - [ ] Emfileirar
  - [ ] Desemfileirar
  - [ ] ConsultarInicio
  - [ ] ConsultarFim
  - [ ] FilaVazia

- Deque
  - [ ] InserirNoInicio
  - [ ] InserirNoFinal
  - [ ] RemoverPrimeiro
  - [ ] RemoverUltimo
  - [ ] DequeVazia

Lembrar que a classe interna de nó (herdada de elemento) deve ser **privada** (encapsulada) dentro da estrutura.

Basear a organização no atributo ID.

Ajuda: https://en.wikipedia.org/wiki/Binary_search_tree.

- Árvore Binária de Busca
  - [ ] Inserir
  - [ ] BuscarPeloId
  - [ ] RemoverPeloId
  - Percursos: (não sei oque o prof quiz dizer com esses topicos)
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
  - [ ] Lista Não Ordenada
  - [ ] Lista Ordenada
  - [ ] Pilha (Sequencial)
  - [ ] Fila (Sequencial)
  - [ ] ListaSimplesmenteEncadeada
  - [ ] ListaDuplamenteEncadeada
  - [ ] ListaDuplamenteEncadeadaCircular
  - [ ] Pilha (Encadeada)
  - [ ] Fila (Encadeada)
  - [ ] Deque (Encadeada)
  - [ ] Árvore Binária de Busca

    
## Para fazer antes de enviar

- [ ] Deixar o repositório público

Organizar README.md:
- [ ] Explicações de design
- [ ] Tabela de complexidade
- [ ] Nomes dos integrantes do grupo
