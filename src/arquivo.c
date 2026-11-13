// src/arquivo.c
#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Salva os livros em formato texto: um livro por linha, campos separados por '|'
int salvar_dados_texto(const VetorLivros *v, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        perror("Erro ao abrir arquivo para escrita");
        return 0;
    }
    for (int i = 0; i < v->tamanho; ++i) {
        const Livro *l = &v->dados[i];
        fprintf(fp, "%d|%s|%s|%d|%s\n", l->id, l->titulo, l->autor, l->ano, l->categoria);
    }
    fclose(fp);
    return 1;
}

// Carrega livros a partir de arquivo texto. Se o vetor ainda não foi inicializado, assume já inicializado.
int carregar_dados_texto(VetorLivros *v, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (!fp) {
        // arquivo pode não existir ainda, não é erro fatal
        return 0;
    }
    char linha[512];
    while (fgets(linha, sizeof(linha), fp)) {
        Livro l;
        // Remove '\n'
        linha[strcspn(linha, "\n")] = '\0';
        // parse usando strtok
        char *token = strtok(linha, "|");
        if (!token) continue;
        l.id = atoi(token);
        token = strtok(NULL, "|");
        if (!token) continue;
        strncpy(l.titulo, token, sizeof(l.titulo) - 1);
        l.titulo[sizeof(l.titulo) - 1] = '\0';
        token = strtok(NULL, "|");
        if (!token) continue;
        strncpy(l.autor, token, sizeof(l.autor) - 1);
        l.autor[sizeof(l.autor) - 1] = '\0';
        token = strtok(NULL, "|");
        if (!token) continue;
        l.ano = atoi(token);
        token = strtok(NULL, "|");
        if (!token) continue;
        strncpy(l.categoria, token, sizeof(l.categoria) - 1);
        l.categoria[sizeof(l.categoria) - 1] = '\0';
        vetor_adicionar(v, &l);
    }
    fclose(fp);
    return 1;
}
