# Biblioteca - Sistema de Gerenciamento de Biblioteca

## Visão Geral
Este projeto implementa, em **C**, um sistema de gerenciamento de biblioteca para a disciplina *Programação de Computadores I*.  Ele permite cadastrar, listar, buscar, remover e salvar livros utilizando um vetor dinâmico (`malloc`/`realloc`) e arquivos de texto.

## Estrutura de Pastas
```
📦 f:/pc1/trabalho
├─ 📂 include          # cabeçalhos (.h)
│   ├─ utils.h
│   ├─ livro.h
│   ├─ vetor.h
│   └─ arquivo.h
├─ 📂 src              # implementação (.c)
│   ├─ utils.c
│   ├─ livro.c
│   ├─ vetor.c
│   ├─ arquivo.c
│   └─ main.c
├─ 📂 obj               # objetos gerados pelo Makefile (não versionado)
├─ 📄 Makefile          # script de compilação
├─ 📄 livros.txt         # arquivo de teste com 5 livros
└─ 📄 README.md          # este documento
```

## Requisitos
- **Compilador GCC** (ex.: MinGW‑w64 no Windows ou GCC/Linux)
- **Make** (ou `mingw32-make` no Windows)  
- Sistema operacional Windows (conforme a configuração do workspace)  

## Compilação
Abra um terminal na pasta raiz do projeto e execute:
```bash
make            # ou "mingw32-make" se estiver usando MinGW
```
O comando acima:
1. Cria a pasta `obj/`.
2. Compila cada arquivo `.c` em objetos (`*.o`).
3. Liga os objetos e gera o executável **biblioteca.exe**.

> **Dica:** Caso o `make` não esteja disponível, você pode compilar manualmente:
```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/*.c -o biblioteca.exe
```

## Execução
```bash
./biblioteca.exe   # no PowerShell ou CMD use .\biblioteca.exe
```
Ao iniciar, o programa tenta carregar os livros existentes em `livros.txt`. Em seguida apresenta o menu:
```
Sistema de Gerenciamento de Biblioteca
1. Cadastrar livro
2. Listar livros
3. Buscar livros
4. Remover livro por ID
5. Salvar dados em arquivo texto (livros.txt)
6. Sair
Escolha uma opcao:
```
Siga as instruções na tela. O programa aceita entradas **com espaços** para título, autor e categoria.

## Funcionalidades Implementadas
- **Cadastro** com verificação de ID duplicado.
- **Listagem** com ordenação por título ou por ano (cópia temporária para não alterar a ordem original).
- **Busca** por título, autor ou categoria (aceita substring).
- **Remoção** por ID, reorganizando o vetor para evitar “buracos”.
- **Persistência** em arquivo texto (`livros.txt`).
- **Makefile** completo para compilação automática.

## Arquivo de Teste (`livros.txt`)
O repositório já contém um arquivo de exemplo com 5 registros:
```
1|O Senhor dos Anéis|J.R.R. Tolkien|1954|Fantasia
2|Dom Quixote|Miguel de Cervantes|1605|Clássico
3|1984|George Orwell|1949|Distopia
4|A Culpa é das Estrelas|John Green|2012|Romance
5|Clean Code|Robert C. Martin|2008|Programação
```
Ele será lido automaticamente na primeira execução.

## Próximos Passos (opcionais)
- Implementar salvamento/leitura **binária** (`livros.dat`).
- Gerar relatórios avançados (quantidade por categoria, livro mais antigo/recente, etc.).
- Exportar em CSV.
- Adicionar testes automatizados.
- Melhorar a validação de entrada e tratamento de erros.
