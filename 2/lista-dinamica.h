#ifndef LISTA_DINAMIC_H
#define LISTA_DINAMIC_H

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para a fun��o strcpy


typedef struct no {
    Funcionario dado;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} ListaDinamica;

// Fun��es para a Lista Din�mica

void inicializaListaDinamica(ListaDinamica *lista) {
    lista->inicio = NULL;
}

No* alocaNo(Funcionario funcionario) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        // Tratamento de erro: mem�ria insuficiente
        return NULL;
    }
    novoNo->dado = funcionario;
    novoNo->proximo = NULL;
    return novoNo;
}

int insereFuncionarioDinamica(ListaDinamica *lista, Funcionario funcionario) {
    No *novoNo = alocaNo(funcionario);
    if (novoNo == NULL) {
        return 0; // Inser��o falhou
    }
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
    return 1; // Inser��o bem-sucedida
}

Funcionario buscaFuncionarioDinamica(ListaDinamica *lista, int matricula) {
    No *aux = lista->inicio;

    while (aux != NULL) {
        if (aux->dado.matricula == matricula) {
            return aux->dado; // Retorna o funcion�rio encontrado
        }
        aux = aux->proximo;
    }

    // Funcion�rio n�o encontrado
    Funcionario funcionarioNaoEncontrado;
    // Inicializar os campos da estrutura com valores padr�o ou inv�lidos
    return funcionarioNaoEncontrado;
}

int removeFuncionarioDinamica(ListaDinamica *lista, int matricula) {
    No *aux = lista->inicio, *anterior = NULL;

    while (aux != NULL) {
        if (aux->dado.matricula == matricula) {
            // Encontramos o funcion�rio a ser removido
            if (anterior == NULL) {
                // Se o n� a ser removido � o primeiro, atualizamos o in�cio da lista
                lista->inicio = aux->proximo;
            } else {
                // Caso contr�rio, ligamos o n� anterior ao pr�ximo do n� a ser removido
                anterior->proximo = aux->proximo;
            }
            free(aux);
            return 1; // Remo��o bem-sucedida
        }
        anterior = aux;
        aux = aux->proximo;
    }

    return 0; // Funcion�rio n�o encontrado
}

void listarFuncionariosDinamica(ListaDinamica *lista) {
    printf("Funcion�rios na lista din�mica:\n");
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->dado.nome);
        printf("Matr�cula: %d\n", aux->dado.matricula);
        printf("Sal�rio: %.2f\n\n", aux->dado.salario);
        aux = aux->proximo;
    }
}


void salvarListaDinamica(ListaDinamica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve o cabe�alho do arquivo (opcional)
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

    // Pula a linha do cabe�alho (se houver)
    char linha[100];
    fgets(linha, 100, arquivo);

    while (fgets(linha, 100, arquivo) != NULL) {
        Funcionario funcionario;
        // Assume que os campos est�o separados por v�rgulas
        sscanf(linha, "%[^,],%d,%f", funcionario.nome, &funcionario.matricula, &funcionario.salario);

        // Cria um novo n� e insere no in�cio da lista
        No *novoNo = (No*) malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("Erro ao alocar mem�ria!\n");
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
