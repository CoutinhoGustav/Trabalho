/*
 * vetor.h
 * ------
 * Interface do módulo responsável por gerenciar o vetor dinâmico de
 * objetos do tipo Livro. Ele abstrai a alocação, redimensionamento,
 * inserção, remoção e ordenação dos livros.
 */
// include/vetor.h
#ifndef VETOR_H
#define VETOR_H

#include "livro.h"

/*
 * Estrutura que representa o vetor dinâmico de livros.
 * 'dados' aponta para o array alocado dinamicamente.
 * 'tamanho' indica quantos livros estão atualmente armazenados.
 * 'capacidade' indica o número máximo de livros que podem ser
 *   armazenados antes de redimensionar.
 */
// Estrutura do vetor dinâmico de livros
typedef struct {
    Livro *dados; // ponteiro para array de livros
    int tamanho; // número de elementos atuais
    int capacidade; // capacidade alocada
} VetorLivros;

/* Funções públicas do módulo vetor */
// Funções para manipular o vetor
/* Inicializa o vetor com capacidade inicial e tamanho zero */
void vetor_inicializar(VetorLivros *v);
/* Libera a memória alocada pelo vetor */
void vetor_destruir(VetorLivros *v);
/* Adiciona um Livro ao vetor; redimensiona se necessário */
int vetor_adicionar(VetorLivros *v, const Livro *l);
/* Remove o Livro com o ID especificado e reorganiza o vetor */
int vetor_remover_por_id(VetorLivros *v, int id);
/* Ordena o vetor de livros por título (ordem alfabética) */
void vetor_ordenar_por_titulo(VetorLivros *v);
/* Ordena o vetor de livros por ano (crescente) */
void vetor_ordenar_por_ano(VetorLivros *v);

#endif // VETOR_H
