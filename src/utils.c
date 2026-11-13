/*
 * utils.c
 * Implementação das funções auxiliares declaradas em utils.h.
 * Elas fornecem suporte básico para entrada/saída no console.
 */
// utils.c -
#include "utils.h"
#include <stdio.h>
#include <string.h>

void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void press_any_key_to_continue(void) {
  printf("\nPressione Enter para continuar...");
  getchar();
}

void read_line(char *buffer, int size) {
  if (fgets(buffer, size, stdin) != NULL) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    } else {
      // discard remaining characters
      clear_input_buffer();
    }
  }
}
