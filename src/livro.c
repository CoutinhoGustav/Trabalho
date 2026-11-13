// src/livro.c
#include "livro.h"
#include <stdio.h>

void imprimir_cabecalho(void) {
    printf("%-5s %-30s %-20s %-5s %-15s\n", "ID", "Titulo", "Autor", "Ano", "Categoria");
    printf("--------------------------------------------------------------------------------\n");
}


void imprimir_livro(const Livro *l) {
  if (l == NULL) return;
  printf("%-5d %-30s %-20s %-5d %-15s\n",
         l->id, l->titulo, l->autor, l->ano, l->categoria);
}

// Placeholder: verificar se ID já existe (implementação futura)
int validar_id_unico(int id) {
  // Esta função será implementada posteriormente, retornando 1 se o ID for
  // único.
  return 1;
}
