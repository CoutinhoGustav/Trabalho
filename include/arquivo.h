// include/arquivo.h
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "vetor.h"

// Funções para salvar e carregar dados
int salvar_dados_texto(const VetorLivros *v, const char *nome_arquivo);
int carregar_dados_texto(VetorLivros *v, const char *nome_arquivo);

#endif // ARQUIVO_H
