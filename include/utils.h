/*
 * utils.h
 * ---------
 * Declarações de funções auxiliares usadas em todo o projeto,
 * como limpeza de buffer, pausa para o usuário e leitura de
 * linhas contendo espaços. Essas utilidades facilitam a interação
 * via console e evitam código duplicado.
 */
// utils.h - funções auxiliares
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

/*
 * clear_input_buffer()
 * --------------------
 * Remove caracteres pendentes no stdin (usado após fgets ou getchar)
 */
void clear_input_buffer(void);

void press_any_key_to_continue(void);

void read_line(char *buffer, int size);

#endif // UTILS_H
