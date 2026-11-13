// src/main.c
#include "arquivo.h"
#include "livro.h"
#include "utils.h"
#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para verificar ID duplicado no vetor
static int id_ja_existe(const VetorLivros *v, int id) {
  for (int i = 0; i < v->tamanho; ++i) {
    if (v->dados[i].id == id)
      return 1;
  }
  return 0;
}

static void cadastrar_livro(VetorLivros *v) {
  Livro l;
  char buffer[256];
  printf("\n--- Cadastro de Livro ---\n");
  printf("ID (inteiro): ");
  fgets(buffer, sizeof(buffer), stdin);
  l.id = atoi(buffer);
  if (id_ja_existe(v, l.id)) {
    printf("ID ja existe. Cadastro abortado.\n");
    press_any_key_to_continue();
    return;
  }
  printf("Título: ");
  read_line(l.titulo, sizeof(l.titulo));
  printf("Autor: ");
  read_line(l.autor, sizeof(l.autor));
  printf("Ano: ");
  fgets(buffer, sizeof(buffer), stdin);
  l.ano = atoi(buffer);
  printf("Categoria: ");
  read_line(l.categoria, sizeof(l.categoria));
  if (vetor_adicionar(v, &l)) {
    printf("Livro cadastrado com sucesso!\n");
  } else {
    printf("Falha ao cadastrar livro.\n");
  }
  press_any_key_to_continue();
}

static void listar_livros(const VetorLivros *v) {
    if (v->tamanho == 0) {
        printf("Nenhum livro cadastrado.\n");
        press_any_key_to_continue();
        return;
    }
    printf("\nOrdenar por (a) titulo ou (b) ano? ");
    char opt = getchar();
    clear_input_buffer();

    if (opt == 'a' || opt == 'A') {
        // Criar cópia temporária para não mudar a ordem original
        VetorLivros copia = *v;
        copia.dados = malloc(v->tamanho * sizeof(Livro));
        memcpy(copia.dados, v->dados, v->tamanho * sizeof(Livro));
        copia.capacidade = v->tamanho;
        vetor_ordenar_por_titulo(&copia);
        imprimir_cabecalho();
        for (int i = 0; i < copia.tamanho; ++i) {
            imprimir_livro(&copia.dados[i]);
            printf("------------------------\n");
        }
        free(copia.dados);
    } else if (opt == 'b' || opt == 'B') {
        VetorLivros copia = *v;
        copia.dados = malloc(v->tamanho * sizeof(Livro));
        memcpy(copia.dados, v->dados, v->tamanho * sizeof(Livro));
        copia.capacidade = v->tamanho;
        vetor_ordenar_por_ano(&copia);
        imprimir_cabecalho();
        for (int i = 0; i < copia.tamanho; ++i) {
            imprimir_livro(&copia.dados[i]);
            printf("------------------------\n");
        }
        free(copia.dados);
    } else {
        printf("Opcao invalida. Listando sem ordenacao.\n");
        imprimir_cabecalho();
        for (int i = 0; i < v->tamanho; ++i) {
            imprimir_livro(&v->dados[i]);
            printf("------------------------\n");
        }
    }
    press_any_key_to_continue();
}

static void buscar_livros(const VetorLivros *v) {
  if (v->tamanho == 0) {
    printf("Nenhum livro cadastrado.\n");
    press_any_key_to_continue();
    return;
  }
  printf("\nBuscar por: (1) Titulo, (2) Autor, (3) Categoria\nEscolha: ");
  char opt = getchar();
  clear_input_buffer();
  char termo[100];
  int encontrado = 0;
  switch (opt) {
  case '1':
    printf("Digite parte do titulo: ");
    read_line(termo, sizeof(termo));
    imprimir_cabecalho();
    for (int i = 0; i < v->tamanho; ++i) {
      if (strstr(v->dados[i].titulo, termo)) {
        imprimir_livro(&v->dados[i]);
        printf("------------------------\n");
        encontrado = 1;
      }
    }
    break;
  case '2':
    printf("Digite parte do autor: ");
    read_line(termo, sizeof(termo));
    imprimir_cabecalho();
    for (int i = 0; i < v->tamanho; ++i) {
      if (strstr(v->dados[i].autor, termo)) {
        imprimir_livro(&v->dados[i]);
        printf("------------------------\n");
        encontrado = 1;
      }
    }
    break;
  case '3':
    printf("Digite parte da categoria: ");
    read_line(termo, sizeof(termo));
    imprimir_cabecalho();
    for (int i = 0; i < v->tamanho; ++i) {
      if (strstr(v->dados[i].categoria, termo)) {
        imprimir_livro(&v->dados[i]);
        printf("------------------------\n");
        encontrado = 1;
      }
    }
    break;
  default:
    printf("Opcao invalida.\n");
    press_any_key_to_continue();
    return;
  }
  if (!encontrado) {
    printf("Nenhum livro encontrado com o termo informado.\n");
  }
  press_any_key_to_continue();
}

static void remover_livro(VetorLivros *v) {
  if (v->tamanho == 0) {
    printf("Nenhum livro cadastrado.\n");
    press_any_key_to_continue();
    return;
  }
  char buffer[32];
  printf("Digite o ID do livro a ser removido: ");
  fgets(buffer, sizeof(buffer), stdin);
  int id = atoi(buffer);
  if (vetor_remover_por_id(v, id)) {
    printf("Livro removido com sucesso.\n");
  } else {
    printf("Livro com ID %d nao encontrado.\n", id);
  }
  press_any_key_to_continue();
}

static void salvar_dados(const VetorLivros *v) {
  if (salvar_dados_texto(v, "livros.txt")) {
    printf("Dados salvos em livros.txt com sucesso.\n");
  } else {
    printf("Falha ao salvar dados.\n");
  }
  press_any_key_to_continue();
}

int main(void) {
  VetorLivros biblioteca;
  vetor_inicializar(&biblioteca);
  // Carrega dados se o arquivo existir
  carregar_dados_texto(&biblioteca, "livros.txt");

  int sair = 0;
  while (!sair) {
    printf("\nSistema de Gerenciamento de Biblioteca\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Buscar livros\n");
    printf("4. Remover livro por ID\n");
    printf("5. Salvar dados em arquivo texto (livros.txt)\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    char escolha = getchar();
    clear_input_buffer();
    switch (escolha) {
    case '1':
      cadastrar_livro(&biblioteca);
      break;
    case '2':
      listar_livros(&biblioteca);
      break;
    case '3':
      buscar_livros(&biblioteca);
      break;
    case '4':
      remover_livro(&biblioteca);
      break;
    case '5':
      salvar_dados(&biblioteca);
      break;
    case '6':
      printf("Deseja salvar antes de sair? (s/n): ");
      char resp = getchar();
      clear_input_buffer();
      if (resp == 's' || resp == 'S') {
        salvar_dados(&biblioteca);
      }
      sair = 1;
      break;
    default:
      printf("Opcao invalida!\n");
      press_any_key_to_continue();
      break;
    }
  }

  vetor_destruir(&biblioteca);
  return 0;
}
