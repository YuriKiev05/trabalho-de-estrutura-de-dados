#ifndef LISTA_STATIC_H
#define LISTA_STATIC_H

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para a função strcpy

#define MAX_FUNCIONARIOS 100 // Tamanho máximo da lista estática

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int tamanho;
} ListaEstatica;

typedef struct node {
    Funcionario dado;
    struct node *proximo;
} Node;


// Funções para a Lista Estática

void inicializaListaEstatica(ListaEstatica *lista) {
    lista->tamanho = 0;
}

int listaEstaticaCheia(ListaEstatica *lista) {
    return lista->tamanho == MAX_FUNCIONARIOS;
}

int insereFuncionarioEstatica(ListaEstatica *lista, Funcionario funcionario) {
    if (listaEstaticaCheia(lista)) {
        return 0; // Inserção falhou
    }
    lista->funcionarios[lista->tamanho] = funcionario;
    lista->tamanho++;
    return 1; // Inserção bem-sucedida
}


// ... outras funções para a lista estática (remover, buscar, listar)

Funcionario buscaFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            return lista->funcionarios[i];
        }
    }
    // Funcionário não encontrado
    Funcionario funcionarioNaoEncontrado;
    // Inicializar os campos da estrutura com valores padrão ou inválidos
    return funcionarioNaoEncontrado;
}

int removeFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    int i, j;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            // Encontramos o funcionário a ser removido
            for (j = i; j < lista->tamanho - 1; j++) {
                // Deslocamos todos os elementos após o elemento removido para a esquerda
                lista->funcionarios[j] = lista->funcionarios[j + 1];
            }
            lista->tamanho--;
            return 1; // Remoção bem-sucedida
        }
    }

    return 0; // Funcionário não encontrado
}


void listarFuncionariosEstatica(ListaEstatica *lista) {
    printf("Funcionários na lista estática:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Nome: %s\n", lista->funcionarios[i].nome);
        printf("Matrícula: %d\n", lista->funcionarios[i].matricula);
        printf("Salário: %.2f\n\n", lista->funcionarios[i].salario);
    }
}

void salvarListaEstatica(ListaEstatica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve o cabeçalho do arquivo (opcional)
    fprintf(arquivo, "Nome,Matricula,Salario\n");

    for (int i = 0; i < lista->tamanho; i++) {
        fprintf(arquivo, "%s,%d,%.2f\n",
                lista->funcionarios[i].nome,
                lista->funcionarios[i].matricula,
                lista->funcionarios[i].salario);
    }

    fclose(arquivo);
    printf("Lista salva com sucesso em %s\n", nomeArquivo);
}


void carregarListaEstatica(ListaEstatica *lista, const char *nomeArquivo) {
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
        if (listaEstaticaCheia(lista)) {
            printf("Lista estática cheia!\n");
            break;
        }
        insereFuncionarioEstatica(lista, funcionario);
    }

    fclose(arquivo);
    printf("Lista carregada com sucesso!\n");
}
#endif
