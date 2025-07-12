# Implementação de estrutura de dados utilizando POO, C++ & CMake

**Disciplina**: Algoritmos e Estruturas de Dados.

**Professor**: Prof. Dr. Rodrigo Lamblet Mafort.

Instituto Politécnico, Universidade do Estado do Rio de Janeiro. Julho, 2025.

**Creditos** :
- Laura Neves Coutinho
  - Matricula: *202410330811*
  - Github: *@undephying*
- João Pedro Nóbrega de Oliveira Mattos
  - Matricula: *202410329611*
  - Github: *@jpnobrega05*
- Rodrigo Morales Tavares
  - Matricula: *202410068711*
  - Github: *@Shadrick194*
- Lucas Ângelo Câmara da Silva
  - Matricula: *202410367011*
  - Github: *@ahopness*
- Javier Blanco Rodrigues Cadima
  - Matricula: *202410330911*
  - Github: *@JavierCadima*
- Gusthavo Cassimiro Lemos Pereira
  - Matricula: *202410330211*
  - Github: *@Gusthoso*

## Estrutura do codigo

O repositório foi divido entre as pastas `inc` (include, com os headers `.h`) e `src` (source, com as implementações `.cpp`), onde foram implementadas diferentes estruturas de dados que serão debatidas ao longo desse relatório.

Todas as estruturas de dados seguem o mesmo modelo, herdando a classe `Elemento` para os dados contidos em si, forçando eles a declararem um inicializador, destruidor, valor do identificador unico e valor de conteudo.

Todos os dados contidos possuem um identificador unico `id` do tipo `int` com um conteúdo `valor` do tipo `std::string`, a escolha de string como tipo foi meramente didadica - para facilitar na demonstração e manipulação do funcionamento das estruturas de dados - ele pode ser substituido por qualquer outro tipo aceito pela linguagem de programação C++ que funcionará normalmente.

Todas as estruturas, utilizando alocação dinamica ou não, tem funções para:
- Inserir dados contidos (pelo identificador ou por posição na estrutura);
- Remover dados contidos (pelo identificador ou por posição na estrutura);
- Buscar dados contidos (pelo identificador);
- Alterar dados contidos (pelo identificador).

## Complexidade das operações

- **Alocação Sequencial**
  - Lista não ordenada (`src/aloc_sequencial/lista_nao_ordenada.cpp`)
    - inserirNoInicio: **O(n)**
    - inserirNoFinal: **O(1)**
    - removerPrimeiro: **O(n)**
    - removerUltimo: **O(1)**
    - removerPeloId: **O(n)**
    - buscarPeloId: **O(n)**
    - alterarPeloId: **O(n)**
  - Lista ordenada (`src/aloc_sequencial/lista_ordenada.cpp`)
    - inserir: **O(n)**
    - removerPrimeiro: **O(n)**
    - removerUltimo: **O(1)**
    - removerPeloId: **O(n)**
    - buscarPeloId: **O(log n)**
    - alterarPeloId: **O(log n)**
  - Pilha (`src/aloc_sequencial/pilha.cpp`)
    - Empilhar: **O(1)**
    - Desempilhar: **O(1)**
  - Fila (`src/aloc_sequencial/fila.cpp`)
    - Enfileirar: **O(1)**
    - Desemfileirar: **O(n)**
    
- **Alocação Encadeada**
  - Lista simplesmente encadeada (`src/aloc_encadeada/lista_simplesmente_encadeada.cpp`)
    - inserirNoInicio: **O(1)**
    - inserirNoFinal: **O(n)**
    - removerPrimeiro: **O(1)**
    - removerUltimo: **O(n)**
    - removerPeloId: **O(n)**
    - buscarPeloId: **O(n)**
    - alterarPeloId: **O(n)**
  - Lista duplamente encadeada (`src/aloc_encadeada/lista_duplamente_encadeada.cpp`)
    - inserirNoInicio: **O(1)**
    - inserirNoFinal: **O(n)**
    - removerPrimeiro: **O(1)**
    - removerUltimo: **O(n)**
    - removerPeloId: **O(n)**
    - buscarPeloId: **O(n)**
    - alterarPeloId: **O(n)**
  - Lista duplamente encadeada circular (`src/aloc_encadeada/lista_duplamente_encadeada_circular.cpp`)
    - inserirNoInicio: **O(1)**
    - inserirNoFinal: **O(1)**
    - removerPrimeiro: **O(1)**
    - removerUltimo: **O(1)**
    - removerPeloId: **O(n)**
    - buscarPeloId: **O(n)**
    - alterarPeloId: **O(n)**
  - Pilha (`src/aloc_encadeada/pilha.cpp`)
    - Empilhar: **O(1)**
    - Desempilhar: **O(1)**
  - Fila (`src/aloc_encadeada/fila.cpp`)
    - Enfileirar: **O(1)**
    - Desemfileirar: **O(1)**
  - Deque (`src/aloc_encadeada/deque.cpp`)
    - InserirNoInicio: **O(1)**
    - InserirNoFinal: **O(1)**
    - removerPrimeiro: **O(1)**
    - removerUltimo: **O(1)**

- **Árvore de Busca Binária** (`src/arvore/arvore_binaria.cpp`)
  - inserir: **O(log n)**
  - remover: **O(log n)**
  - buscar: **O(log n)**

## Instruções de execução

**Opção 1 - Usando VSCode *no Windows* (mais simples)**:

- Instalar o Visual Studio Build Tools 2022:
  - https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
  - Durante a instalação, selecionar "Desktop development with C++"
  - Reiniciar PC após instalação

- Extensões necessárias:
  1. C/C++ (Microsoft)
  2. CMake Tools (Microsoft)

- Abrir o projeto no VSCode:
  - Faça duplo-clique no arquivo `aed.code-workspace`

- Aguardar a indexação.

- Precionar F5 para compilar e executar o projeto.

**Opção 2 - Usando CLI *no Windows e no Linux* (tende a falhar menos)**:

- **(WINDOWS APENAS)** Instalar dependências (PS: Reinicie após instalação):
```sh
winget install --id=Microsoft.VisualStudio.2022.BuildTools -e --override "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
winget install --id=Git.Git -e
```

- **(LINUX/WSL APENAS)** Instalar dependências:
```sh
sudo apt update
sudo apt install build-essential cmake
```

- **(WINDOWS APENAS)** Abrir "Developer Command Prompt" ou "Developer PowerShell";

- Clonar e navegar para o diretório do projeto:
```sh
git clone https://github.com/ahopness/aed-2025-1.git
cd aed-2025-1
```

- Criar pasta de build:
```sh
mkdir build
cd build
```

- Configurar o projeto com CMake:
```sh
cmake ..
```

- **(WINDOWS APENAS)** Compilar o projeto:
```sh
cmake --build . --config Release
```

- **(LINUX/WSL APENAS)** Compilar o projeto:
```sh
make
```

- **(WINDOWS APENAS)** Executar o programa:
```sh
.\Release\aeds-2025-1.exe
```

- **(LINUX/WSL APENAS)** Executar o programa:
```sh
./aeds-2025-1
```

## Extra (Post Scriptum)

Tem umas funções de sorting q agnt fez em `src/sorts/sorts.cpp`, sla acho q o esforço a mais poderia valer uns decimos a mais na nota do trabalho... ᵖᶠᵛʳ ʳᵒᵈʳⁱᵍᵒ ᵉᵘ ᵗᵉ ⁱᵐᵖˡᵒʳᵒ