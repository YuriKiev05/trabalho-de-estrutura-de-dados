#ifndef LISTA_DINAMIC_H
#define LISTA_DINAMIC_H

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para a função strcpy


typedef struct no {
    Funcionario dado;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} ListaDinamica;

// Funções para a Lista Dinâmica

void inicializaListaDinamica(ListaDinamica *lista) {
    lista->inicio = NULL;
}

No* alocaNo(Funcionario funcionario) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        // Tratamento de erro: memória insuficiente
        return NULL;
    }
    novoNo->dado = funcionario;
    novoNo->proximo = NULL;
    return novoNo;
}

int insereFuncionarioDinamica(ListaDinamica *lista, Funcionario funcionario) {
    No *novoNo = alocaNo(funcionario);
    if (novoNo == NULL) {
        return 0; // Inserção falhou
    }
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
    return 1; // Inserção bem-sucedida
}

Funcionario buscaFuncionarioDinamica(ListaDinamica *lista, int matricula) {
    No *aux = lista->inicio;

    while (aux != NULL) {
        if (aux->dado.matricula == matricula) {
            return aux->dado; // Retorna o funcionário encontrado
        }
        aux = aux->proximo;
    }

    // Funcionário não encontrado
    Funcionario funcionarioNaoEncontrado;
    // Inicializar os campos da estrutura com valores padrão ou inválidos
    return funcionarioNaoEncontrado;
}

int removeFuncionarioDinamica(ListaDinamica *lista, int matricula) {
    No *aux = lista->inicio, *anterior = NULL;

    while (aux != NULL) {
        if (aux->dado.matricula == matricula) {
            // Encontramos o funcionário a ser removido
            if (anterior == NULL) {
                // Se o nó a ser removido é o primeiro, atualizamos o início da lista
                lista->inicio = aux->proximo;
            } else {
                // Caso contrário, ligamos o nó anterior ao próximo do nó a ser removido
                anterior->proximo = aux->proximo;
            }
            free(aux);
            return 1; // Remoção bem-sucedida
        }
        anterior = aux;
        aux = aux->proximo;
    }

    return 0; // Funcionário não encontrado
}

void listarFuncionariosDinamica(ListaDinamica *lista) {
    printf("Funcionários na lista dinâmica:\n");
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->dado.nome);
        printf("Matrícula: %d\n", aux->dado.matricula);
        printf("Salário: %.2f\n\n", aux->dado.salario);
        aux = aux->proximo;
    }
}


void salvarListaDinamica(ListaDinamica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve o cabeçalho do arquivo (opcional)
    fprintf(arquivo, "Nome,Matricula,Salario\n");

    No *aux = lista->inicio;
    while (aux != NULL) {
        fprintf(arquivo, "%s,%d,%.2f\n",
                aux->dado.nome,
                aux->dado.matricula,
                aux->dado.salario);
        aux = aux->proximo;
    }

    fclose(arquivo);
    printf("Lista salva com sucesso em %s\n", nomeArquivo);
}


void carregarListaDinamica(ListaDinamica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Pula a linha do cabeçalho (se houver)
    char linha[100];
    fgets(linha, 100, arquivo);

    while (fgets(linha, 100, arquivo) != NULL) {
        Funcionario funcionario;
        // Assume que os campos estão separados por vírgulas
        sscanf(linha, "%[^,],%d,%f", funcionario.nome, &funcionario.matricula, &funcionario.salario);

        // Cria um novo nó e insere no início da lista
        No *novoNo = (No*) malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("Erro ao alocar memória!\n");
            fclose(arquivo);
            return;
        }
        novoNo->dado = funcionario;
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    }

    fclose(arquivo);
    printf("Lista carregada com sucesso!\n");
}
#endif