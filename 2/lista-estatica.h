#ifndef LISTA_STATIC_H
#define LISTA_STATIC_H

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para a fun��o strcpy

#define MAX_FUNCIONARIOS 100 // Tamanho m�ximo da lista est�tica

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int tamanho;
} ListaEstatica;

typedef struct node {
    Funcionario dado;
    struct node *proximo;
} Node;


// Fun��es para a Lista Est�tica

void inicializaListaEstatica(ListaEstatica *lista) {
    lista->tamanho = 0;
}

int listaEstaticaCheia(ListaEstatica *lista) {
    return lista->tamanho == MAX_FUNCIONARIOS;
}

int insereFuncionarioEstatica(ListaEstatica *lista, Funcionario funcionario) {
    if (listaEstaticaCheia(lista)) {
        return 0; // Inser��o falhou
    }
    lista->funcionarios[lista->tamanho] = funcionario;
    lista->tamanho++;
    return 1; // Inser��o bem-sucedida
}


// ... outras fun��es para a lista est�tica (remover, buscar, listar)

Funcionario buscaFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            return lista->funcionarios[i];
        }
    }
    // Funcion�rio n�o encontrado
    Funcionario funcionarioNaoEncontrado;
    // Inicializar os campos da estrutura com valores padr�o ou inv�lidos
    return funcionarioNaoEncontrado;
}

int removeFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    int i, j;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            // Encontramos o funcion�rio a ser removido
            for (j = i; j < lista->tamanho - 1; j++) {
                // Deslocamos todos os elementos ap�s o elemento removido para a esquerda
                lista->funcionarios[j] = lista->funcionarios[j + 1];
            }
            lista->tamanho--;
            return 1; // Remo��o bem-sucedida
        }
    }

    return 0; // Funcion�rio n�o encontrado
}


void listarFuncionariosEstatica(ListaEstatica *lista) {
    printf("Funcion�rios na lista est�tica:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Nome: %s\n", lista->funcionarios[i].nome);
        printf("Matr�cula: %d\n", lista->funcionarios[i].matricula);
        printf("Sal�rio: %.2f\n\n", lista->funcionarios[i].salario);
    }
}

void salvarListaEstatica(ListaEstatica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve o cabe�alho do arquivo (opcional)
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

    // Pula a linha do cabe�alho (se houver)
    char linha[100];
    fgets(linha, 100, arquivo);

    while (fgets(linha, 100, arquivo) != NULL) {
        Funcionario funcionario;
        // Assume que os campos est�o separados por v�rgulas
        sscanf(linha, "%[^,],%d,%f", funcionario.nome, &funcionario.matricula, &funcionario.salario);
        if (listaEstaticaCheia(lista)) {
            printf("Lista est�tica cheia!\n");
            break;
        }
        insereFuncionarioEstatica(lista, funcionario);
    }

    fclose(arquivo);
    printf("Lista carregada com sucesso!\n");
}
#endif
