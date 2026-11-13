// src/vetor.c
#include "vetor.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VETOR_CAPACIDADE_INICIAL 10

void vetor_inicializar(VetorLivros *v) {
    v->dados = (Livro *)malloc(VETOR_CAPACIDADE_INICIAL * sizeof(Livro));
    if (!v->dados) {
        fprintf(stderr, "Erro ao alocar memória para o vetor de livros.\n");
        exit(EXIT_FAILURE);
    }
    v->tamanho = 0;
    v->capacidade = VETOR_CAPACIDADE_INICIAL;
}

void vetor_destruir(VetorLivros *v) {
    if (v->dados) {
        free(v->dados);
        v->dados = NULL;
    }
    v->tamanho = 0;
    v->capacidade = 0;
}

static int vetor_redimensionar(VetorLivros *v) {
    int nova_capacidade = v->capacidade * 2;
    Livro *novo = (Livro *)realloc(v->dados, nova_capacidade * sizeof(Livro));
    if (!novo) {
        fprintf(stderr, "Erro ao realocar memória para o vetor de livros.\n");
        return 0;
    }
    v->dados = novo;
    v->capacidade = nova_capacidade;
    return 1;
}

int vetor_adicionar(VetorLivros *v, const Livro *l) {
    if (v->tamanho >= v->capacidade) {
        if (!vetor_redimensionar(v)) {
            return 0; // falha
        }
    }
    v->dados[v->tamanho] = *l; // cópia direta
    v->tamanho++;
    return 1; // sucesso
}

int vetor_remover_por_id(VetorLivros *v, int id) {
    int indice = -1;
    for (int i = 0; i < v->tamanho; ++i) {
        if (v->dados[i].id == id) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        return 0; // não encontrado
    }
    // mover os elementos seguintes para fechar o espaço
    for (int i = indice; i < v->tamanho - 1; ++i) {
        v->dados[i] = v->dados[i + 1];
    }
    v->tamanho--;
    return 1; // sucesso
}

static int comp_por_titulo(const void *a, const void *b) {
    const Livro *la = (const Livro *)a;
    const Livro *lb = (const Livro *)b;
    return strcmp(la->titulo, lb->titulo);
}

static int comp_por_ano(const void *a, const void *b) {
    const Livro *la = (const Livro *)a;
    const Livro *lb = (const Livro *)b;
    return (la->ano - lb->ano);
}

void vetor_ordenar_por_titulo(VetorLivros *v) {
    qsort(v->dados, v->tamanho, sizeof(Livro), comp_por_titulo);
}

void vetor_ordenar_por_ano(VetorLivros *v) {
    qsort(v->dados, v->tamanho, sizeof(Livro), comp_por_ano);
}
