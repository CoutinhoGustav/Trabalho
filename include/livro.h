/*
 * livro.h
 * ------
 * Declarações relacionadas ao tipo Livro e às funções de manipulação.
 * Este módulo contém a definição da estrutura que representa um livro
 * e protótipos auxiliares, como impressão e validação de IDs.
 */
// include/livro.h
#ifndef LIVRO_H
#define LIVRO_H

#include "utils.h"

// Definição da estrutura Livro
/*
 * Estrutura que modela um livro da biblioteca.
 * Campos: id, título, autor, ano e categoria.
 */
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    char categoria[50];
} Livro;

// Funções de manipulação de Livro (esqueleto)
/* Imprime na tela todos os campos de um livro */
void imprimir_livro(const Livro *l);
/* Verifica se o ID informado já está presente no vetor (implementado no futuro) */
int validar_id_unico(int id);
void imprimir_cabecalho(void);

#endif // LIVRO_H
